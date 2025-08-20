#include "../template/head.h"
#include <bits/stdc++.h>
int countSquares(vector<vector<int>> &&matrix) {
    // 优化空间
    // 时间 O(mn)，空间 O(n)

    // 只留一行
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp1(n, vector<int>(3)), tmp;

    int res{};
    for (int i = 0; i < m; i++) {
        tmp = dp1;

        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                dp1[j] = {0, 0, 0};
                continue;
            }
            if (i == 0 && j == 0) {
                dp1[j] = {1, 1, 1};
            } else if (i == 0) {
                dp1[j] = {dp1[j - 1][0] + 1, 1, 1};
            } else if (j == 0) {
                dp1[j] = {1, tmp[j][1] + 1, 1};
            } else {
                dp1[j][0] = dp1[j - 1][0] + 1;
                dp1[j][1] = tmp[j][1] + 1;
                dp1[j][2] = min({tmp[j - 1][2] + 1, dp1[j][0], dp1[j][1]});
            }
            res += dp1[j][2];
        }
    }
    return res;
}

int countSquares1(vector<vector<int>> &&matrix) {
    // 思路：DP
    // 时间 O(mn)，空间 O(mn)

    // 计算每个点能成立的最大值
    // min{从左到右连续, 从顶向下连续，左斜上方的个数}
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3)));

    int res{};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = {1, 1, 1};
            } else if (i == 0) {
                dp[i][j] = {dp[i][j - 1][0] + 1, 1, 1};
            } else if (j == 0) {
                dp[i][j] = {1, dp[i - 1][j][1] + 1, 1};
            } else {
                dp[i][j][0] = dp[i][j - 1][0] + 1;
                dp[i][j][1] = dp[i - 1][j][1] + 1;
                dp[i][j][2] =
                    min({dp[i - 1][j - 1][2] + 1, dp[i][j][0], dp[i][j][1]});
            }
            res += dp[i][j][2];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 15
    cout << countSquares({{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}) << endl;
    // 7
    cout << countSquares({{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}) << endl;

    return 0;
}
