#ifndef SEM_H
#define SEM_H

#include <semaphore.h>
#include <exception>

// 信号量类
class Semaphore {
public:
    Semaphore() : source(0) {
        init(0);
    }

    Semaphore(int num) : source(num) {
        init(num);
    }

    ~Semaphore() {
        destroy();
    }

    // 等待信号量
    bool wait() {
        return sem_wait(&m_sem) == 0;
    }

    // 增加信号量
    bool post() {
        return sem_post(&m_sem) == 0;
    }

    int getValue() {
        int val = 0;
        sem_getvalue(&m_sem, &val);
        return val;
    }

    void reset() {
        destroy();
        init(source);
    }
private:
    sem_t m_sem;
    int source;

    void init(int num = 0) {
        if (sem_init(&m_sem, 0, num) != 0) {
            throw std::exception();
        }
    }

    void destroy() {
        sem_destroy(&m_sem);
    }
};

#endif