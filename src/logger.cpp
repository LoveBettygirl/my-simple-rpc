#include "logger.h"
#include <ctime>

// 获取日志的单例
Logger &Logger::GetInstance()
{
    static Logger logger;
    return logger;
}

Logger::Logger()
{
    // 启动专门的写日志线程
    std::thread writeLogTask([&]() {
        while (true) {
            // 获取当天的日期，然后取日志信息，写入相应的日志文件中
            time_t now = time(nullptr);
            tm *nowtm = localtime(&now);

            char fileName[128] = {0};
            sprintf(fileName, "%04d-%02d-%02d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

            std::ofstream fout(fileName, std::ios::app);
            if (!fout.is_open()) {
                perror("open log file error");
                exit(EXIT_FAILURE);
            }

            std::string msg = m_queue.Pop();
            char timeBuf[128] = {0};
            sprintf(timeBuf, "%02d:%02d:%02d => ", nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec);
            fout << timeBuf << msg << std::endl;
            fout.close();
        }
    });
    // 设置分离线程（相当于守护线程）
    writeLogTask.detach();
}

// 设置日志级别
void Logger::SetLogLevel(LogLevel level)
{
    m_logLevel = level;
}

// 写日志，把日志信息写入LockQueue缓冲区中
void Logger::Log(const std::string &msg)
{
    m_queue.Push(msg);
}