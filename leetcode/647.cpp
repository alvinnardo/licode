#include "../template/head.h"
#include <bits/stdc++.h>

int countSubstrings(string s) {
    // 思路：DP
    // 时间 O(n2)，空间 O(n)
    // 优化时间
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));

    int sum = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = len - 1; i < n; i++) {
            int left = i + 1 - len;

            if (len == 1 || len == 2 && s[left] == s[i] ||
                s[left] == s[i] && dp[left + 1][i - 1]) {
                dp[left][i] = 1;
                sum++;
            }
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countSubstrings("abc") << endl;
    // 6
    cout << countSubstrings("aaa") << endl;

    return 0;
}
