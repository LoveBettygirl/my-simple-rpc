#include "rpcconfig.h"
#include <iostream>

// 负责解析加载配置文件
void RpcConfig::LoadConfigFile(const std::string &configFile)
{
    std::ifstream fin(configFile);
    if (!fin.is_open()) {
        std::cerr << configFile << " is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string temp;
    // 1. 注释 2. 正确的配置项 3. 去掉开头多余的空格
    while (std::getline(fin, temp)) {
        Trim(temp);

        // 判断#的注释
        if (temp[0] == '#' || temp.empty()) {
            continue;
        }

        // 解析配置项
        int idx = temp.find('=');
        if (idx == -1) {
            // 配置项不合法
            continue;
        }

        std::string key;
        std::string value;
        key = temp.substr(0, idx);
        Trim(key);
        value = temp.substr(idx + 1);
        Trim(value);
        m_configMap.insert({key, value});
    }

    fin.close();
}

// 查询配置项信息
std::string RpcConfig::Load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it == m_configMap.end()) {
        return "";
    }
    return it->second;
}

// 去掉字符串前后的空格
void RpcConfig::Trim(std::string &temp)
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