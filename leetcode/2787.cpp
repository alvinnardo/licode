#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfWays(int n, int x) {
    // 思路：优化空间
    // 时间 O(kn)，空间 O(n)，k 是能使 p^x <= n 成立的 p 的个数

    vector<int> vec{0};
    int t = 1, p = 0;
    while (1) {
        p = pow(t, x);
        if (p > n) {
            break;
        }

        vec.push_back(p);
        t++;
    }

    // 只和两排数据有关，优化空间
    vector<int> dp(n + 1), dp2;

    const int mod = 1e9 + 7;
    dp[0] = 1;

    int up = 0;
    for (int i = 1; i < vec.size(); i++) {
        dp2 = dp;

        for (int j = 1; j <= n; j++) {
            up = j - vec[i] >= 0 ? dp2[j - vec[i]] : 0;
            dp[j] = ((long long)dp2[j] + up) % mod;
        }
    }

    return dp[n];
}

int numberOfWays1(int n, int x) {
    // 思路：0-1 背包
    // 时间 O(kn)，空间 O(kn)，k 是能使 p^x <= n 成立的 p 的个数

    vector<int> vec{0};
    int t = 1, p = 0;
    while (1) {
        p = pow(t, x);
        if (p > n) {
            break;
        }

        vec.push_back(p);
        t++;
    }

    // 定义 dp[i][j] 为 前 i 个数字，能组成 j 的个数
    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vec[i]]
    vector<vector<int>> dp(vec.size(), vector<int>(n + 1));

    const int mod = 1e9 + 7;
    for (int i = 0; i < vec.size(); i++) {
        // 用前 0 个数字组成 0，有 1 种方案
        // 因为定义为前几种的和，所以后面的值都是这 1 种方案
        dp[i][0] = 1;
    }

    int up = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < vec.size(); i++) {
            up = j - vec[i] >= 0 ? dp[i - 1][j - vec[i]] : 0;
            dp[i][j] = ((long long)dp[i - 1][j] + up) % mod;
        }
    }

    return dp[vec.size() - 1][n];
}

int main(int argc, char *argv[]) {
    // 1
    cout << numberOfWays(10, 2) << endl;
    // 2
    cout << numberOfWays(4, 1) << endl;

    return 0;
}
