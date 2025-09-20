#include "../template/head.h"
#include <bits/stdc++.h>

/**
  分析：队列的先入先出
  如何检测同一时间戳下有相同的数据包，哈希表就顺序乱了
  获取时间戳在一定范围内，dest 的个数

  这里有一个重要的条件，时间戳是非递减的，
  所以可以不需要红黑树自动排序，vector 即可

  1. 需要一个队列
  2. 使用哈希表存放 dest 的内容，<dest, deque>，
     时间戳用双向队列存放，因为其能二分查找，迭代器也可以相减
     (还有一个思路是不删除，添加一个哈希表记录可用位置)
  3. 相同时刻的重复包，不一定是顺序的，使用哈希表存放，用来找重复包
*/

// 思路：哈希表 + 队列
// 时间 O(klogn)，空间 O(n)
class Router {
  public:
    int m_memory_limit{};
    queue<vector<int>> m_qu;
    unordered_map<int, deque<int>> m_dest_umap;

    int m_dup_uset_time{INT_MIN};
    unordered_set<long long> m_dup_uset;

    Router(int memoryLimit) : m_memory_limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        // 时间 O(1)
        // 先检查是否有冲突
        long long t = (long long)source * 1e6 + destination;
        if (m_dup_uset_time == timestamp && !m_dup_uset.empty() &&
            m_dup_uset.count(t)) {
            return false;
        }

        // 再检查缓冲区是否满了
        if (m_qu.size() == m_memory_limit) {
            forwardPacket(); // 删除一个包
        }

        m_qu.push({source, destination, timestamp}); // 插入队列
        if (m_dup_uset_time != timestamp) {          // 插入同时刻队列
            m_dup_uset.clear();
            m_dup_uset_time = timestamp;
        }
        m_dup_uset.insert(t);

        m_dest_umap[destination].push_back(timestamp); // 插入 dest 哈希表
        return true;
    }

    vector<int> forwardPacket() {
        if (m_qu.empty()) { // 没有缓存则返回空
            return {};
        }

        // 时间 O(1)
        auto f = m_qu.front();
        m_qu.pop(); // 从队列中删除

        m_dest_umap[f[1]].pop_front(); // 从 dest 哈希表中删除
        if (m_dest_umap[f[1]].empty()) {
            m_dest_umap.erase(f[1]);
        }

        if (m_dup_uset_time == f[2]) { // 从重复队列中删除
            auto t = (long long)f[0] * 1e6 + f[1];
            m_dup_uset.erase(t);
        }

        return f;
    }

    int getCount(int destination, int startTime, int endTime) {
        // 时间 O(logn)
        if (!m_dest_umap.contains(destination)) {
            return 0;
        }

        // 这里找了半个多小时问题，老是超时，把能优化的都优化了
        // 最后发现这里忘记引用了。。。
        auto &range = m_dest_umap[destination];
        auto it_bng = std::lower_bound(range.begin(), range.end(), startTime);
        auto it_end = std::upper_bound(range.begin(), range.end(), endTime);

        return it_end - it_bng; // (it_end - 1) - it_bng + 1
    }
};

int main(int argc, char *argv[]) {

    Router router(3);
    cout << router.addPacket(1, 4, 90) << endl;   // 1
    cout << router.addPacket(2, 5, 90) << endl;   // 1
    cout << router.addPacket(1, 4, 90) << endl;   // 0
    cout << router.addPacket(3, 5, 95) << endl;   // 1
    cout << router.addPacket(4, 5, 105) << endl;  // 1
    cout << router.forwardPacket() << endl;       // {2, 5, 90}
    cout << router.addPacket(5, 2, 110) << endl;  // 1
    cout << router.getCount(5, 100, 110) << endl; // 1

    router = Router(2);
    cout << router.addPacket(7, 4, 90) << endl; // 1
    cout << router.forwardPacket() << endl;     // {7, 4, 90}
    cout << router.forwardPacket() << endl;     // {}

    return 0;
}
