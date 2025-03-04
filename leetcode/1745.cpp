#include "../template/head.h"
#include <bits/stdc++.h>

bool checkPartitioning(string s) {
    /* clang-format off */
    // 思路：DP + 模拟
    // 时间 O(n2)，空间 O(n2)

    // 一个 DP 用于判断是否是回文串，
    // 一个模拟分别枚举前两个串的结束位置，三个都回文就成立
    // 注：分割成 k 个回文，不一定能分割成 k - 1 个回文，也不一定能分割成 k + 1 个回文
    // 如 aba c d e f 能够分成 5 个回文，不能分成 4 或 6 个回文
    /* clang-format on */

    // 用于判断是否是回文串
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == 1) {
                dp[i - 1][j] = true;
            } else {
                int end = j + i - 1;
                if (end >= len) {
                    break;
                }
                dp[i - 1][j] = i == 2 && s[j] == s[end] ||
                               i > 2 && s[j] == s[end] && dp[i - 3][j + 1];
            }
        }
    }

    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            // 使用位置求长度
            // 0 => i, first = i - 0 + 1 - 1 = i
            // i + 1 => j, first = j - i - 1 + 1 - 1 = j - i - 1
            // j + 1 => len - 1, first = len - 1 - j - 1 + 1 - 1 = len - j - 2
            if (dp[i][0] && dp[j - i - 1][i + 1] && dp[len - j - 2][j + 1]) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // true
    cout << checkPartitioning("abcbdd") << endl;
    // false
    cout << checkPartitioning("bcbddxy") << endl;

    return 0;
}
