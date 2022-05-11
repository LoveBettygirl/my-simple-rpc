#include "rpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>

RpcConfig RpcApplication::m_config;

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
    std::string configFile;
    while ((c = getopt(argc, argv, "i:")) != -1) {
        switch (c) {
            case 'i':
                configFile = optarg;
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
    m_config.LoadConfigFile(configFile);
}

RpcApplication &RpcApplication::GetInstance()
{
    static RpcApplication app;
    return app;
}

RpcConfig &RpcApplication::GetConfig()
{
    return m_config;
}