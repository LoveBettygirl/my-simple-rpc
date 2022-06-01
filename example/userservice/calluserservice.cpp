#include <iostream>
#include <mysimplerpc.h>
#include "user.pb.h"
using namespace std;
using namespace chatservice;

void LoginResponseHandler(RpcContext *context, LoginResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc login response success: " << response->success() << endl;
    }
    else {
        cerr << "rpc login response error: " << response->result().errmsg() << endl;
    }
}

void RegisterResponseHandler(RpcContext *context, RegisterResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc register response success: " << response->success() << endl;
    }
    else {
        cerr << "rpc register response error: " << response->result().errmsg() << endl;
    }
}

void callUserService()
{
    // 演示调用远程发布的rpc方法Login
    RpcClient *client = new RpcClient();
    UserServiceRpc_Stub stub(client);
    // rpc方法的请求参数
    LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    LoginResponse response;
    // 发起rpc方法的调用，同步的rpc调用过程
    RpcContext context; // 控制对象，需要context的原因是想在rpc调用过程中，知道状态信息
    // 异步调用指定回调函数
    Closure *done = NewCallback(LoginResponseHandler, &context, &response);
    stub.Login(&context, &request, &response, done); // RpcClient->RpcClient::CallMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    context.waitForResult(); // 线程同步：等待结果

    // 演示调用远程发布的rpc方法Register
    RegisterRequest req;
    req.set_id(2000);
    req.set_name("li si");
    req.set_pwd("666666");
    RegisterResponse rsp;

    // 以同步的方式发起rpc调用请求，等待返回结果，不指定回调函数
    stub.Register(&context, &req, &rsp, nullptr); // RpcClient->RpcClient::CallMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    RegisterResponseHandler(&context, &rsp);
}

int main(int argc, char *argv[])
{
    // 整个程序启动以后，想使用框架来享受rpc服务调用，一定需要先调用框架的初始化函数（框架只初始化一次）
    // calluserservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    callUserService();
    
    return 0;
}