#include <iostream>
#include <string>
#include <mysimplerpc.h>
#include "user.pb.h"

/*
UserService原来是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendLists
现在变成RPC服务
*/
class UserService: public chatservice::UserServiceRpc { // 使用在rpc服务发布端（rpc服务提供者，callee）
public:
    bool Login(const std::string &name, const std::string &pwd) {
        std::cout << "doing local service: Login" << std::endl;
        std::cout << "name: " << name << " pwd: " << pwd << std::endl;
        // return false;
        return true;
    }

    bool Register(uint32_t id, const std::string &name, const std::string &pwd) {
        std::cout << "doing local service: Register" << std::endl;
        std::cout << "id: " << id << " name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }

    // 重写基类UserServiceRpc的虚函数，下面这些方法都是框架直接调用的
    // 网络中的rpc请求首先被框架接收，框架根据请求的方法名、参数、返回值匹配到该方法，然后将该请求上报到这里
    // 该方法从请求中拿出数据，然后做本地业务，然后填写响应（response），然后执行回调（done）
    // 执行完的rpc方法返回值response由框架序列化，再通过框架和网络把响应返回回去
    void Login(::google::protobuf::RpcController* controller,
                       const ::chatservice::LoginRequest* request,
                       ::chatservice::LoginResponse* response,
                       ::google::protobuf::Closure* done) {
        // 框架已经将request反序列化好了
        // 框架给业务上报了请求参数LoginRequest，应用获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 做本地业务
        bool loginresult = Login(name, pwd);

        // 把响应写入response，其序列化由框架负责
        chatservice::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Login success!");
        // code->set_errcode(1);
        // code->set_errmsg("Login error!");
        response->set_success(loginresult);

        // 执行回调操作
        // 回调函数中执行响应对象数据的序列化和网络发送（都是由框架完成的）
        // Closure是抽象类，如果想定义回调函数，必须要继承Closure并重写Run
        done->Run();
    }

    void Register(::google::protobuf::RpcController* controller,
                       const ::chatservice::RegisterRequest* request,
                       ::chatservice::RegisterResponse* response,
                       ::google::protobuf::Closure* done) {
        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 做本地业务
        bool ret = Register(id, name, pwd);

        // 把响应写入response，其序列化由框架负责
        chatservice::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Register success!");
        response->set_success(ret);

        done->Run();
    }

};

// 该程序的本质是一个服务器
int main(int argc, char *argv[])
{
    // UserService us;
    // us.Login("xxx", "xxx"); // 现在只能这样调用，其他进程不行。需要设计成RPC方法，支持分布式调用。

    // 调用框架的初始化操作(例如：配置、日志初始化)
    // userservice -i test.conf
    RpcApplication::Init(argc, argv);

    // 把UserService、FriendService对象发布到rpc节点上
    // privider是一个rpc网络服务对象
    RpcProvider provider;
    provider.NotifyService(new UserService()); // 发布服务
    // provider.NotifyService(new xxxService()); // 假如想发布多个服务

    // 启动一个rpc服务发布节点
    // Run之后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}