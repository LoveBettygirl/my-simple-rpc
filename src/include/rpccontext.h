#ifndef RPCCONTEXT_H
#define RPCCONTEXT_H

#include <google/protobuf/service.h>
#include <string>
#include <functional>
#include "sem.h"

using Closure = google::protobuf::Closure;
using Message = google::protobuf::Message;

class RpcContext : public google::protobuf::RpcController {
public:
    RpcContext();
    void Reset();
    bool Failed() const;
    std::string ErrorText() const;
    void SetFailed(const std::string &reason);
    void waitForResult();
    void complete();

    // 目前未实现具体的功能
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(Closure *callback);
private:
    bool m_failed; // RPC方法执行过程中的状态
    std::string m_errText; // RPC方法执行过程中的错误信息
    Semaphore sem;
};

#endif