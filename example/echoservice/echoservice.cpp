#include <iostream>
#include <string>
#include <mysimplerpc.h>
#include "echo.pb.h"
using namespace std;

class EchoService: public echoservice::EchoServiceRpc {
public:
    string Echo(const string &text) {
        return text;
    }

    // 重写基类方法
    void Echo(::google::protobuf::RpcController* controller,
                       const ::echoservice::EchoRequest* request,
                       ::echoservice::EchoResponse* response,
                       ::google::protobuf::Closure* done) {
        response->set_text(Echo(request->text()));

        echoservice::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Echo success!");

        done->Run();
    }
};

int main(int argc, char *argv[])
{
    // echoservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);
    RpcServer *server = RpcServer::getInstance();
    server->registerService(new EchoService());
    server->start();

    return 0;
}