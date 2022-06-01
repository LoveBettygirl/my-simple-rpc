#ifndef LOGGER_H
#define LOGGER_H

#include "lockqueue.h"
#include "noncopyable.h"
#include <string>
#include <fstream>
#include <functional>

enum LogLevel {
    DEBUG,
    INFO, // 普通的日志信息
    WARN,
    ERROR, // 错误信息
    FATAL,
};

// 框架提供的日志系统
class Logger : private Noncopyable {
public:
    // 获取日志的单例
    static Logger *getInstance();
    
    // 写日志
    void log(LogLevel level, const std::string &msg);

    void start();

    void stop() { this->m_running = true; }
private:
    LockQueue<std::string> m_queue; // 日志缓冲队列
    bool m_running; // 程序是否正在运行，设置false来结束日志线程
    void writeLog();
    void doLog();
    Logger();
};

// 定义日志宏
#define LOG_DEBUG(logmsgformat, ...) \
    do { \
        Logger *logger = Logger::getInstance(); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger->log(DEBUG, buf); \
    } while (0)

#define LOG_INFO(logmsgformat, ...) \
    do { \
        Logger *logger = Logger::getInstance(); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger->log(INFO, buf); \
    } while (0)

#define LOG_WARN(logmsgformat, ...) \
    do { \
        Logger *logger = Logger::getInstance(); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger->log(WARN, buf); \
    } while (0)

#define LOG_ERROR(logmsgformat, ...) \
    do { \
        Logger *logger = Logger::getInstance(); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger->log(ERROR, buf); \
    } while (0)

#define LOG_FATAL(logmsgformat, ...) \
    do { \
        Logger *logger = Logger::getInstance(); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger->log(FATAL, buf); \
    } while (0)

#endif