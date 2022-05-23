#include "rpcprovider.h"
#include <functional>
#include "rpcapplication.h"
#include "rpcheader.pb.h"
#include "rpccontroller.h"
#include "logger.h"

RpcProvider *RpcProvider::GetInstance()
{
    static EventLoop loop;
    static InetAddress addr(RpcApplication::GetInstance().GetConfig().Load("rpcserver_ip"), 
        std::stoi(RpcApplication::GetInstance().GetConfig().Load("rpcserver_port")));
    static RpcProvider rpcProvider(&loop, addr, "RpcProvider");
    return &rpcProvider;
}

RpcProvider::RpcProvider(EventLoop *loop, const InetAddress &addr, const std::string& name)
    : m_eventLoop(loop), m_server(loop, addr, name)
{
    // 绑定连接回调和消息读写回调方法，分离了网络代码和业务代码
    m_server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    m_server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置muduo库的线程数量
    m_server.setThreadNum(8);

    // 启动zkclient客户端
    m_zkCli.Start();
    // 加入根节点
    m_zkCli.Create(ROOT_PATH, nullptr, 0);

    // TODO: zk心跳机制
    // TODO: SIGINT信号注册
}

/*
serviceName -> service描述 -> service*记录服务对象，methodName -> method方法对象
*/
// 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
void RpcProvider::NotifyService(Service *service)
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

    std::string ip = RpcApplication::GetInstance().GetConfig().Load("rpcserver_ip");
    uint16_t port = std::stoi(RpcApplication::GetInstance().GetConfig().Load("rpcserver_port"));

    // znode路径：/my-simple-rpc/UserServiceRpc/Login/127.0.0.1:8000
    std::string servicePath = ROOT_PATH;
    servicePath += "/" + serviceName;
    m_zkCli.Create(servicePath.c_str(), nullptr, 0);
    for (int i = 0; i < methodCnt; ++i) {
        // 获取了服务对象指定下标的服务方法的描述（抽象描述）
        const MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string methodName = pmethodDesc->name();
        serviceInfo.m_methodMap.insert({methodName, pmethodDesc});

        LOG_DEBUG("methodName: %s", methodName.c_str());

        // 加入znode子节点
        std::string methodPath = servicePath + "/" + methodName;
        m_zkCli.Create(methodPath.c_str(), nullptr, 0);
        char address[128] = {0};
        sprintf(address, "%s:%d", ip.c_str(), port);
        methodPath += "/";
        methodPath += address;
        m_zkCli.Create(methodPath.c_str(), nullptr, 0, ZOO_EPHEMERAL);
        m_pathSet.insert(methodPath);
    }
    serviceInfo.m_service = service;
    m_serviceMap.insert({serviceName, serviceInfo});

    LOG_INFO("In RpcProvider: Notify Service success!");
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = RpcApplication::GetInstance().GetConfig().Load("rpcserver_ip");
    uint16_t port = std::stoi(RpcApplication::GetInstance().GetConfig().Load("rpcserver_port"));
    
    // rpc服务端准备启动，打印信息
    std::cout << "RpcProvider start service at ip: " << ip << " port: " << port << std::endl;
    LOG_INFO("RpcProvider start service at ip: %s port: %d", ip.c_str(), port);

    // 启动网络服务
    m_server.start();
    m_eventLoop->loop();
}

// 新的socket连接回调
void RpcProvider::OnConnection(const TcpConnectionPtr &conn)
{
    // rpc请求和http一样，都是短连接请求，服务端返回rpc响应之后就会主动关闭连接
    if (!conn->connected()) {
        // 和rpc client的连接断开了
        conn->shutdown();
    }
}

/*
在框架内部，RpcPrivider和RpcConsumer要协商好通信用的protobuf数据类型
协议头部应该包含这三部分：serviceName methodName args
定义proto的message类型，进行数据的序列化和反序列化
为了防止TCP粘包问题，还需要记录头部的长度，参数的长度
*/
// 已建立连接用户的读写事件回调
// 如果远程有一个rpc服务的调用请求，那么OnMessage方法将会响应
void RpcProvider::OnMessage(const TcpConnectionPtr &conn, Buffer *buffer, Timestamp)
{
    LOG_INFO("In RpcProvider: get a rpc request!");
    // 网络上接收的远程rpc调用请求的字符流
    std::string recvBuf = buffer->retrieveAllAsString();

    // 从字符流中读取前4个字节的内容
    uint32_t headerSize = 0;
    recvBuf.copy((char*)&headerSize, 4, 0);

    // 根据headerSize读取数据头的原始字符流，反序列化数据，得到rpc请求的详细信息
    std::string rpcHeaderStr = recvBuf.substr(4, headerSize);
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
        LOG_ERROR("In RpcProvider: rpcHeaderStr: %s parse error!", rpcHeaderStr.c_str());
        conn->shutdown();
        return;
    }

    // 获取rpc方法参数的字符流数据
    std::string argsStr = recvBuf.substr(4 + headerSize, argsSize);

    // 打印调试信息
    LOG_DEBUG("In %s:%s:%d: ", __FILE__, __FUNCTION__, __LINE__);
    LOG_DEBUG("headerSize: %d", headerSize);
    LOG_DEBUG("rpcHeaderStr: %s", rpcHeaderStr.c_str());
    LOG_DEBUG("serviceName: %s", serviceName.c_str());
    LOG_DEBUG("methodName: %s", methodName.c_str());
    LOG_DEBUG("argsSize: %d", argsSize);
    LOG_DEBUG("argsStr: %s", argsStr.c_str());

    // 获取service对象和method对象
    auto it = m_serviceMap.find(serviceName);
    if (it == m_serviceMap.end()) {
        LOG_ERROR("In RpcProvider: %s is not exist!", serviceName.c_str());
        conn->shutdown();
        return;
    }

    auto mit = it->second.m_methodMap.find(methodName);
    if (mit == it->second.m_methodMap.end()) {
        LOG_ERROR("In RpcProvider: %s::%s is not exist!", serviceName.c_str(), methodName.c_str());
        conn->shutdown();
        return;
    }

    Service *service = it->second.m_service; // 获取service对象
    const MethodDescriptor *method = mit->second; // 获取method对象

    // 生成rpc方法调用的请求request和响应response参数
    Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(argsStr)) {
        LOG_ERROR("In RpcProvider: request parse error! content: %s", argsStr.c_str());
        conn->shutdown();
        return;
    }
    Message *response = service->GetResponsePrototype(method).New();

    // 给下面的method方法的调用，绑定一个Closure的回调函数
    Closure *done = google::protobuf::NewCallback<RpcProvider, const TcpConnectionPtr&, Message*>(this, &RpcProvider::SendRpcResponse, conn, response);

    // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
    LOG_INFO("In RpcProvider: rpc request parse success, ready to call local method!");
    RpcController controller;
    service->CallMethod(method, &controller, request, response, done);
}

// Closure回调操作，用于序列化rpc响应和网络发送
void RpcProvider::SendRpcResponse(const TcpConnectionPtr &conn, Message *response)
{
    std::string responseStr;
    if (response->SerializeToString(&responseStr))  { // 对response进行序列化
        // 序列化成功后，通过网络把rpc方法执行的结果发送回rpc调用方
        conn->send(responseStr);
    }
    else {
        LOG_ERROR("In RpcProvider: serialize responseStr error!");
    }
    LOG_INFO("In RpcProvider: rpc response finish!");
    conn->shutdown(); // 模拟http的短连接服务，由RpcProvider主动断开连接，以给其他更多rpc调用方提供服务
}

// 删除注册的znode节点
void RpcProvider::Clear()
{
    m_zkCli.Stop();
}