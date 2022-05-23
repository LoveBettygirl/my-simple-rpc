#include "zookeeperutil.h"
#include "rpcapplication.h"
#include "logger.h"

// 全局的watcher观察器   zkserver给zkclient的通知
void ZkClient::GlobalWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
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
    Stop();
}

// zkclient启动连接zkserver
void ZkClient::Start()
{
    std::string host = RpcApplication::GetInstance().GetConfig().Load("zookeeper_ip");
    std::string port = RpcApplication::GetInstance().GetConfig().Load("zookeeper_port");
    std::string connstr = host + ":" + port;

    /*
    zookeeper_mt：多线程版本
    zookeeper的API客户端程序提供了三个线程
    API调用线程 （当前线程）
    网络I/O线程  pthread_create  poll
    watcher回调线程 pthread_create 给客户端通知
    */
    // 这是异步的连接
    m_zhandle = zookeeper_init(connstr.c_str(), GlobalWatcher, 30000, nullptr, nullptr, 0);
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

void ZkClient::Stop()
{
    if (m_zhandle != nullptr) {
        zookeeper_close(m_zhandle); // 关闭句柄，释放资源  MySQL_Conn
        m_zhandle = nullptr;
    }
}

// 在zkserver上根据指定的path创建znode节点
// state: 表示永久性节点还是临时性节点，0是永久性节点。永久性节点的ephemeralOwner为0
void ZkClient::Create(const char *path, const char *data, int datalen, int state)
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

// 根据指定的path，获取znode节点的值
std::string ZkClient::GetData(const char *path)
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

std::vector<std::string> ZkClient::GetNodes(const std::string &path)
{
    auto it = m_serviceNodesMap.find(path);
    if (m_serviceNodesMap.find(path) != m_serviceNodesMap.end())
        return it->second;
    std::vector<std::string> result = GetChildren(path.c_str());
    m_serviceNodesMap[path] = result;
    return result;
}

std::vector<std::string> ZkClient::GetChildren(const char *path)
{
    struct String_vector node_vec;
    int flag = zoo_wget_children(m_zhandle, path, ServiceWatcher, nullptr, &node_vec);
    zoo_set_context(m_zhandle, this);
    if (flag != ZOK) {
        LOG_ERROR("get znode children error... path: %s", path);
        return std::vector<std::string>();
    }
    int size = node_vec.count;
    std::vector<std::string> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(node_vec.data[i]);
    }
    return result;
}

void ZkClient::ServiceWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    ZkClient *instance = (ZkClient *)zoo_get_context(zh);
    if (type == ZOO_CHILD_EVENT) {
        std::vector<std::string> result = instance->GetChildren(path);
        instance->m_serviceNodesMap[path] = result;
    }
}