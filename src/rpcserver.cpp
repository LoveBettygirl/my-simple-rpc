#include "rpcserver.h"
#include <functional>
#include "rpcconfig.h"
#include "rpcheader.pb.h"
#include "rpccontext.h"
#include "logger.h"
#include <signal.h>

constexpr uint32_t RpcServer::MAGIC_NUM;

void addsig(int sig, void (*handler)(int))
{
    struct sigaction sa; // 这里必须加struct，要不然和函数名字冲突了
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigfillset(&sa.sa_mask);
    sigaction(sig, &sa, nullptr);
}

void RpcServer::sigHandler(int sig)
{
    RpcServer::getInstance()->clear();
    exit(EXIT_SUCCESS);
}

RpcServer *RpcServer::getInstance()
{
    static EventLoop loop;
    static InetAddress addr(RpcConfig::getInstance()->load("rpcserver.ip"), 
        std::stoi(RpcConfig::getInstance()->load("rpcserver.port")));
    static RpcServer rpcServer(&loop, addr, "RpcServer");
    return &rpcServer;
}

RpcServer::RpcServer(EventLoop *loop, const InetAddress &addr, const std::string& name)
    : m_eventLoop(loop), m_server(loop, addr, name)
{
    // 绑定连接回调和消息读写回调方法，分离了网络代码和业务代码
    m_server.setConnectionCallback(std::bind(&RpcServer::onConnection, this, std::placeholders::_1));
    m_server.setMessageCallback(std::bind(&RpcServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置muduo库的线程数量
    m_server.setThreadNum(8);

    // 启动zkclient客户端
    m_zkCli.start();
    // 加入根节点
    m_zkCli.create(ROOT_PATH, nullptr, 0);

    // zk心跳机制
    // m_zkCli.sendHeartBeat();

    // SIGINT信号注册
    addsig(SIGINT, sigHandler);
}

RpcServer::~RpcServer()
{
    clear();
}

/*
serviceName -> service描述 -> service*记录服务对象，methodName -> method方法对象
*/
// 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
void RpcServer::registerService(Service *service)
{
    ServiceInfo serviceInfo;
    // 获取了服务对象的描述信息
    const ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    // 获取服务名
    std::string serviceName = pserviceDesc->name();
    // 获取服务对象service的方法的数量
    int methodCnt = pserviceDesc->method_count();

    LOG_DEBUG("In %s:%s:%d: ", __FILE__, __FUNCTION__, __LINE__);
    LOG_DEBUG("serviceName: %s", serviceName.c_str());

    std::string ip = RpcConfig::getInstance()->load("rpcserver.ip");
    uint16_t port = std::stoi(RpcConfig::getInstance()->load("rpcserver.port"));

    // znode路径：/my-simple-rpc/UserServiceRpc/Login/127.0.0.1:8000
    std::string servicePath = ROOT_PATH;
    servicePath += "/" + serviceName;
    m_zkCli.create(servicePath.c_str(), nullptr, 0);
    for (int i = 0; i < methodCnt; ++i) {
        // 获取了服务对象指定下标的服务方法的描述（抽象描述）
        const MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string methodName = pmethodDesc->name();
        serviceInfo.m_methodMap.insert({methodName, pmethodDesc});

        LOG_DEBUG("methodName: %s", methodName.c_str());

        // 加入znode子节点
        std::string methodPath = servicePath + "/" + methodName;
        m_zkCli.create(methodPath.c_str(), nullptr, 0);
        char address[128] = {0};
        sprintf(address, "%s:%d", ip.c_str(), port);
        methodPath += "/";
        methodPath += address;
        m_zkCli.create(methodPath.c_str(), nullptr, 0, ZOO_EPHEMERAL);
        m_pathSet.insert(methodPath);
    }
    serviceInfo.m_service = service;
    m_serviceMap.insert({serviceName, serviceInfo});

    LOG_INFO("In RpcServer: Register Service success!");
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcServer::start()
{
    std::string ip = RpcConfig::getInstance()->load("rpcserver.ip");
    uint16_t port = std::stoi(RpcConfig::getInstance()->load("rpcserver.port"));
    
    // rpc服务端准备启动，打印信息
    std::cout << "RpcServer start service at ip: " << ip << " port: " << port << std::endl;
    LOG_INFO("RpcServer start service at ip: %s port: %d", ip.c_str(), port);

    // 启动网络服务
    m_server.start();
    m_eventLoop->loop();
}

// 新的socket连接回调
void RpcServer::onConnection(const TcpConnectionPtr &conn)
{
    // rpc请求和http一样，都是短连接请求，服务端返回rpc响应之后就会主动关闭连接
    if (!conn->connected()) {
        // 和rpc client的连接断开了
        conn->shutdown();
    }
}

// recvBuf: 网络上接收的远程rpc调用请求的字符流
bool RpcServer::processRequest(const TcpConnectionPtr &conn, const std::string &recvBuf)
{
    uint32_t msgType = 0;
    int progress = sizeof(MAGIC_NUM) + sizeof(msgType); // 表示数据包处理的进度

    uint32_t contentSize = 0;
    recvBuf.copy((char*)&contentSize, sizeof(contentSize), progress);
    progress += sizeof(contentSize);

    uint64_t requestId = 0;
    recvBuf.copy((char*)&requestId, sizeof(requestId), progress);
    LOG_INFO("In RpcServer: get a rpc request, request id: %lx!", requestId);
    progress += sizeof(requestId);

    uint32_t rpcHeaderStrSize = 0;
    recvBuf.copy((char*)&rpcHeaderStrSize, sizeof(rpcHeaderStrSize), progress);
    progress += sizeof(rpcHeaderStrSize);

    uint32_t restContentSize = contentSize - sizeof(requestId);

    // 根据headerSize读取数据头的原始字符流，反序列化数据，得到rpc请求的详细信息
    std::string rpcHeaderStr = recvBuf.substr(progress, rpcHeaderStrSize);
    mysimplerpc::RpcHeader rpcHeader;
    std::string serviceName, methodName;
    uint32_t argsSize;
    if (rpcHeader.ParseFromString(rpcHeaderStr)) {
        // 数据头反序列化成功
        serviceName = rpcHeader.service_name();
        methodName = rpcHeader.method_name();
        argsSize = rpcHeader.args_size();
    }
    else {
        // 数据头反序列化失败
        LOG_ERROR("In RpcServer: rpcHeaderStr: %s parse error!", rpcHeaderStr.c_str());
        return false;
    }
    progress += rpcHeaderStrSize;

    // 获取rpc方法参数的字符流数据
    std::string argsStr = recvBuf.substr(progress, argsSize);

    // 打印调试信息
    LOG_DEBUG("In %s:%s:%d: ", __FILE__, __FUNCTION__, __LINE__);
    LOG_DEBUG("msgType: %d", msgType);
    LOG_DEBUG("contentSize: %d", contentSize);
    LOG_DEBUG("requestId: %lx", requestId);
    LOG_DEBUG("rpcHeaderStrSize: %d", rpcHeaderStrSize);
    LOG_DEBUG("rpcHeaderStr: %s", rpcHeaderStr.c_str());
    LOG_DEBUG("serviceName: %s", serviceName.c_str());
    LOG_DEBUG("methodName: %s", methodName.c_str());
    LOG_DEBUG("argsSize: %d", argsSize);
    LOG_DEBUG("argsStr: %s", argsStr.c_str());

    // 获取service对象和method对象
    auto it = m_serviceMap.find(serviceName);
    if (it == m_serviceMap.end()) {
        LOG_ERROR("In RpcServer: %s is not exist!", serviceName.c_str());
        return false;
    }

    auto mit = it->second.m_methodMap.find(methodName);
    if (mit == it->second.m_methodMap.end()) {
        LOG_ERROR("In RpcServer: %s::%s is not exist!", serviceName.c_str(), methodName.c_str());
        return false;
    }

    Service *service = it->second.m_service; // 获取service对象
    const MethodDescriptor *method = mit->second; // 获取method对象

    // 生成rpc方法调用的请求request和响应response参数
    Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(argsStr)) {
        LOG_ERROR("In RpcServer: request parse error! content: %s", argsStr.c_str());
        return false;
    }
    Message *response = service->GetResponsePrototype(method).New();

    // 测试：用sleep模拟服务端处理不过来的场景
    // std::this_thread::sleep_for(std::chrono::seconds(5));

    // 给下面的method方法的调用，绑定一个Closure的回调函数
    RpcServerContext context(conn);
    context.setRequestId(requestId);
    Closure *done = NewCallback(this, &RpcServer::sendRpcResponse, &context, response);

    // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
    LOG_INFO("In RpcServer: rpc request parse success, ready to call local method!");
    service->CallMethod(method, &context, request, response, done);
    return true;
}

/*
在框架内部，RpcPrivider和RpcConsumer要协商好通信用的protobuf数据类型
协议头部应该包含这三部分：serviceName methodName args
定义proto的message类型，进行数据的序列化和反序列化
为了防止TCP粘包问题，还需要记录头部的长度，参数的长度
*/
// 已建立连接用户的读写事件回调
// 如果远程有一个rpc服务的调用请求，那么OnMessage方法将会响应
void RpcServer::onMessage(const TcpConnectionPtr &conn, Buffer *buffer, Timestamp)
{
    // 要解决粘包问题
    uint32_t contentSize = 0, msgType = 0;
    if (buffer->readableBytes() < sizeof(MAGIC_NUM))
        return;

    uint32_t magic = 0;
    memcpy((char*)&magic, buffer->peek(), sizeof(MAGIC_NUM));
    if (magic != MAGIC_NUM) {
        LOG_ERROR("In RpcServer: %s!", "receive illegal packet");
        conn->shutdown();
        return;
    }

    if (buffer->readableBytes() < sizeof(MAGIC_NUM) + sizeof(msgType) + sizeof(contentSize))
        return;

    memcpy((char*)&contentSize, buffer->peek() + sizeof(MAGIC_NUM) + sizeof(msgType), sizeof(contentSize));

    int allSize = sizeof(MAGIC_NUM) + sizeof(msgType) + sizeof(contentSize) + contentSize;
    if (buffer->readableBytes() < allSize)
        return;

    memcpy((char*)&msgType, buffer->peek() + sizeof(MAGIC_NUM), sizeof(msgType));
    if (msgType != 0) {
        LOG_ERROR("In RpcServer: %s!", "not request package");
        conn->shutdown();
        return;
    }

    // 已经可以接收一个包了
    std::string recvBuf;
    recvBuf.append(buffer->peek(), allSize);
    buffer->retrieve(allSize);

    if (!processRequest(conn, recvBuf)) {
        conn->shutdown();
    }
}


// Closure回调操作，用于序列化rpc响应和网络发送
void RpcServer::sendRpcResponse(RpcServerContext *context, Message *response)
{
    const TcpConnectionPtr &conn = context->getConn();
    std::string responseStr;
    if (response->SerializeToString(&responseStr))  { // 对response进行序列化
        // 序列化成功后，通过网络把rpc方法执行的结果发送回rpc调用方
        uint64_t requestId = context->getRequestId();
        uint32_t msgType = 1, contentSize = sizeof(requestId) + responseStr.size();
        std::string allStr;
        allStr.append((char*)&MAGIC_NUM, sizeof(MAGIC_NUM));
        allStr.append((char*)&msgType, sizeof(msgType));
        allStr.append((char*)&contentSize, sizeof(contentSize));
        allStr.append((char*)&requestId, sizeof(requestId));
        allStr.append(responseStr);
        conn->send(allStr);
    }
    else {
        LOG_ERROR("In RpcServer: serialize responseStr error!");
    }
    LOG_INFO("In RpcServer: rpc response finish!");
    conn->shutdown(); // 模拟http的短连接服务，由RpcServer主动断开连接，以给其他更多rpc调用方提供服务
}

// 删除注册的znode节点，断开与zkserver连接
void RpcServer::clear()
{
    if (!m_zkCli.getIsConnected()) {
        return;
    }
    // 先删除自己注册的节点
    for (const std::string &path : m_pathSet) {
        m_zkCli.deleteNode(path.c_str());
    }
    // 也要删除节点上层表示服务和方法的节点，以及根节点（如果它们已经没有子节点了）
    for (auto &sp : m_serviceMap) {
        std::string servicePath = ROOT_PATH;
        servicePath += "/" + sp.first;
        for (auto &mp : sp.second.m_methodMap) {
            std::string methodPath = servicePath + "/" + mp.first;
            if (m_zkCli.getChildrenNodes(methodPath).empty()) {
                m_zkCli.deleteNode(methodPath.c_str());
            }
        }
        if (m_zkCli.getChildrenNodes(servicePath).empty()) {
            m_zkCli.deleteNode(servicePath.c_str());
        }
    }
    if (m_zkCli.getChildrenNodes(ROOT_PATH).empty()) {
        m_zkCli.deleteNode(ROOT_PATH);
    }
    // 断开与zkserver的连接
    m_zkCli.stop();
}