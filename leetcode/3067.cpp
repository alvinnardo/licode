#include "../template/head.h"
#include <bits/stdc++.h>

// 第三次提交用父节点 替换 哈希表
// 时间 175 ms，减到 1/10
vector<int> countPairsOfConnectableServers(vector<vector<int>> edges,
                                           int signalSpeed) {
    // 思路：对每个点的每条边进行统计
    // 时间 O(n2)，空间 O(n2)，k 是某个点满足边的条数
    int n = edges.size() + 1;
    vector<int> res(n);
    vector<vector<pair<int, int>>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].push_back({edge[1], edge[2]});
        nei[edge[1]].push_back({edge[0], edge[2]});
    }

    function<int(pair<int, int> &, int, int)> dfs = [&](pair<int, int> &p,
                                                        int fa, int up) {
        int cur = up + p.second;
        int sum = 0;
        for (auto &it : nei[p.first]) {
            if (it.first == fa) {
                continue;
            }
            sum += dfs(it, p.first, cur);
        }

        return cur % signalSpeed == 0 ? sum + 1 : sum;
    };

    auto handle = [&](int i) {
        // 乘法定理优化：之前的总和 * 当前数
        int pre = 0, sum = 0;
        for (auto &it : nei[i]) {
            int r = dfs(it, i, 0); // 只需要不选父节点即可
            if (r > 0) {
                sum += r * pre;
                pre += r;
            }
        }

        return sum;
    };

    for (int i = 0; i < n; i++) {
        if (nei[i].size() <= 1) {
            continue;
        }

        res[i] = handle(i);
    }

    return res;
}

// 第二次优化了乘法原理
// 时间 1787 ms
vector<int> countPairsOfConnectableServers2(vector<vector<int>> &edges,
                                            int signalSpeed) {
    // 思路：对每个点的每条边进行统计
    // 时间 O(n2)，空间 O(kn2)，k 是某个点满足边的条数
    int n = edges.size() + 1;
    vector<int> res(n);
    vector<vector<pair<int, int>>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].push_back({edge[1], edge[2]});
        nei[edge[1]].push_back({edge[0], edge[2]});
    }

    function<int(pair<int, int> &, unordered_set<int> &, int)> dfs =
        [&](pair<int, int> &p, unordered_set<int> &uset, int up) {
            uset.insert(p.first);

            int cur = up + p.second;
            int sum = 0;
            for (auto &it : nei[p.first]) {
                if (uset.count(it.first)) {
                    continue;
                }
                sum += dfs(it, uset, cur);
            }
            uset.erase(p.first);

            return cur % signalSpeed == 0 ? sum + 1 : sum;
        };

    auto handle = [&](int i) {
        // 乘法定理优化：之前的总和 * 当前数
        int pre = 0, sum = 0;
        for (auto &it : nei[i]) {
            unordered_set<int> uset;
            uset.insert(i);
            int r = dfs(it, uset, 0);
            if (r > 0) {
                sum += r * pre;
                pre += r;
            }
        }

        return sum;
    };

    for (int i = 0; i < n; i++) {
        if (nei[i].size() <= 1) {
            continue;
        }

        res[i] = handle(i);
    }

    return res;
}

// 第一次提交，时间 1676 ms
vector<int> countPairsOfConnectableServers1(vector<vector<int>> &edges,
                                            int signalSpeed) {
    // 思路：对每个点的每条边进行统计
    // 时间 O(k2n2)，空间 O(kn2)，k 是某个点满足边的条数
    int n = edges.size() + 1;
    vector<int> res(n);
    vector<vector<pair<int, int>>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].push_back({edge[1], edge[2]});
        nei[edge[1]].push_back({edge[0], edge[2]});
    }

    function<int(pair<int, int> &, unordered_set<int> &, int)> dfs =
        [&](pair<int, int> &p, unordered_set<int> &uset, int up) {
            uset.insert(p.first);

            int cur = up + p.second;
            int sum = 0;
            for (auto &it : nei[p.first]) {
                if (uset.count(it.first)) {
                    continue;
                }
                sum += dfs(it, uset, cur);
            }
            uset.erase(p.first);

            return cur % signalSpeed == 0 ? sum + 1 : sum;
        };

    auto handle = [&](int i) {
        vector<int> tmp;
        for (auto &it : nei[i]) {
            unordered_set<int> uset;
            uset.insert(i);
            int r = dfs(it, uset, 0);
            if (r > 0) {
                tmp.push_back(r);
            }
        }

        int sum = 0;
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = i + 1; j < tmp.size(); j++) {
                sum += tmp[i] * tmp[j];
            }
        }

        return sum;
    };

    for (int i = 0; i < n; i++) {
        if (nei[i].size() <= 1) {
            continue;
        }

        res[i] = handle(i);
    }

    return res;
}
int main(int argc, char *argv[]) {
    // {0,4,6,6,4,0}
    printVector(countPairsOfConnectableServers(
        {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}}, 1));
    // {2,0,0,0,0,0,2}
    printVector(countPairsOfConnectableServers(
        {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}}, 3));

    return 0;
}
