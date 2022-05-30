#include "rpccontext.h"

RpcContext::RpcContext(): m_failed(false), m_errText("") {}

void RpcContext::Reset()
{
    m_failed = false;
    m_errText = "";
    sem.reset();
}

bool RpcContext::Failed() const
{
    return m_failed;
}

std::string RpcContext::ErrorText() const
{
    return m_errText;
}

void RpcContext::SetFailed(const std::string &reason)
{
    m_failed = true;
    m_errText = reason;
}

void RpcContext::waitForResult()
{
    sem.wait();
}

void RpcContext::complete()
{
    sem.post();
}

// 目前未实现具体的功能
void RpcContext::StartCancel(){}
bool RpcContext::IsCanceled() const { return false; }
void RpcContext::NotifyOnCancel(google::protobuf::Closure* callback) {}