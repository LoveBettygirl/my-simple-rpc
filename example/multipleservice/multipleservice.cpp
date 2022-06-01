#include <iostream>
#include <string>
#include <exception>
#include <mysimplerpc.h>
#include "calculator.pb.h"
#include "hello.pb.h"
using namespace std;

class CalculatorService: public multipleservice::CalculatorServiceRpc {
public:
    int Add(int a, int b) {
        return a + b;
    }

    void Add(::google::protobuf::RpcController* controller,
                       const ::multipleservice::CalculateRequest* request,
                       ::multipleservice::CalculateResponse* response,
                       ::google::protobuf::Closure* done) {
        int a = request->a(), b = request->b();
        response->set_c(Add(a, b));
        multipleservice::CalculateResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Add success!");
        done->Run();
    }

    int Sub(int a, int b) {
        return a - b;
    }

    void Sub(::google::protobuf::RpcController* controller,
                       const ::multipleservice::CalculateRequest* request,
                       ::multipleservice::CalculateResponse* response,
                       ::google::protobuf::Closure* done) {
        int a = request->a(), b = request->b();
        response->set_c(Sub(a, b));
        multipleservice::CalculateResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Sub success!");
        done->Run();
    }

    int Mul(int a, int b) {
        return a * b;
    }

    void Mul(::google::protobuf::RpcController* controller,
                       const ::multipleservice::CalculateRequest* request,
                       ::multipleservice::CalculateResponse* response,
                       ::google::protobuf::Closure* done) {
        int a = request->a(), b = request->b();
        response->set_c(Mul(a, b));
        multipleservice::CalculateResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Mul success!");
        done->Run();
    }

    int Div(int a, int b) {
        if (b == 0)
            throw runtime_error("cannot divide 0");
        return a / b;
    }

    void Div(::google::protobuf::RpcController* controller,
                       const ::multipleservice::CalculateRequest* request,
                       ::multipleservice::CalculateResponse* response,
                       ::google::protobuf::Closure* done) {
        int a = request->a(), b = request->b();
        int c = 0;
        multipleservice::CalculateResultCode *code = response->mutable_result();
        try {
            c = Div(a, b);
            code->set_errcode(0);
            code->set_errmsg("Div success!");
        }
        catch (exception &e) {
            code->set_errcode(1);
            code->set_errmsg(string("Div failed! ") + e.what());
        }
        done->Run();
    }
};

class HelloService: public multipleservice::HelloServiceRpc {
public:
    string Hello(const string &name) {
        return "Hello, " + name;
    }

    void Hello(::google::protobuf::RpcController* controller,
                       const ::multipleservice::HelloRequest* request,
                       ::multipleservice::HelloResponse* response,
                       ::google::protobuf::Closure* done) {
        response->set_message(Hello(request->name()));
        multipleservice::HelloResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("Hello success!");
        done->Run();
    }
};

// 该程序的本质是一个服务器
int main(int argc, char *argv[])
{
    // multipleservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    RpcServer *server = RpcServer::getInstance();
    server->registerService(new CalculatorService()); // 发布服务
    server->registerService(new HelloService()); // 同一进程发布多个服务

    server->start();

    return 0;
}