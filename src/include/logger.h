#ifndef LOGGER_H
#define LOGGER_H

#include "lockqueue.h"
#include <string>
#include <fstream>

enum LogLevel {
    INFO, // 普通的日志信息
    ERROR, // 错误信息
};

// 框架提供的日志系统
class Logger {
public:
    // 获取日志的单例
    static Logger &GetInstance();

    // 设置日志级别
    void SetLogLevel(LogLevel level);
    
    // 写日志
    void Log(const std::string &msg);
private:
    int m_logLevel; // 记录日志级别
    LockQueue<std::string> m_queue; // 日志缓冲队列
    Logger();
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
};

// 定义日志宏
#define LOG_INFO(logmsgformat, ...) \
    do { \
        Logger &logger = Logger::GetInstance(); \
        logger.SetLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger.Log(buf); \
    } while ({0});

#define LOG_ERROR(logmsgformat, ...) \
    do { \
        Logger &logger = Logger::GetInstance(); \
        logger.SetLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger.Log(buf); \
    } while ({0});

#endif