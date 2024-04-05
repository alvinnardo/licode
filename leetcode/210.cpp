#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    // BFS 拓扑排序
    vector<vector<int>> edges(numCourses);
    vector<int> du(numCourses);

    for (auto &pre : prerequisites) {
        edges[pre[1]].push_back(pre[0]);
        du[pre[0]]++; // 入度
    }

    queue<int> qu;
    for (int i = 0; i < numCourses; i++) {
        if (du[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> res;
    while (!qu.empty()) {
        auto t = qu.front();
        qu.pop();
        res.push_back(t);

        for (auto &c : edges[t]) {
            if (--du[c] == 0) {
                qu.push(c);
            }
        }
    }

    if (res.size() != numCourses) {
        res.clear();
    }
    return res;
}

vector<int> findOrder_my(int numCourses, vector<vector<int>> prerequisites) {
    if (numCourses == 0) {
        return {};
    }
    vector<vector<int>> pres(numCourses);
    vector<vector<int>> next(numCourses);
    for (auto &p : prerequisites) {
        pres[p[0]].push_back(p[1]);
        next[p[1]].push_back(p[0]);
    }

    // 层序遍历
    queue<int> qu;
    for (int i = 0; i < numCourses; i++) {
        if (pres[i].empty()) {
            qu.push(i);
        }
    }
    if (qu.empty()) { // 有环
        return {};
    }

    unordered_set<int> seen;
    vector<int> res;

    while (!qu.empty()) {
        int cnt = qu.size();
        int a = cnt, b = 0;

        while (cnt--) {
            int t = qu.front();
            qu.pop();
            if (seen.find(t) != seen.end()) {
                continue;
            }

            bool can = true;
            for (auto &c : pres[t]) {
                // 前提没处理过
                if (seen.find(c) == seen.end()) {
                    can = false;
                    break;
                }
            }

            if (can) {
                res.push_back(t);
                seen.insert(t);
                for (auto &c : next[t]) {
                    if (seen.find(c) == seen.end()) {
                        qu.push(c);
                    }
                }
            } else {
                qu.push(t);
                b++;
            }
        }

        if (a == b) { // 卡住
            return {};
        }
    }

    if (res.size() != numCourses) {
        return {};
    }
    return res;
}

int main(void) {
    printVector(findOrder(2, {{1, 0}}));
    printVector(findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}));
    printVector(findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {3, 0}}));
    printVector(findOrder(0, {}));
    printVector(findOrder(3, {{0, 1}, {2, 1}}));
    printVector(findOrder(3, {{1, 0}, {1, 2}}));
    printVector(findOrder(4, {{3, 0}, {1, 3}, {0, 1}, {3, 2}}));
    printVector(findOrder(1, {}));
    return 0;
}
