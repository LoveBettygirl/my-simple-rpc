#include <iostream>
#include <thread>
#include <chrono>
#include <mysimplerpc.h>
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
    for (int i = 0; i < 10; i++) {
        // 由于需要确保在函数被调用的时候使用到这些对象，response和context必须建立在堆上
        EchoRequest request;
        EchoResponse *response = new EchoResponse();
        RpcContext *context = new RpcContext();
        request.set_text("Hello, " + to_string(i));
        Closure *done = NewCallback(EchoResponseHandler, context, response);
        stub.Echo(context, &request, response, done);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main(int argc, char *argv[])
{
    // asynccallechoservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    callEchoService();
    
    return 0;
}