#include "../template/head.h"
#include <bits/stdc++.h>

int orderOfLargestPlusSign(int n, vector<vector<int>> mines) {
    // 思路：模拟 + DP
    // 时间 O(n2)，空间 O(n2)
    // 上下左右中
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, {0, 0, 0, 0, 1}));
    for (auto &m : mines) {
        dp[m[0]][m[1]][4] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 上左
            if (dp[i][j][4] != 0) {
                if (i - 1 >= 0 && dp[i - 1][j][4] == 1) {
                    dp[i][j][0] = dp[i - 1][j][0] + 1;
                }
                if (j - 1 >= 0 && dp[i][j - 1][4] == 1) {
                    dp[i][j][2] = dp[i][j - 1][2] + 1;
                }
            }
            // 下
            int mi = n - i - 1;
            if (dp[mi][j][4] != 0) {
                if (mi + 1 < n && dp[mi + 1][j][4] == 1) {
                    dp[mi][j][1] = dp[mi + 1][j][1] + 1;
                }
            }

            // 右
            int mj = n - j - 1;
            if (dp[i][mj][4] != 0) {
                if (mj + 1 < n && dp[i][mj + 1][4] == 1) {
                    dp[i][mj][3] = dp[i][mj + 1][3] + 1;
                }
            }
        }
    }

    int maxv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j][4] == 0) {
                continue;
            }

            maxv = max(maxv, 1 + min(min(dp[i][j][0], dp[i][j][1]),
                                     min(dp[i][j][2], dp[i][j][3])));
        }
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << orderOfLargestPlusSign(5, {{4, 2}}) << endl;
    // 0
    cout << orderOfLargestPlusSign(1, {{0, 0}}) << endl;

    return 0;
}
