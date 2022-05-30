#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <utility>
#include <functional>
#include <muduo/net/TcpClient.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include "zookeeperutil.h"
#include "lockqueue.h"
#include <mutex>
#include "rpccontext.h"

using MethodDescriptor = google::protobuf::MethodDescriptor;
using ServiceDescriptor = google::protobuf::ServiceDescriptor;
using Message = google::protobuf::Message;
using Closure = google::protobuf::Closure;
using EventLoop = muduo::net::EventLoop;
using InetAddress = muduo::net::InetAddress;
using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
using Buffer = muduo::net::Buffer;
using Timestamp = muduo::Timestamp;
using TcpClient = muduo::net::TcpClient;
using google::protobuf::NewCallback;

class RpcClient : public google::protobuf::RpcChannel {
public:
    RpcClient();
    ~RpcClient();
    // 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
    void CallMethod(const MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const Message* request,
                          Message* response, Closure* done);
    void setCallback(Closure *done);
private:
    ZkClient m_zkCli;
    TcpClient *m_client;
    std::function<void(const TcpConnectionPtr&)> sendRpcCallBack;
    std::function<void(const TcpConnectionPtr&)> connectFailedCallBack, recvFailedCallBack;
	std::function<void(const TcpConnectionPtr &, const std::string &)> responseCallBack;
    EventLoop m_eventLoop;

    std::unordered_map<int, Closure*> m_callbackMap;
    static int taskid; // 准备新分配的taskid
    int currTask = -1;
    bool m_running;
    std::mutex _connMutex;

    struct Request {
        int currTask;
        std::string ip;
        uint16_t port;
        std::string sendRpcStr;
        Message *response;
        RpcContext *context;
        Request(int task, const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, RpcContext* context):
            currTask(task), ip(ip), port(port), sendRpcStr(sendRpcStr), response(response), context(context) {}
    };

    struct Response {
        int currTask;
        Message *response;
        RpcContext *context;
        Response(int task, Message* response, RpcContext* context):
            currTask(task), response(response), context(context) {}
    };

    LockQueue<Request> m_requestQueue;
    LockQueue<Response> m_responseQueue;

    // 服务发现
    std::pair<std::string, uint16_t> discoverService(RpcContext* context, const std::string &serviceName, const std::string &methodName, const std::string &argsStr);

    // 同步调用
    void syncCall(const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, RpcContext* context);

    // 异步调用
    void asyncCall(const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, google::protobuf::RpcController* controller);

    void onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp time);

    void onConnection(const TcpConnectionPtr &con);

    void startThread();
};

#endif