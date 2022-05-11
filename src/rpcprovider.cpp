#include "rpcprovider.h"
#include <string>
#include <functional>
#include "rpcapplication.h"

// 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
void RpcProvider::NotifyService(Service *service)
{

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

}

// 已建立连接用户的读写事件回调
void RpcProvider::OnMessage(const TcpConnectionPtr&, Buffer *, Timestamp)
{
    
}