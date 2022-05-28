#ifndef LOGQUEUE_H
#define LOGQUEUE_H

#include <queue>
#include <thread>
#include <mutex> // pthread_mutex_t
#include <condition_variable> // pthread_cond_t
#include <iostream>

// 异步写日志的日志队列
template <typename T>
class LockQueue {
public:
    // 多个worker线程都会写日志queue
    void push(const T &data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_cond.notify_one();
    }

    // 一个线程读日志queue，写日志文件
    T pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        // while (m_queue.empty()) {
        //     // 日志队列为空，线程进入wait状态
        //     m_cond.wait(lock);
        // }

        T data = m_queue.front();
        m_queue.pop();
        return data;
    }

    size_t size() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    bool empty() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

#endif