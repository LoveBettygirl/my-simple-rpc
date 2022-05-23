#include <iostream>
#include <string>
#include <vector>
#include <mysimplerpc.h>
#include "friend.pb.h"
using namespace std;

class FriendService: public chatservice::FriendServiceRpc {
public:
    vector<string> GetFriendsList(uint32_t userid) {
        cout << "do GetFriendsList service! userid: " << userid << endl;
        vector<string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        vec.push_back("wang shuo");
        return vec;
    }

    // 重写基类方法
    void GetFriendsList(::google::protobuf::RpcController* controller,
                       const ::chatservice::GetFriendsListRequest* request,
                       ::chatservice::GetFriendsListResponse* response,
                       ::google::protobuf::Closure* done) {
        uint32_t userid = request->userid();
        vector<string> friendsList = GetFriendsList(userid);

        chatservice::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("GetFriendsList success!");
        for (const string &name : friendsList) {
            string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

// 该程序的本质是一个服务器
int main(int argc, char *argv[])
{
    // UserService us;
    // us.Login("xxx", "xxx"); // 现在只能这样调用，其他进程不行。需要设计成RPC方法，支持分布式调用。

    // 调用框架的初始化操作(例如：配置、日志初始化)
    // friendservice -i test.conf
    RpcApplication::Init(argc, argv);

    // 把UserService、FriendService对象发布到rpc节点上
    // privider是一个rpc网络服务对象
    RpcProvider *provider = RpcProvider::GetInstance();
    provider->NotifyService(new FriendService()); // 发布服务
    // provider->NotifyService(new xxxService()); // 假如想发布多个服务

    // 启动一个rpc服务发布节点
    // Run之后，进程进入阻塞状态，等待远程的rpc调用请求
    provider->Run();

    return 0;
}