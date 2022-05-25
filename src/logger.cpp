#include "logger.h"
#include <ctime>
#include <sys/stat.h>

// 获取日志的单例
Logger *Logger::GetInstance()
{
    static Logger logger;
    return &logger;
}

Logger::Logger() : m_running(false)
{
    Start();
}

void Logger::Start()
{
    if (this->m_running)
        return;
    this->m_running = true;
    int ret = mkdir("logs/", 0777);
    if (ret == -1) {
        if (errno != EEXIST)
            exit(EXIT_FAILURE);
    }

    // 启动专门的写日志线程
    std::thread writeLogTask(std::bind(&Logger::WriteLog, this));
    // 设置分离线程（相当于守护线程）
    writeLogTask.detach();
}

void Logger::WriteLog()
{
    while (m_running) {
        DoLog();
    }

    // 准备退出程序，但是还要把队列中剩余的日志写入到文件中
    while (!m_queue.Empty()) {
        DoLog();
    }
}

void Logger::DoLog()
{
    // 获取当天的日期，然后取日志信息，写入相应的日志文件中
    time_t now = time(nullptr);
    tm *nowtm = localtime(&now);

    char fileName[128] = {0};
    sprintf(fileName, "logs/%04d-%02d-%02d-log.log", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

    std::ofstream fout(fileName, std::ios::app);
    if (!fout.is_open()) {
        perror("open log file error");
        exit(EXIT_FAILURE);
    }

    if (m_queue.Empty()) {
        fout.close();
        return;
    }
    std::string msg = m_queue.Pop();
    fout << msg << std::endl;
    fout.close();
}

// 写日志，把日志信息写入LockQueue缓冲区中
void Logger::Log(LogLevel level, const std::string &msg)
{
    time_t now = time(nullptr);
    tm *nowtm = localtime(&now);
    char timeBuf[128] = {0};
    sprintf(timeBuf, "%04d-%02d-%02d %02d:%02d:%02d => ", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday, 
        nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec);
    std::string log = timeBuf;
    switch (level) {
        case DEBUG:
            log += "[DEBUG] ";
            break;
        case INFO:
            log += "[INFO] ";
            break;
        case WARN:
            log += "[WARN] ";
            break;
        case ERROR:
            log += "[ERROR] ";
            break;
        case FATAL:
            log += "[FATAL] ";
            break;
    }
    log += msg;
    m_queue.Push(log);
}