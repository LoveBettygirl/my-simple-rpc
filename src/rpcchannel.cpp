#include "rpcchannel.h"
#include "rpcheader.pb.h"
#include "rpcapplication.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include "rpccontroller.h"

// 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
void RpcChannel::CallMethod(const MethodDescriptor* method,
                        google::protobuf::RpcController* controller, const Message* request,
                        Message* response, Closure* done)
{
    const ServiceDescriptor *sd = method->service();
    std::string serviceName = sd->name();
    std::string methodName = method->name();

    // 获取参数的序列化字符串长度 argsSize
    int argsSize = 0;
    std::string argsStr;
    if (request->SerializeToString(&argsStr)) {
        argsSize = argsStr.size();
    }
    else {
        controller->SetFailed("serialize request error!");
        return;
    }

    // 定义rpc的请求header
    mysimplerpc::RpcHeader rpcHeader;
    rpcHeader.set_servicename(serviceName);
    rpcHeader.set_methodname(methodName);
    rpcHeader.set_argssize(argsSize);

    uint32_t headerSize = 0;
    std::string rpcHeaderStr;
    if (rpcHeader.SerializeToString(&rpcHeaderStr)) {
        headerSize = rpcHeaderStr.size();
    }
    else {
        controller->SetFailed("serialize rpc header error!");
        return;
    }

    // 组织待发送的rpc请求字符串
    std::string sendRpcStr;
    sendRpcStr.insert(0, std::string((char*)&headerSize, 4)); // headerSize
    sendRpcStr += rpcHeaderStr;
    sendRpcStr += argsStr;

    // 打印调试信息
    std::cout << "==================================================" << std::endl;
    std::cout << "headerSize: " << headerSize << std::endl;
    std::cout << "rpcHeaderStr: " << rpcHeaderStr << std::endl;
    std::cout << "serviceName: " << serviceName << std::endl;
    std::cout << "methodName: " << methodName << std::endl;
    std::cout << "argsSize: " << argsSize << std::endl;
    std::cout << "argsStr: " << argsStr << std::endl;
    std::cout << "==================================================" << std::endl;

    // 使用tcp编程，完成rpc方法远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1) {
        controller->SetFailed(std::string("create socket error: ") + strerror(errno));
        close(clientfd);
        return;
    }

    // 读取配置文件的rpcserver的信息
    std::string ip = RpcApplication::GetInstance().GetConfig().Load("rpcserver_ip");
    uint16_t port = std::stoi(RpcApplication::GetInstance().GetConfig().Load("rpcserver_port"));

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    // 连接rpc服务节点
    if (connect(clientfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        controller->SetFailed(std::string("connect error: ") + strerror(errno));
        close(clientfd);
        return;
    }

    // 发送rpc请求
    if (send(clientfd, sendRpcStr.c_str(), sendRpcStr.size(), 0) == -1) {
        controller->SetFailed(std::string("send error: ") + strerror(errno));
        close(clientfd);
        return;
    }

    // 接收rpc请求的返回值
    char recvBuf[1024] = {0};
    int recvSize = 0;
    if ((recvSize = recv(clientfd, recvBuf, sizeof(recvBuf), 0)) == -1) {
        controller->SetFailed(std::string("recv error: ") + strerror(errno));
        close(clientfd);
        return;
    }

    // 反序列化rpc调用的远程数据
    // std::string responseStr(recvBuf, 0, recvSize); // 出现问题，recvBuf遇到\0，后面的数据就存不下来了，导致反序列化失败
    // if (!response->ParseFromString(responseStr)) {
    if (!response->ParseFromArray(recvBuf, recvSize)) {
        controller->SetFailed(std::string("parse error! response str: ") + recvBuf);
        close(clientfd);
        return;
    }

    close(clientfd);
}