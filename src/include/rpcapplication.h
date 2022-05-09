#ifndef RPCAPPLICATION_H
#define RPCAPPLICATION_H

// 框架的基础类，负责框架的一些初始化操作
// 使用单例模式
class RpcApplication {
public:
    static void Init(int argc, char *argv[]);
    static RpcApplication &GetInstance();
private:
    RpcApplication() {}
    RpcApplication(const RpcApplication &) = delete;
    RpcApplication(RpcApplication &&) = delete;
};

#endif