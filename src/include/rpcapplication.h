#ifndef RPCAPPLICATION_H
#define RPCAPPLICATION_H

#include "rpcconfig.h"

// 框架的基础类，负责框架的一些初始化操作
// 使用单例模式
class RpcApplication {
public:
    static void Init(int argc, char *argv[]);
    static RpcApplication &GetInstance();
private:
    static RpcConfig m_config;

    RpcApplication() {}
    RpcApplication(const RpcApplication &) = delete;
    RpcApplication(RpcApplication &&) = delete;
};

#endif