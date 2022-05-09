#include "rpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>

void ShowArgsHelp()
{
    std::cout << "format: command -i <configfile>" << std::endl;
}

void RpcApplication::Init(int argc, char *argv[])
{
    if (argc < 2) {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1) {
        switch (c) {
            case 'i':
                config_file = optarg;
                break;
            case '?':
            case ':':
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    // 开始加载配置文件了

}

RpcApplication &RpcApplication::GetInstance()
{
    static RpcApplication app;
    return app;
}