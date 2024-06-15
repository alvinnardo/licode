#include "../template/head.h"
#include <bits/stdc++.h>

double knightProbability(int n, int k, int row, int column) {
    // 思路：DP，每步是一个维度
    // 时间 O(n2k)，空间 O(n2k)
    vector<vector<vector<double>>> dp(
        k + 1, vector<vector<double>>(n, vector<double>(n, 1)));

    vector<pair<int, int>> pos_vec{{-1, 2}, {1, 2},  {-2, 1},  {-2, -1},
                                   {2, 1},  {2, -1}, {-1, -2}, {1, -2}};
    for (int step = 1; step <= k; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double res = 0;
                for (auto &pos : pos_vec) {
                    int newi = i + pos.first, newj = j + pos.second;
                    if (newi >= 0 && newi < n && newj >= 0 && newj < n) {
                        res += 0.125 * dp[step - 1][newi][newj];
                    }
                }
                dp[step][i][j] = res;
            }
        }
    }

    return dp[k][row][column];
}

int main(int argc, char *argv[]) {
    // 0.0625
    cout << knightProbability(3, 2, 0, 0) << endl;
    // 1.00000
    cout << knightProbability(1, 0, 0, 0) << endl;

    return 0;
}
