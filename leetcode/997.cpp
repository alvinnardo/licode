#include "../template/head.h"
#include <bits/stdc++.h>

int findJudge(int n, vector<vector<int>> trust) {
    // 思路：哈希表 + 模拟
    // 时间 O(m + n)，空间 O(n)
    vector<int> trusted_vec(n + 1), trust_vec(n + 1);
    for (auto &it : trust) {
        trust_vec[it[0]] = 1;
        trusted_vec[it[1]]++;
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (trust_vec[i] == 0 && trusted_vec[i] == n - 1) {
            if (res < 0) {
                res = i;
            } else {
                return -1;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findJudge(2, {{1, 2}}) << endl;
    // 3
    cout << findJudge(3, {{1, 3}, {2, 3}}) << endl;
    // -1
    cout << findJudge(3, {{1, 3}, {2, 3}, {3, 1}}) << endl;

    return 0;
}
