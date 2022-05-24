#include "rpccontroller.h"
#include "logger.h"

RpcController::RpcController(): m_failed(false), m_errText("") {}

void RpcController::Reset()
{
    m_failed = false;
    m_errText = "";
}

bool RpcController::Failed() const
{
    return m_failed;
}

std::string RpcController::ErrorText() const
{
    return m_errText;
}

void RpcController::SetFailed(const std::string &reason)
{
    m_failed = true;
    m_errText = reason;
    LOG_ERROR("%s", m_errText.c_str());
    Logger::GetInstance()->SetEnd();
}

// 目前未实现具体的功能
void RpcController::StartCancel(){}
bool RpcController::IsCanceled() const { return false; }
void RpcController::NotifyOnCancel(google::protobuf::Closure* callback) {}