#include "../template/head.h"
#include <bits/stdc++.h>

int winningPlayerCount(int n, vector<vector<int>> pick) {
    // 思路：哈希表
    // 时间 O(m)，空间 O(n)
    vector<unordered_map<int, int>> vec(n);
    unordered_set<int> uset;
    for (auto &it : pick) {
        if (++vec[it[0]][it[1]] > it[0]) {
            uset.insert(it[0]);
        };
    }

    return uset.size();
}

int main(int argc, char *argv[]) {
    // 2
    cout << winningPlayerCount(4,
                               {{0, 0}, {1, 0}, {1, 0}, {2, 1}, {2, 1}, {2, 0}})
         << endl;
    // 0
    cout << winningPlayerCount(5, {{1, 1}, {1, 2}, {1, 3}, {1, 4}}) << endl;
    // 1
    cout << winningPlayerCount(5, {{1, 1}, {2, 4}, {2, 4}, {2, 4}}) << endl;

    return 0;
}
