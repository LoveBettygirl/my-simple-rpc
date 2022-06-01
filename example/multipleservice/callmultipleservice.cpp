#include <iostream>
#include <string>
#include <mysimplerpc.h>
#include "calculator.pb.h"
#include "hello.pb.h"
using namespace std;
using namespace multipleservice;

void CalculateResponseHandler(RpcContext *context, CalculateResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc Calculate response success! cal result: " << response->c() << endl;
    }
    else {
        cerr << "rpc Calculate response error: " << response->result().errmsg() << endl;
    }
}

void HelloResponseHandler(RpcContext *context, HelloResponse *response) {
    if (context->Failed()) {
        cerr << context->ErrorText() << endl;
        return;
    }
    if (response->result().errcode() == 0) {
        cout << "rpc Hello response success! greeting message: " << response->message() << endl;
    }
    else {
        cerr << "rpc Hello response error: " << response->result().errmsg() << endl;
    }
}

void callCalculatorService()
{
    RpcClient *client = new RpcClient();
    CalculatorServiceRpc_Stub stub(client);
    CalculateRequest request;
    CalculateResponse response;
    RpcContext context;

    request.set_a(1);
    request.set_b(2);
    stub.Add(&context, &request, &response, nullptr);
    CalculateResponseHandler(&context, &response);

    request.set_a(51);
    request.set_b(3);
    stub.Sub(&context, &request, &response, nullptr);
    CalculateResponseHandler(&context, &response);

    request.set_a(4);
    request.set_b(5);
    stub.Mul(&context, &request, &response, nullptr);
    CalculateResponseHandler(&context, &response);

    request.set_a(5);
    request.set_b(2);
    stub.Div(&context, &request, &response, nullptr);
    CalculateResponseHandler(&context, &response);

    request.set_a(2);
    request.set_b(0);
    stub.Div(&context, &request, &response, nullptr);
    CalculateResponseHandler(&context, &response);
}

void callHelloService()
{
    RpcClient *client = new RpcClient();
    HelloServiceRpc_Stub stub(client);
    HelloRequest request;
    HelloResponse response;
    RpcContext context;

    request.set_name("world");
    stub.Hello(&context, &request, &response, nullptr);
    HelloResponseHandler(&context, &response);
}

// 该程序的本质是一个服务器
int main(int argc, char *argv[])
{
    // callmultipleservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    callCalculatorService();
    callHelloService();

    return 0;
}