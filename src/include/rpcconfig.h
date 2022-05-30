#ifndef RPCCONFIG_H
#define RPCCONFIG_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <cstring>
#include "noncopyable.h"

// 框架读取配置文件类
class RpcConfig : private Noncopyable {
public:
    void init(int argc, char *argv[]);

    static RpcConfig *getInstance();

    // 负责解析加载配置文件
    void loadConfigFile(const std::string &configFile);

    // 查询配置项信息
    std::string load(const std::string &key);
private:
    std::unordered_map<std::string, std::string> m_configMap;

    // 去掉字符串前后的空格
    void trim(std::string &temp);
};

#endif