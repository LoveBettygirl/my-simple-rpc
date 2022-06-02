# my-simple-rpc

基于Linux下C++环境实现的简单的RPC框架。

## 功能

- 使用[Muduo](https://github.com/chenshuo/muduo)网络库为RPC服务端提供高性能的网络服务，实现网络和实际功能逻辑的解耦。
- 自定义私有协议完成RPC请求和响应，并进行了TCP粘包处理。
- 使用Protobuf作为RPC方法调用和参数的序列化和反序列化协议。
- RPC客户端支持同步/异步调用（Callback）两种形式。
- 使用ZooKeeper作为服务治理中间件，实现了服务注册和服务发现功能。
- 实现了随机、轮询、一致性哈希三种负载均衡策略。

## 依赖

- gcc v7.5
- CMake（>=3.0）
- Muduo（需要依赖boost库）
- Protobuf
- ZooKeeper（>=3.4，需要先安装JDK）

## 项目使用

### 构建和安装项目

安装完依赖之后，使用如下命令构建项目：

```bash
chmod 777 clean.sh
chmod 777 build.sh
chmod 777 install.sh
./clean.sh
./build.sh
sudo ./install.sh
```

### 配置文件

见 `test.conf`：

```bash
# rpc节点的ip地址
rpcserver.ip=127.0.0.1
# rpc节点的端口号
rpcserver.port=8000
# rpc客户端的负载均衡策略，负载均衡策略有Random、Round、ConsistentHash三种，默认采用Random
rpcclient.loadbalance=Random
# zookeeper的ip地址
zookeeper.ip=127.0.0.1
# zookeeper的端口号
zookeeper.port=2181
# zookeeper的timeout，默认为30s
zookeeper.timeout=30000
```

### 示例程序

#### 定义RPC服务

在文件 `echo.proto` 中：

```protobuf
syntax = "proto3";

package echoservice;

option cc_generic_services = true;

message ResultCode {
    int32 errcode = 1;
    bytes errmsg = 2;
}

message EchoRequest {
    bytes text = 1;
}

message EchoResponse {
    ResultCode result = 1;
    bytes text = 2;
}

service EchoServiceRpc {
    // 注意，这里定义的方法名和本地服务的方法名不一定要一致，但是最好一致
    rpc Echo(EchoRequest) returns(EchoResponse);
}
```

生成对应的C++文件：

```bash
protoc echo.proto --cpp_out=./
```

将会在当前目录下产生源文件 `echo.pb.cc` 和头文件 `echo.pb.h`。

#### RPC服务端

在文件 `server.cpp` 中：

```c++
#include <iostream>
#include <string>
#include <mysimplerpc/mysimplerpc.h>
#include "echo.pb.h"
using namespace std;

class EchoService: public echoservice::EchoServiceRpc {
public:
    // 本地方法
    string Echo(const string &text) {
        return text;
    }

    // 重写基类方法，变成远程方法
    void Echo(::google::protobuf::RpcController* controller,
                       const ::echoservice::EchoRequest* request,
                       ::echoservice::EchoResponse* response,
                       ::google::protobuf::Closure* done) {
        response->set_text(Echo(request->text())); // 调用本地方法，获得执行结果并填入到响应中

        echoservice::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Echo success!");

        done->Run();
    }
};

int main(int argc, char *argv[])
{
    RpcConfig::getInstance()->init(argc, argv);
    RpcServer *server = RpcServer::getInstance();
    server->registerService(new EchoService()); // 注册服务
    server->start(); // 运行服务端
    return 0;
}
```

#### RPC客户端

在文件 `client.cpp` 中：

```c++
#include <iostream>
#include <mysimplerpc/mysimplerpc.h>
#include "echo.pb.h"
using namespace std;
using namespace echoservice;

void EchoResponseHandler(RpcContext *context, EchoResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc Echo response success! echo text: " << response->text() << endl;
    }
    else {
        cerr << "rpc Echo response error: " << response->result().errmsg() << endl;
    }
}

void callEchoService()
{
    RpcClient *client = new RpcClient();
    EchoServiceRpc_Stub stub(client);
    EchoRequest request;
    EchoResponse response;
    RpcContext context;
    request.set_text("Hello world!");
    stub.Echo(&context, &request, &response, nullptr); // 同步调用
    EchoResponseHandler(&context, &response);
}

int main(int argc, char *argv[])
{
    RpcConfig::getInstance()->init(argc, argv);
    callEchoService();
    return 0;
}
```

#### 编译并运行程序

启动项目前必须先启动 `zkServer`。

服务端：

```bash
g++ server.cpp echo.pb.cc -lmysimplerpc -lprotobuf -lzookeeper_mt -pthread -lmuduo_net -lmuduo_base --std=c++11 -o server
./server -i test.conf
# 配置文件可替换为其他路径
```

客户端：

```bash
g++ client.cpp echo.pb.cc -lmysimplerpc -lprotobuf -lzookeeper_mt -pthread -lmuduo_net -lmuduo_base --std=c++11 -o client
./client -i test.conf
# 配置文件可替换为其他路径
```

### 其他使用示例

见 `example/` 文件夹，构建项目后在 `bin/` 文件夹下生成所有示例程序的可执行文件。

注意：当脱离项目源码工作区之后，头文件的引用必须改为：

```c++
#include <mysimplerpc/mysimplerpc.h>
```

## 自定义协议格式

- 魔数（4 bytes）：`0xabcddcba`，用于过滤非本协议数据包
- 消息类型（4 bytes）：0表示RPC请求，1表示RPC响应
- 内容长度（4 bytes）：该字段后面所有内容的总长度
- （请求和响应才有）请求ID（8 bytes）：标示同一请求对应的请求和响应消息。最高Bit保留，之后15 Bits表示请求信息的哈希值，之后32 Bits表示时间戳，之后16 Bits表示自增值（从0开始）
- 消息的其他内容
  - 请求消息中包括：
    - 请求的信息长度（4 bytes）
    - 请求的信息（用Protobuf序列化之后的，分别是请求的服务名、请求的方法名、序列化后的参数长度）
    - 序列化后的参数内容

## TODO

- 加入超时重试功能，提升可用性
- 加入服务熔断、降级、限流等其他服务治理功能
- 自定义网络库和服务注册中心，实现与Muduo和ZooKeeper的解耦
- 引入协程机制
- 精简接口定义，自定义生成器
- 性能测试
