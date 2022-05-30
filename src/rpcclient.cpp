#include "rpcclient.h"
#include "rpcheader.pb.h"
#include "rpcconfig.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include "logger.h"
#include "loadbalance.h"
#include <future>
#include <thread>

int RpcClient::taskid = 0;

RpcClient::RpcClient() : m_running(true)
{
    Logger::getInstance()->start();
    m_zkCli.closeLog();
    m_zkCli.start();
    startThread();
}

RpcClient::~RpcClient()
{
    m_zkCli.stop();
    Logger::getInstance()->stop();
    m_running = false;
}

void RpcClient::startThread()
{
    std::thread requestTask([&]() {
        while (m_running) {
            if (!m_requestQueue.empty()) {
                Request request = m_requestQueue.pop();
                // TODO: 这里直接使用阻塞调用了，需要优化
                syncCall(request.ip, request.port, request.sendRpcStr, request.response, request.context);
                m_responseQueue.push(Response(request.currTask, request.response, request.context));
            }
        }
    });
    requestTask.detach();

    std::thread responseTask([&]() {
        while (m_running) {
            if (!m_responseQueue.empty()) {
                Response response = m_responseQueue.pop();
                std::lock_guard<std::mutex> lock(_connMutex);
                auto it = m_callbackMap.find(response.currTask);
                if (it != m_callbackMap.end()) {
                    it->second->Run();
                    if (response.context) {
                        response.context->complete();
                    }
                    m_callbackMap.erase(it);
                }
            }
        }
    });
    responseTask.detach();
}

std::pair<std::string, uint16_t> RpcClient::discoverService(RpcContext* context, const std::string &serviceName, const std::string &methodName, const std::string &argsStr)
{
    // 读取配置文件的rpcserver的信息
    // std::string ip = RpcConfig::getInstance()->load("rpcserver.ip");
    // uint16_t port = std::stoi(RpcConfig::getInstance()->load("rpcserver.port"));

    // rpc调用方想调用service_name的method_name服务，需要查询zk上该服务所在的host信息
    // /my-simple-rpc/UserServiceRpc/Login
    std::pair<std::string, uint16_t> result = {"", 0};
    std::string methodPath = ROOT_PATH;
    methodPath += "/" + serviceName + "/" + methodName;
    // 127.0.0.1:8000
    std::vector<std::string> nodes = m_zkCli.getChildrenNodes(methodPath);
    if (nodes.empty()) {
        std::string errMsg = methodPath + " is not exist!";
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        return result;
    }

    LoadBalanceCategory category = LoadBalance::str2Strategy(RpcConfig::getInstance()->load("rpcclient.loadbalance"));
    std::string categoryStr = LoadBalance::strategy2Str(category);
    LOG_INFO("In RpcClient: Use load balance strategy: %s", categoryStr.c_str());

    LoadBalanceStrategy::ptr strategy = LoadBalance::queryStrategy(category);
    std::string hostData = strategy->select(nodes, serviceName + methodName + argsStr); // 负载均衡器的选择
    int idx = hostData.find(":");
    if (idx == -1) {
        std::string errMsg = methodPath + " address is invalid!";
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        return result;
    }
    std::string ip = hostData.substr(0, idx);
    uint16_t port = std::stoi(hostData.substr(idx + 1, hostData.size() - idx));
    result.first = ip;
    result.second = port;
    return result;
}

void RpcClient::syncCall(const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, RpcContext* context)
{
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    // 使用tcp编程，完成rpc方法远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1) {
        std::string errMsg = std::string("In RpcClient: create socket error: ") + strerror(errno);
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }

    // 连接rpc服务节点
    if (connect(clientfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::string errMsg = std::string("In RpcClient: connect error: ") + strerror(errno);
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }

    // 发送rpc请求
    if (send(clientfd, sendRpcStr.c_str(), sendRpcStr.size(), 0) == -1) {
        std::string errMsg = std::string("In RpcClient: send error: ") + strerror(errno);
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }

    // 接收rpc请求的返回值
    char recvBuf[1024] = {0};
    int recvSize = 0;
    if ((recvSize = recv(clientfd, recvBuf, sizeof(recvBuf), 0)) == -1) {
        std::string errMsg = std::string("In RpcClient: recv error: ") + strerror(errno);
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }
    else if (recvSize == 0) {
        std::string errMsg = "In RpcClient: recv error: rpc request content error!";
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }

    // 反序列化rpc调用的远程数据
    // std::string responseStr(recvBuf, 0, recvSize); // 出现问题，recvBuf遇到\0，后面的数据就存不下来了，导致反序列化失败
    // if (!response->ParseFromString(responseStr)) {
    if (!response->ParseFromArray(recvBuf, recvSize)) {
        std::string errMsg = std::string("In RpcClient: parse error! response str: ") + recvBuf;
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        close(clientfd);
        return;
    }

    LOG_INFO("In RpcClient: rpc request send success!");
    close(clientfd);
}

// 异步调用
void RpcClient::asyncCall(const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, google::protobuf::RpcController* controller)
{
    sendRpcCallBack = [&](const TcpConnectionPtr &conn) {
        conn->send(sendRpcStr);
    };
    connectFailedCallBack = [&](const TcpConnectionPtr &conn) {
        std::string errMsg = "In RpcClient: connect error";
        LOG_ERROR("%s", errMsg.c_str());
        if (controller)
            controller->SetFailed(errMsg);
        conn->shutdown();
        m_eventLoop.quit();
    };
    recvFailedCallBack = [&](const TcpConnectionPtr &conn) {
        std::string errMsg = "In RpcClient: connect error";
        LOG_ERROR("%s", errMsg.c_str());
        if (controller)
            controller->SetFailed(errMsg);
        conn->shutdown();
        m_eventLoop.quit();
    };
    responseCallBack = [&](const TcpConnectionPtr &conn, const std::string &message) {
        if (!response->ParseFromArray(message.c_str(), message.size())) {
            std::string errMsg = std::string("In RpcClient: parse error! response str: ") + message;
            LOG_ERROR("%s", errMsg.c_str());
            if (controller)
                controller->SetFailed(errMsg);
            return;
        }
        LOG_INFO("In RpcClient: rpc request send success!");
        conn->shutdown();
        m_eventLoop.quit();
        // m_callback(response, controller);
    };
    TcpClient client(&m_eventLoop, InetAddress(ip, port), "");
    client.setConnectionCallback(std::bind(&RpcClient::onConnection, this, std::placeholders::_1));
    client.setMessageCallback(std::bind(&RpcClient::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    client.connect();
    m_eventLoop.loop();
}

// 连接回调，有连接事件发生时，该函数会调用
void RpcClient::onConnection(const TcpConnectionPtr &conn)
{
    if (!conn->connected()) {
        connectFailedCallBack(conn);
        return;
    }
    sendRpcCallBack(conn);
}

// 消息回调，接受到Rpcserver处理完成的response消息后调用
void RpcClient::onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp time)
{
    if (buf->readableBytes() == 0) {
        recvFailedCallBack(conn);
        return;
    }
    std::string message = buf->retrieveAllAsString();
    responseCallBack(conn, message);
}

// 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
void RpcClient::CallMethod(const MethodDescriptor* method,
                        google::protobuf::RpcController* controller, const Message* request,
                        Message* response, Closure* done)
{
    RpcContext *context = nullptr;
    if (controller) {
        controller->Reset();
        context = dynamic_cast<RpcContext*>(controller);
    }
    currTask = taskid++;
    LOG_INFO("In RpcClient: generating rpc request!");
    const ServiceDescriptor *sd = method->service();
    std::string serviceName = sd->name();
    std::string methodName = method->name();

    // 获取参数的序列化字符串长度 argsSize
    int argsSize = 0;
    std::string argsStr;
    if (request->SerializeToString(&argsStr)) {
        argsSize = argsStr.size();
    }
    else {
        std::string errMsg = "In RpcClient: serialize request error!";
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        if (done)
            done->Run();
        if (context)
            context->complete();
        return;
    }

    // 定义rpc的请求header
    mysimplerpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(serviceName);
    rpcHeader.set_method_name(methodName);
    rpcHeader.set_args_size(argsSize);

    uint32_t headerSize = 0;
    std::string rpcHeaderStr;
    if (rpcHeader.SerializeToString(&rpcHeaderStr)) {
        headerSize = rpcHeaderStr.size();
    }
    else {
        std::string errMsg = "In RpcClient: serialize rpc header error!";
        LOG_ERROR("%s", errMsg.c_str());
        if (context)
            context->SetFailed(errMsg);
        if (done)
            done->Run();
        if (context)
            context->complete();
        return;
    }

    // 组织待发送的rpc请求字符串
    std::string sendRpcStr;
    sendRpcStr.insert(0, std::string((char*)&headerSize, 4)); // headerSize
    sendRpcStr += rpcHeaderStr;
    sendRpcStr += argsStr;

    // 打印调试信息
    LOG_DEBUG("In %s:%s:%d: ", __FILE__, __FUNCTION__, __LINE__);
    LOG_DEBUG("headerSize: %d", headerSize);
    LOG_DEBUG("rpcHeaderStr: %s", rpcHeaderStr.c_str());
    LOG_DEBUG("serviceName: %s", serviceName.c_str());
    LOG_DEBUG("methodName: %s", methodName.c_str());
    LOG_DEBUG("argsSize: %d", argsSize);
    LOG_DEBUG("argsStr: %s", argsStr.c_str());

    LOG_INFO("In RpcClient: rpc request generated, ready to send!");

    // 服务发现
    auto discovered = discoverService(context, serviceName, methodName, argsStr);
    if (discovered.first.empty()) { // 表明服务发现出错
        if (done)
            done->Run();
        if (context)
            context->complete();
        return;
    }

    std::string ip = discovered.first;
    uint16_t port = discovered.second;
    LOG_INFO("Discovered server ip: %s, server port: %d", ip.c_str(), port);

    if (done == nullptr) {
        syncCall(ip, port, sendRpcStr, response, context);
    }
    else {
        // asyncCall(ip, port, sendRpcStr, response, controller);
        // std::future<void> result = std::async(std::bind(&RpcClient::syncCall, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5), ip, port, sendRpcStr, response, controller);
        // std::cout << "future" << std::endl;
        setCallback(done);
        m_requestQueue.push(Request(currTask, ip, port, sendRpcStr, response, context));
    }
}

void RpcClient::setCallback(Closure *done)
{
    std::lock_guard<std::mutex> lock(_connMutex);
    m_callbackMap.insert({currTask, done});
}