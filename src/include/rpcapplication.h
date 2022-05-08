#ifndef RPCAPPLICATION_H
#define RPCAPPLICATION_H

// 框架的初始化类
// 使用单例模式
class RpcApplication {
public:
    static void Init(int argc, char *argv[]);
    static RpcApplication &GetInstance() {
        static RpcApplication app;
        return app;
    }
private:
    RpcApplication() {}
    RpcApplication(const RpcApplication &) = delete;
    RpcApplication(RpcApplication &&) = delete;
};

#endif