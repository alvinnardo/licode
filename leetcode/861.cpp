#include "../template/head.h"
#include <bits/stdc++.h>

int matrixScore(vector<vector<int>> grid) {
    // 思路：贪心
    // 先保证行首是 1，然后处理列
    // 时间 O(mn)，空间 O(n)

    // 每次用贪心都很犹豫，想不到证明方法

    // 看了题解，可以先遍历列，就不用存了，直接算即可
    // 时间和空间都有优化，留给下次遇到时再写吧

    int m = grid.size(), n = grid[0].size();
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        bool turn = grid[i][0] == 0;
        for (int j = 0; j < n; j++) {
            if (!turn && grid[i][j] == 1 || turn && grid[i][j] == 0) {
                cnt[j]++;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] <= (m >> 1)) { // 小于等于一半，处理奇数层
            cnt[i] = m - cnt[i];
        }

        res += (1 << (n - i - 1)) * cnt[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 39
    cout << matrixScore({{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}}) << endl;
    // 1
    cout << matrixScore({{0}}) << endl;

    return 0;
}
