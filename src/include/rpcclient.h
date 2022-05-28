#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <utility>
#include "zookeeperutil.h"

using MethodDescriptor = google::protobuf::MethodDescriptor;
using ServiceDescriptor = google::protobuf::ServiceDescriptor;
using Message = google::protobuf::Message;
using Closure = google::protobuf::Closure;

class RpcClient : public google::protobuf::RpcChannel {
public:
    RpcClient();
    ~RpcClient();
    // 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
    void CallMethod(const MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const Message* request,
                          Message* response, Closure* done);

    // 服务发现
    std::pair<std::string, uint16_t> discoverService(google::protobuf::RpcController* controller, const std::string &serviceName, const std::string &methodName, const std::string &argsStr);
private:
    ZkClient m_zkCli;
};

#endif