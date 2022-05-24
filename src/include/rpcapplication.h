#ifndef RPCAPPLICATION_H
#define RPCAPPLICATION_H

#include "rpcconfig.h"
#include "noncopyable.h"

static const char *ROOT_PATH = "/my-simple-rpc";

// 框架的基础类，负责框架的一些初始化操作
// 使用单例模式
class RpcApplication : private Noncopyable {
public:
    static void Init(int argc, char *argv[]);
    static RpcApplication *GetInstance();
    static RpcConfig &GetConfig();
private:
    static RpcConfig m_config;
};

#endif