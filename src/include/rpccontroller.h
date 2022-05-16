#ifndef RPCCONTROLLER_H
#define RPCCONTROLLER_H

#include <google/protobuf/service.h>
#include <string>

using Closure = google::protobuf::Closure;

class RpcController : public google::protobuf::RpcController {
public:
    RpcController();
    void Reset();
    bool Failed() const;
    std::string ErrorText() const;
    void SetFailed(const std::string &reason);

    // 目前未实现具体的功能
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(Closure *callback);
private:
    bool m_failed; // RPC方法执行过程中的状态
    std::string m_errText; // RPC方法执行过程中的错误信息
};

#endif