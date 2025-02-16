#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> edges) {
    // 思路：哈希表
    // 首先是连通的，则找到没有入边的点
    // 时间 O(n)，空间 O(n)
    // 优化
    vector<int> vec(n), res;
    for (auto &edge : edges) {
        vec[edge[1]] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!vec[i]) {
            res.push_back(i);
        }
    }

    return res;
}

vector<int> findSmallestSetOfVertices1(int n, vector<vector<int>> edges) {
    // 思路：哈希表
    // 首先是连通的，则找到没有入边的点
    // 时间 O(n)，空间 O(n)
    unordered_set<int> uset1, uset2;
    for (auto &edge : edges) {
        uset1.insert(edge[1]);
    }

    for (auto &edge : edges) {
        if (!uset1.count(edge[0]) && !uset2.count(edge[0])) {
            uset2.insert(edge[0]);
        }
    }

    return vector<int>(uset2.begin(), uset2.end());
}

int main(int argc, char *argv[]) {
    // {0,3}
    printVector(
        findSmallestSetOfVertices(6, {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}}));
    // {0,2,3}
    printVector(
        findSmallestSetOfVertices(5, {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}}));

    return 0;
}
