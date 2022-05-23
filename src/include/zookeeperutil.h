#ifndef ZOOKEEPERUTIL_H
#define ZOOKEEPERUTIL_H

#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>
#include <unordered_map>
#include <vector>

// 封装的zookeeper客户端类
class ZkClient {
public:
    ZkClient();
    ~ZkClient();

    // zkclient启动连接zkserver
    void Start();

    // 在zkserver上根据指定的path创建znode节点
    void Create(const char *path, const char *data, int datalen, int state=0);

    // 根据参数指定的znode节点路径，获取znode节点的值
    std::string GetData(const char *path);

    std::vector<std::string> GetNodes(const std::string &path);

    void Stop();
private:
    // zk的客户端句柄
    zhandle_t *m_zhandle;

    std::unordered_map<std::string, std::vector<std::string>> m_serviceNodesMap;

    std::vector<std::string> GetChildren(const char *path);

    static void ServiceWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);

    // 全局的watcher观察器   zkserver给zkclient的通知
    static void GlobalWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
};

#endif