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

    // 获取服务对应的节点
    std::vector<std::string> GetChildrenNodes(const std::string &path);

    // 断开zkclient与zkserver的连接
    void Stop();

    // 删除节点
    void Delete(const char *path);

    // 获取连接状态
    bool GetIsConnected() const { return m_zhandle; }

    // 关闭控制台日志输出（只输出错误的）
    void CloseLog();
private:
    // zk的客户端句柄
    zhandle_t *m_zhandle;

    // 缓存路径对应的子节点，这样就不用总是遍历文件系统了
    std::unordered_map<std::string, std::vector<std::string>> m_childrenNodesMap;

    // 根据参数指定的znode节点路径，获取znode节点的子节点
    std::vector<std::string> GetChildren(const char *path);

    // 获取子节点的watcher
    static void ServiceWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);

    // 全局的watcher观察器   zkserver给zkclient的通知
    static void GlobalWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
};

#endif