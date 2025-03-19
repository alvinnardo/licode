#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> loudAndRich(vector<vector<int>> richer, vector<int> quiet) {
    // 题解：拓扑排序
    // 时间 O(m + n)，空间 O(m + n)

    int sz = quiet.size();
    vector<vector<int>> vec(sz);
    vector<int> up(sz);
    for (auto &r : richer) { // 有钱的保存没钱的
        vec[r[0]].push_back(r[1]);
        up[r[1]]++;
    }

    queue<int> qu;
    for (int i = 0; i < sz; i++) {
        if (up[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> res(sz);
    std::iota(res.begin(), res.end(), 0); // 先等于本身
    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();

        for (int v : vec[t]) { // 把最小的值往下推
            if (quiet[res[t]] < quiet[res[v]]) {
                res[v] = res[t];
            }

            if (--up[v] == 0) {
                qu.push(v);
            }
        }
    }

    return res;
}

vector<int> loudAndRich1(vector<vector<int>> richer, vector<int> quiet) {
    // 思路：DFS
    // 时间 O(n2)，空间 O(n2)
    // 优化空间 和 时间

    int sz = quiet.size();
    vector<vector<int>> vec(sz);
    vector<int> up(sz);
    for (auto &r : richer) {
        vec[r[1]].push_back(r[0]); // 保存比自己钱多的人
        up[r[0]] = 1; // 标记有比自己钱少的人，不能作为根节点
    }

    vector<vector<int>> tmp(sz, vector<int>(sz));
    vector<int> res(sz, -1);

    function<void(int)> dfs = [&](int pos) {
        if (res[pos] != -1) {
            return;
        }

        int minv = INT_MAX, min_pos = -1;
        for (int v : vec[pos]) {
            dfs(v);
            for (int i = 0; i < sz; i++) {
                if (tmp[v][i] && !tmp[pos][i]) {
                    tmp[pos][i] = 1;
                    if (quiet[i] < minv) {
                        minv = quiet[i];
                        min_pos = i;
                    }
                }
            }
        }

        tmp[pos][pos] = 1;
        if (quiet[pos] < minv) {
            minv = quiet[pos];
            min_pos = pos;
        }
        res[pos] = minv == INT_MAX ? pos : min_pos;
    };

    for (int i = 0; i < sz; i++) {
        if (up[i] == 0) { // 找到一个根节点
            dfs(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {5,5,2,5,4,5,6,7}
    printVector(
        loudAndRich({{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}},
                    {3, 2, 5, 4, 6, 1, 7, 0}));
    // {0}
    printVector(loudAndRich({}, {0}));

    return 0;
}
