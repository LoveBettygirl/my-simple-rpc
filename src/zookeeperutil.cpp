#include "zookeeperutil.h"
#include "rpcconfig.h"
#include "logger.h"

// 全局的watcher观察器   zkserver给zkclient的通知
void ZkClient::globalWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    if (type == ZOO_SESSION_EVENT) { // 回调的消息类型是和会话相关的消息类型
        if (state == ZOO_CONNECTED_STATE) { // zkclient和zkserver连接成功
            sem_t *sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem); // 连接成功
        }
    }
}

ZkClient::ZkClient() : m_zhandle(nullptr) {}

ZkClient::~ZkClient()
{
    stop();
}

// zkclient启动连接zkserver
void ZkClient::start()
{
    std::string host = RpcConfig::getInstance()->load("zookeeper.ip");
    std::string port = RpcConfig::getInstance()->load("zookeeper.port");
    std::string connstr = host + ":" + port;

    /*
    zookeeper_mt：多线程版本
    zookeeper的API客户端程序提供了三个线程
    API调用线程 （当前线程）
    网络I/O线程  pthread_create  poll
    watcher回调线程 pthread_create 给客户端通知
    */
    // 这是异步的连接
    int timeout = std::stoi(RpcConfig::getInstance()->load("zookeeper.timeout"));
    m_zhandle = zookeeper_init(connstr.c_str(), globalWatcher, timeout, nullptr, nullptr, 0);
    // 返回表示句柄创建成功，不代表连接成功了
    if (nullptr == m_zhandle) {
        LOG_ERROR("zookeeper_init error!");
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle, &sem);

    sem_wait(&sem); // 等待连接
    LOG_INFO("zookeeper_init success!");
}

// 断开zkclient与zkserver的连接
void ZkClient::stop()
{
    if (m_zhandle != nullptr) {
        zookeeper_close(m_zhandle); // 关闭句柄，释放资源  MySQL_Conn
        m_zhandle = nullptr;
        LOG_INFO("zookeeper connection close success!");
    }
}

// 在zkserver上根据指定的path创建znode节点
// state: 表示永久性节点还是临时性节点，0是永久性节点。永久性节点的ephemeralOwner为0
void ZkClient::create(const char *path, const char *data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
    // 先判断path表示的znode节点是否存在，如果存在，就不再重复创建了
    flag = zoo_exists(m_zhandle, path, 0, nullptr); // 同步的判断
    if (ZNONODE == flag) { // 表示path的znode节点不存在
        // 创建指定path的znode节点了
        flag = zoo_create(m_zhandle, path, data, datalen,
            &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen); // 也是同步的
        if (flag == ZOK) {
            LOG_INFO("znode create success... path: %s", path);
        }
        else {
            LOG_ERROR("flag: %d", flag);
            LOG_ERROR("znode create error... path: %s", path);
            exit(EXIT_FAILURE);
        }
    }
}

// 删除节点
void ZkClient::deleteNode(const char *path)
{
    int flag;
    // 先判断path表示的znode节点是否存在，如果不存在，就不再重复删除
    flag = zoo_exists(m_zhandle, path, 0, nullptr); // 同步的判断
    if (ZNONODE != flag) { // 表示path的znode节点不存在
        flag = zoo_delete(m_zhandle, path, -1); // 也是同步的
        if (flag == ZOK) {
            LOG_INFO("znode delete success... path: %s", path);
        }
        else {
            LOG_ERROR("flag: %d", flag);
            LOG_ERROR("znode delete error... path: %s", path);
        }
    }
}

// 根据指定的path，获取znode节点的值
std::string ZkClient::getData(const char *path)
{
    char buffer[64];
    int bufferlen = sizeof(buffer);
    // 以同步的方式获取znode节点的值
    int flag = zoo_get(m_zhandle, path, 0, buffer, &bufferlen, nullptr);
    if (flag != ZOK) {
        LOG_ERROR("get znode error... path: %s", path);
        return "";
    }
    return buffer;
}

// 获取路径对应的子节点
std::vector<std::string> ZkClient::getChildrenNodes(const std::string &path)
{
    auto it = m_childrenNodesMap.find(path);
    if (m_childrenNodesMap.find(path) != m_childrenNodesMap.end())
        return it->second;
    std::vector<std::string> result = getChildren(path.c_str());
    m_childrenNodesMap[path] = result;
    return result;
}

// 根据参数指定的znode节点路径，获取znode节点的子节点
std::vector<std::string> ZkClient::getChildren(const char *path)
{
    struct String_vector node_vec;
    int flag = zoo_wget_children(m_zhandle, path, serviceWatcher, nullptr, &node_vec);
    zoo_set_context(m_zhandle, this);
    std::vector<std::string> result;
    if (flag != ZOK) {
        LOG_ERROR("get znode children error... path: %s", path);
    }
    else {
        int size = node_vec.count;
        for (int i = 0; i < size; ++i) {
            result.push_back(node_vec.data[i]);
        }
        deallocate_String_vector(&node_vec);
    }
    return result;
}

void ZkClient::serviceWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    ZkClient *instance = (ZkClient *)zoo_get_context(zh);
    if (type == ZOO_CHILD_EVENT) {
        // zk设置监听watcher只能是一次性的，每次触发后需要重复设置
        std::vector<std::string> result = instance->getChildren(path);
        instance->m_childrenNodesMap[path] = result;
    }
}

// 关闭控制台日志输出（只输出错误的）
void ZkClient::closeLog()
{
    zoo_set_debug_level(ZOO_LOG_LEVEL_ERROR);
}

// 心跳机制
void ZkClient::sendHeartBeat()
{
    std::thread t([&]() {
        while (true) {
            int time = zoo_recv_timeout(m_zhandle) * 1.0 / 3; // 默认timeout 30000
            std::this_thread::sleep_for(std::chrono::seconds(time));
            zoo_exists(m_zhandle, ROOT_PATH, 0, nullptr);
        }
    });
    t.detach();
}