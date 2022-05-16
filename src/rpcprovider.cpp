#include "rpcprovider.h"
#include <functional>
#include "rpcapplication.h"
#include "rpcheader.pb.h"
#include "rpccontroller.h"

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

    std::cout << "serviceName: " << serviceName << std::endl;

    for (int i = 0; i < methodCnt; ++i) {
        // 获取了服务对象指定下标的服务方法的描述（抽象描述）
        const MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string methodName = pmethodDesc->name();
        serviceInfo.m_methodMap.insert({methodName, pmethodDesc});

        std::cout << "methodName: " << methodName << std::endl;
    }
    serviceInfo.m_service = service;
    m_serviceMap.insert({serviceName, serviceInfo});
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = RpcApplication::GetInstance().GetConfig().Load("rpcserver_ip");
    uint16_t port = std::stoi(RpcApplication::GetInstance().GetConfig().Load("rpcserver_port"));
    InetAddress address(ip, port);

    // 创建TcpServer对象
    TcpServer server(&m_eventLoop, address, "RpcProvider");

    // 绑定连接回调和消息读写回调方法，分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置muduo库的线程数量
    server.setThreadNum(8);

    std::cout << "RpcProvider start service at ip: " << ip << " port: " << port << std::endl;

    // 启动网络服务
    server.start();
    m_eventLoop.loop();
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
        serviceName = rpcHeader.servicename();
        methodName = rpcHeader.methodname();
        argsSize = rpcHeader.argssize();
    }
    else {
        // 数据头反序列化失败
        std::cerr << "rpcHeaderStr: " << rpcHeaderStr << " parse error!" << std::endl;
        return;
    }

    // 获取rpc方法参数的字符流数据
    std::string argsStr = recvBuf.substr(4 + headerSize, argsSize);

    // 打印调试信息
    std::cout << "==================================================" << std::endl;
    std::cout << "headerSize: " << headerSize << std::endl;
    std::cout << "rpcHeaderStr: " << rpcHeaderStr << std::endl;
    std::cout << "serviceName: " << serviceName << std::endl;
    std::cout << "methodName: " << methodName << std::endl;
    std::cout << "argsSize: " << argsSize << std::endl;
    std::cout << "argsStr: " << argsStr << std::endl;
    std::cout << "==================================================" << std::endl;

    // 获取service对象和method对象
    auto it = m_serviceMap.find(serviceName);
    if (it == m_serviceMap.end()) {
        std::cerr << serviceName << " is not exist!" << std::endl;
        return;
    }

    auto mit = it->second.m_methodMap.find(methodName);
    if (mit == it->second.m_methodMap.end()) {
        std::cerr << serviceName << "::" << methodName << " is not exist!" << std::endl;
        return;
    }

    Service *service = it->second.m_service; // 获取service对象
    const MethodDescriptor *method = mit->second; // 获取method对象

    // 生成rpc方法调用的请求request和响应response参数
    Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(argsStr)) {
        std::cout << "request parse error! content: " << argsStr << std::endl;
        return;
    }
    Message *response = service->GetResponsePrototype(method).New();

    // 给下面的method方法的调用，绑定一个Closure的回调函数
    Closure *done = google::protobuf::NewCallback<RpcProvider, const TcpConnectionPtr&, Message*>(this, &RpcProvider::SendRpcResponse, conn, response);

    // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
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
        std::cerr << "serialize responseStr error!" << std::endl;
    }
    conn->shutdown(); // 模拟http的短连接服务，由RpcProvider主动断开连接，以给其他更多rpc调用方提供服务
}