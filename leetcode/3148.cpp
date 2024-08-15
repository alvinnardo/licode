#include "../template/head.h"
#include <bits/stdc++.h>

int maxScore(vector<vector<int>> grid) {
    // 思路：DP，注意到不管中间经历多少其它数，总能通过起始点和终止点找到位移
    // 所以找到左上角的最小值即可
    // 时间 O(mn)，空间 O(n)
    int m = grid.size(), n = grid[0].size();
    int res = INT_MIN;
    vector<int> dp(n, INT_MAX); // 优化用一行即可
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j - 1 >= 0) {
                dp[j] = min(dp[j], dp[j - 1]);
            }

            if (dp[j] != INT_MAX) {
                res = max(res, grid[i][j] - dp[j]);
            }
            dp[j] = min(dp[j], grid[i][j]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 9
    cout << maxScore({{9, 5, 7, 3}, {8, 9, 6, 1}, {6, 7, 14, 3}, {2, 5, 3, 1}})
         << endl;
    // -1
    cout << maxScore({{4, 3, 2}, {3, 2, 1}}) << endl;

    return 0;
}
