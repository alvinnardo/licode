#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfPaths(vector<vector<int>> &&grid, int k) {
    // 思路：DP
    // 时间 O(mnp)，空间 O(mnp)
    int m = grid.size(), n = grid[0].size(), p = 51;
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(p)));

    const int mod = 1e9 + 7;
    auto handle = [&](const auto &from, auto &to, int val) {
        int t{};
        for (int i = 0; i < from.size(); i++) {
            if (from[i]) {
                t = (i + val % k) % k;
                to[t] = ((long long)to[t] + from[i]) % mod;
            }
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                ++dp[i][j][grid[i][j] % k];
            } else if (i == 0) { // 行
                handle(dp[i][j - 1], dp[i][j], grid[i][j]);
            } else if (j == 0) { // 列
                handle(dp[i - 1][j], dp[i][j], grid[i][j]);
            } else { // 行 + 列
                handle(dp[i][j - 1], dp[i][j], grid[i][j]);
                handle(dp[i - 1][j], dp[i][j], grid[i][j]);
            }
        }
    }

    return dp[m - 1][n - 1][0];
}

int main(int argc, char *argv[]) {
    // 2
    cout << numberOfPaths({{5, 2, 4}, {3, 0, 5}, {0, 7, 2}}, 3) << endl;
    // 1
    cout << numberOfPaths({{0, 0}}, 5) << endl;
    // 10
    cout << numberOfPaths({{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}}, 1)
         << endl;

    return 0;
}
