#include "../template/head.h"
#include <bits/stdc++.h>

class TaskManager {
    // 思路：哈希表 + 红黑树
    // 时间 O(klogn)，空间 O(k)

  public:
    // 哈希表 <taskId, <pri, userId>>
    unordered_map<int, pair<int, int>> umap;
    // 红黑树 <pri, <taskId>>
    // 优先级和任务号都是从大到小
    map<int, set<int, std::greater<int>>, std::greater<int>> mm;
    TaskManager(vector<vector<int>> &tasks) {
        for (auto &task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        umap[taskId] = {priority, userId};
        mm[priority].insert(taskId);
    }

    void edit(int taskId, int newPriority) {
        auto userId = umap[taskId].second;
        rmv(taskId);
        add(userId, taskId, newPriority);
    }

    void rmv(int taskId) {
        auto priority = umap[taskId].first;
        mm[priority].erase(taskId);
        if (mm[priority].empty()) {
            mm.erase(priority);
        }
    }

    int execTop() {
        if (mm.empty()) { // 没有任务
            return -1;
        }

        auto taskId = *mm.begin()->second.begin();
        rmv(taskId);

        return umap[taskId].second;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> vv{{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(vv);
    taskManager.add(4, 104, 5);
    taskManager.edit(102, 8);
    cout << taskManager.execTop() << endl;
    taskManager.rmv(101);
    taskManager.add(5, 105, 15);
    cout << taskManager.execTop() << endl;

    return 0;
}
