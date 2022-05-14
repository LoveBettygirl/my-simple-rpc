#ifndef RPCCHANNEL_H
#define RPCCHANNEL_H

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

using MethodDescriptor = google::protobuf::MethodDescriptor;
using ServiceDescriptor = google::protobuf::ServiceDescriptor;
using RpcController = google::protobuf::RpcController;
using Message = google::protobuf::Message;
using Closure = google::protobuf::Closure;

class RpcChannel : public google::protobuf::RpcChannel {
public:
    // 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
    void CallMethod(const MethodDescriptor* method,
                          RpcController* controller, const Message* request,
                          Message* response, Closure* done);
};

#endif