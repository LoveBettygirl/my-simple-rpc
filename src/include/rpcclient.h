#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <utility>
#include <functional>
#include "zookeeperutil.h"
#include "lockqueue.h"
#include <mutex>
#include "rpccontext.h"
#include "idgenerator.h"

using MethodDescriptor = google::protobuf::MethodDescriptor;
using ServiceDescriptor = google::protobuf::ServiceDescriptor;
using Message = google::protobuf::Message;
using Closure = google::protobuf::Closure;
using google::protobuf::NewCallback;

class RpcClient : public google::protobuf::RpcChannel {
public:
    RpcClient();
    ~RpcClient();
    // 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
    void CallMethod(const MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const Message* request,
                          Message* response, Closure* done);
private:
    ZkClient m_zkCli;
    static constexpr uint32_t MAGIC_NUM = 0xabcddcba;

    std::unordered_map<uint64_t, Closure*> m_callbackMap;
    bool m_running;
    std::mutex _connMutex;

    struct Request {
        uint64_t requestId;
        std::string ip;
        uint16_t port;
        std::string sendRpcStr;
        Message *response;
        RpcContext *context;
        Request(uint64_t requestId, const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, RpcContext* context):
            requestId(requestId), ip(ip), port(port), sendRpcStr(sendRpcStr), response(response), context(context) {}
    };

    struct Response {
        uint64_t requestId;
        Message *response;
        RpcContext *context;
        Response(uint64_t requestId, Message* response, RpcContext* context):
            requestId(requestId), response(response), context(context) {}
    };

    LockQueue<Request> m_requestQueue;
    LockQueue<Response> m_responseQueue;

    // 服务发现
    std::pair<std::string, uint16_t> discoverService(RpcContext* context, const std::string &serviceName, const std::string &methodName, const std::string &argsStr);

    void syncCall(const std::string &ip, uint16_t port, const std::string &sendRpcStr, Message* response, RpcContext* context);

    void startThread();

    void setCallback(uint64_t requestId, Closure *done);
};

#endif