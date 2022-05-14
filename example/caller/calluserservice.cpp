#include <iostream>
#include "rpcapplication.h"
#include "user.pb.h"
#include "rpcchannel.h"

int main(int argc, char *argv[])
{
    // 整个程序启动以后，想使用框架来享受rpc服务调用，一定需要先调用框架的初始化函数（框架只初始化一次）
    // comsumer -i config.conf
    RpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    // privider是一个rpc网络服务对象
    chatservice::UserServiceRpc_Stub stub(new RpcChannel());
    // rpc方法的请求参数
    chatservice::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    chatservice::LoginResponse response;
    // 发起rpc方法的调用，同步的rpc调用过程
    stub.Login(nullptr, &request, &response, nullptr); // RpcChannel->RpcChannel::CallMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    if (response.result().errcode() == 0) {
        std::cout << "rpc login response success: " << response.success() << std::endl;
    }
    else {
        std::cerr << "rpc login response error: " << response.result().errmsg() << std::endl;
    }
    
    return 0;
}