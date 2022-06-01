#include <iostream>
#include <thread>
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
    for (int i = 0; i < 1000; i++) {
        EchoRequest request;
        EchoResponse response;
        RpcContext context;
        request.set_text("Hello, " + to_string(i));
        stub.Echo(&context, &request, &response, nullptr);
        EchoResponseHandler(&context, &response);
    }
}

int main(int argc, char *argv[])
{
    // callechoservice -i test.conf
    RpcConfig::getInstance()->init(argc, argv);

    callEchoService();
    
    return 0;
}