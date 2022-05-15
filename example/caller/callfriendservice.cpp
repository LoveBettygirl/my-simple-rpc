#include <iostream>
#include "rpcapplication.h"
#include "friend.pb.h"
#include "rpcchannel.h"

void CallFriendService()
{
    // 演示调用远程发布的rpc方法GetFriendsList
    // privider是一个rpc网络服务对象
    chatservice::FriendServiceRpc_Stub stub(new RpcChannel());
    // rpc方法的请求参数
    chatservice::GetFriendsListRequest request;
    request.set_userid(1000);
    // rpc方法的响应
    chatservice::GetFriendsListResponse response;
    // 发起rpc方法的调用，同步的rpc调用过程
    stub.GetFriendsList(nullptr, &request, &response, nullptr); // RpcChannel->RpcChannel::CallMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    if (response.result().errcode() == 0) {
        std::cout << "rpc GetFriendsList response success!" << std::endl;
        int size = response.friends_size();
        for (int i = 0; i < size; ++i) {
            std::cout << "index: " << (i + 1) << " name: " << response.friends(i) << std::endl;
        }
    }
    else {
        std::cerr << "rpc GetFriendsList response error: " << response.result().errmsg() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // 整个程序启动以后，想使用框架来享受rpc服务调用，一定需要先调用框架的初始化函数（框架只初始化一次）
    // callfriendservice -i test.conf
    RpcApplication::Init(argc, argv);

    CallFriendService();
    
    return 0;
}