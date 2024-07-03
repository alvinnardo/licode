#include "../template/head.h"
#include <bits/stdc++.h>

int numTilings(int n) {
    // 思路：对状态转换的方法进行空间优化
    // 时间 O(n)，空间 O(1)

    const int mod = 1e9 + 7;
    vector<int> col1{0, 0, 0}, col2{1, 0, 0};
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        long long t = i >= 1 ? col1[0] : 0;
        a = (t + col2[0] + col2[1] + col2[2]) % mod;
        b = (t + col2[2]) % mod;
        c = (t + col2[1]) % mod;
        col1 = col2;
        col2 = {a, b, c};
    }

    return col2[0];
}

int numTilings2(int n) {
    // 思路：状态转换，总结出来三种状态
    // 时间 O(n)，空间 O(n)
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[0][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        dp[i][0] =
            ((long long)dp[i][0] + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) %
            mod;
        dp[i][1] = ((long long)dp[i][1] + dp[i - 1][2]) % mod;
        dp[i][2] = ((long long)dp[i][2] + dp[i - 1][1]) % mod;
        if (i - 2 >= 0) {
            dp[i][0] = ((long long)dp[i][0] + dp[i - 2][0]) % mod;
            dp[i][1] = ((long long)dp[i][1] + dp[i - 2][0]) % mod;
            dp[i][2] = ((long long)dp[i][2] + dp[i - 2][0]) % mod;
        }
    }

    return dp[n][0];
}

int numTilings1(int n) {
    // 思路：DP
    // 时间 O(n2)，空间 O(n2)
    int sz = n + 1;
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(sz, vector<int>(sz));
    dp[0][0] = 1;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            long long t = dp[i][j];
            if (i == j) {
                // 当两行结尾相等时
                // 可以放 [1, 1],[2, 0], [1, 2], [2, 1]
                if (i + 1 < sz) {
                    if (j + 1 < sz) {
                        dp[i + 1][j + 1] = (t + dp[i + 1][j + 1]) % mod;
                    }
                    if (j + 2 < sz) {
                        dp[i + 1][j + 2] = (t + dp[i + 1][j + 2]) % mod;
                    }
                }
                if (i + 2 < sz) {
                    dp[i + 2][j] = (t + dp[i + 2][j]) % mod;
                    if (j + 1 < sz) {
                        dp[i + 2][j + 1] = (t + dp[i + 2][j + 1]) % mod;
                    }
                }
            } else if (i - j == 2) {
                // 当结尾是 [2, 0] 时，只能放 [0, 2]
                if (j + 2 < sz) {
                    dp[i][j + 2] = (t + dp[i][j + 2]) % mod;
                }
            } else if (i - j == 1) {
                // 当结尾是 [2, 1] 时，可以放 [0, 2] 和 [1, 2]
                if (j + 2 < sz) {
                    dp[i][j + 2] = (t + dp[i][j + 2]) % mod;
                    if (i + 1 < sz) {
                        dp[i + 1][j + 2] = (t + dp[i + 1][j + 2]) % mod;
                    }
                }
            } else if (j - i == 1) {
                // 当结尾是 [1, 2] 时，可以放 [2, 0] 和 [2, 1]
                if (i + 2 < sz) {
                    dp[i + 2][j] = (t + dp[i + 2][j]) % mod;
                    if (j + 1 < sz) {
                        dp[i + 2][j + 1] += (t + dp[i + 2][j + 1]) % mod;
                    }
                }
            }
        }
    }

    return dp[n][n];
}

int main(int argc, char *argv[]) {
    // 5
    cout << numTilings(3) << endl;
    // 1
    cout << numTilings(1) << endl;
    // 3418626
    cout << numTilings(20) << endl;
    // 2
    cout << numTilings(2) << endl;
    // 11
    cout << numTilings(4) << endl;
    // 24
    cout << numTilings(5) << endl;
    // 53
    cout << numTilings(6) << endl;
    // 1255
    cout << numTilings(10) << endl;
    // 979232805
    cout << numTilings(1000) << endl;

    return 0;
}
