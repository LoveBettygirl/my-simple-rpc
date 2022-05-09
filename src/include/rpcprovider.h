#ifndef RPCPROVIDER_H
#define RPCPROVIDER_H

#include <google/protobuf/service.h>

using Service = google::protobuf::Service;

// 框架提供的专门负责发布rpc服务的网络对象类
// 需要支持高并发（可能有很多人请求rpc调用），因此需要使用muduo库实现
class RpcProvider {
public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void NotifyService(Service *service);

    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();
};

#endif