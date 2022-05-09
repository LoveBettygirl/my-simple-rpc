#include "rpcapplication.h"

void RpcApplication::Init(int argc, char *argv[])
{

}

RpcApplication &RpcApplication::GetInstance()
{
    static RpcApplication app;
    return app;
}