#include "rpcconfig.h"
#include <iostream>
#include <unistd.h>
#include <cerrno>

void showArgsHelp(const char *argv)
{
    std::cout << "Usage: " << basename(argv) << " -i <configfile>" << std::endl;
}

void RpcConfig::init(int argc, char *argv[])
{
    if (argc < 2) {
        showArgsHelp(argv[0]);
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
                showArgsHelp(argv[0]);
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    // 开始加载配置文件了
    loadConfigFile(configFile);
}

RpcConfig *RpcConfig::getInstance()
{
    static RpcConfig config;
    return &config;
}

// 负责解析加载配置文件
void RpcConfig::loadConfigFile(const std::string &configFile)
{
    std::ifstream fin(configFile);
    if (!fin.is_open()) {
        perror("Open config file");
        exit(EXIT_FAILURE);
    }

    std::string temp;
    // 1. 注释 2. 正确的配置项 3. 去掉开头多余的空格
    while (std::getline(fin, temp)) {
        // 忽略注释
        int idx = temp.find('#');
        if (idx != -1) {
            temp = temp.substr(0, idx);
        }

        trim(temp);
        
        if (temp.empty()) {
            continue;
        }

        // 解析配置项
        idx = temp.find('=');
        if (idx == -1) {
            // 配置项不合法
            continue;
        }

        std::string key;
        std::string value;
        key = temp.substr(0, idx);
        trim(key);
        value = temp.substr(idx + 1);
        trim(value);
        m_configMap.insert({key, value});
    }

    fin.close();
}

// 查询配置项信息
std::string RpcConfig::load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it == m_configMap.end()) {
        return "";
    }
    return it->second;
}

// 去掉字符串前后的空格
void RpcConfig::trim(std::string &temp)
{
    // 去掉字符串前面多余的空格
    int idx = temp.find_first_not_of(' ');
    if (idx != -1) {
        // 说明字符串前面有空格
        temp = temp.substr(idx);
    }
    // 去掉字符串后面多余的空格
    idx = temp.find_last_not_of(' ');
    if (idx != -1) {
        // 说明字符串后面有空格
        temp = temp.substr(0, idx + 1);
    }
}