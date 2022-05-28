#ifndef RPCSERVER_H
#define RPCSERVER_H

#include <google/protobuf/service.h>
#include <string>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <unordered_map>
#include <unordered_set>
#include "zookeeperutil.h"
#include "noncopyable.h"

using Service = google::protobuf::Service;
using TcpServer = muduo::net::TcpServer;
using EventLoop = muduo::net::EventLoop;
using InetAddress = muduo::net::InetAddress;
using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
using Buffer = muduo::net::Buffer;
using Timestamp = muduo::Timestamp;
using ServiceDescriptor = google::protobuf::ServiceDescriptor;
using MethodDescriptor = google::protobuf::MethodDescriptor;
using Message = google::protobuf::Message;
using Closure = google::protobuf::Closure;

// 框架提供的专门负责发布rpc服务的网络对象类
// 需要支持高并发（可能有很多人请求rpc调用），因此需要使用muduo库实现
class RpcServer : private Noncopyable {
public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void registerService(Service *service);

    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void start();

    static RpcServer *getInstance();
private:
    RpcServer(EventLoop *loop, const InetAddress &addr, const std::string& name);

    ~RpcServer();

    // 组合了EventLoop
    EventLoop *m_eventLoop;

    // 创建TcpServer对象
    TcpServer m_server;

    // service服务类型信息
    struct ServiceInfo {
        Service *m_service; // 保存服务对象
        std::unordered_map<std::string, const MethodDescriptor*> m_methodMap; // 保存服务方法
    };

    // 存储注册成功的服务对象和其服务方法的所有信息
    std::unordered_map<std::string, ServiceInfo> m_serviceMap;

    // 存储注册过的路径
    std::unordered_set<std::string> m_pathSet;

    ZkClient m_zkCli;

    // 新的socket连接回调
    void onConnection(const TcpConnectionPtr &);

    // 已建立连接用户的读写事件回调
    void onMessage(const TcpConnectionPtr&, Buffer *, Timestamp);

    // Closure回调操作，用于序列化rpc响应和网络发送
    void sendRpcResponse(const TcpConnectionPtr&, Message *);

    // 删除注册的znode节点
    void clear();

    // SIGINT信号处理函数
    static void sigHandler(int sig);
};

#endif