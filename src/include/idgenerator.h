#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include "noncopyable.h"
#include <string>
#include <ctime>

class IDGenerator : private Noncopyable {
public:
    static IDGenerator *getInstance() {
        static IDGenerator gen;
        return &gen;
    }
    uint64_t getUID(const std::string &info) {
        union {
            struct {
                uint64_t addID:16;
                uint64_t timestamp:32;
                uint64_t infoHash:15;
                uint64_t reserved:1;
            };
            uint64_t id;
        } idGen;

        uint32_t curSecond = time(nullptr);
        // 若秒数不同了，则自增ID重新从0开始
        if (curSecond != m_lastSecond) {
            m_lastSecond = curSecond;
            m_addID = 0;
        }
        idGen.reserved = 0;
        idGen.infoHash = std::hash<std::string>()(info);
        idGen.timestamp = curSecond;
        idGen.addID = m_addID++;
        return idGen.id;
    }
private:
    uint32_t m_lastSecond;  // 上次产生ID时的时间戳，单位：秒
    uint32_t m_addID;  // 自增ID
};

#endif