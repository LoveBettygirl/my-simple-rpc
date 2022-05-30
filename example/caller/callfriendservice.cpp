#include <iostream>
#include <mysimplerpc.h>
#include "friend.pb.h"
using namespace std;
using namespace chatservice;

void GetFriendsListResponseHandler(RpcContext *context, GetFriendsListResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc GetFriendsList response success!" << endl;
        int size = response->friends_size();
        for (int i = 0; i < size; ++i) {
            cout << "index: " << (i + 1) << " name: " << response->friends(i) << endl;
        }
    }
    else {
        cerr << "rpc GetFriendsList response error: " << response->result().errmsg() << endl;
    }
}

void callFriendService()
{
    // 演示调用远程发布的rpc方法GetFriendsList
    RpcClient *client = new RpcClient(); // stub的析构函数会释放掉
    FriendServiceRpc_Stub stub(client);
    // rpc方法的请求参数
    GetFriendsListRequest request;
    request.set_userid(1000);
    // rpc方法的响应
    GetFriendsListResponse response;
    // 发起rpc方法的调用，同步的rpc调用过程
    RpcContext context; // 控制对象，需要context的原因是想在rpc调用过程中，知道状态信息
    // 异步调用指定回调函数
    Closure *done = NewCallback(GetFriendsListResponseHandler, &context, &response);
    stub.GetFriendsList(&context, &request, &response, done); // RpcClient->RpcClient::CallMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    context.waitForResult();
}

int main(int argc, char *argv[])
{
    // 整个程序启动以后，想使用框架来享受rpc服务调用，一定需要先调用框架的初始化函数（框架只初始化一次）
    // callfriendservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    callFriendService();
    
    return 0;
}