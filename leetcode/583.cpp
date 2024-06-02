#include "../template/head.h"
#include <bits/stdc++.h>

int minDistance(string word1, string word2) {
    // 思路：DP，先求最长公共子序列
    // 时间 O(mn)，空间 O(mn)
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (word1[i] == word2[j]) {
                dp[i + 1][j + 1] =
                    max(dp[i][j] + 1, max(dp[i][j + 1], dp[i + 1][j]));
            } else {
                dp[i + 1][j + 1] =
                    max(dp[i][j], max(dp[i][j + 1], dp[i + 1][j]));
            }
        }
    }

    return m + n - dp[m][n] * 2;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minDistance("sea", "eat") << endl;
    // 4
    cout << minDistance("leetcode", "etco") << endl;
    // 2
    cout << minDistance("aaaaaaaaaa", "eaaaaaaaaaae") << endl;

    return 0;
}
