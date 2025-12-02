#include "../template/head.h"
#include <bits/stdc++.h>

int countTrapezoids(vector<vector<int>> &&points) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(k)，k 是不同纵坐标个数
    // 题目给出两两不同
    unordered_map<int, long long> umap;
    int sz = points.size();
    for (int i = 0; i < sz; i++) {
        ++umap[points[i][1]];
    }

    vector<long long> vec;
    long long t{};
    for (auto &p : umap) {
        if (p.second > 1) {
            t = (p.second * (p.second - 1)) >> 1;
            vec.push_back(t);
        }
    }

    const int mod = 1e9 + 7;
    long long res{}, pre{};
    for (int i = 0; i < vec.size(); i++) {
        res = (res + ((long long)vec[i] * pre) % mod) % mod;
        pre += vec[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countTrapezoids({{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}}) << endl;
    // 1
    cout << countTrapezoids({{0, 0}, {1, 0}, {0, 1}, {2, 1}}) << endl;

    return 0;
}
