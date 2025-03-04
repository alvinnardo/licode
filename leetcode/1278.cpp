#include "../template/head.h"
#include <bits/stdc++.h>

// 两个 DP 的方法留给下一次遇到吧，分割的那部分用 DP 没绕过弯来
int palindromePartition(string s, int k) {
    // 思路：记忆化搜索 DFS + DP
    // 时间 O(n2k)，空间 O(n2k)
    // 之前考虑过枚举左节点进行 DFS 的方式，但对于分割出来的右边字符串，k
    // 值是否等于 1 有疑问 min{min{bng, end, k} + 右}
    if (s.length() == k) {
        return 0;
    }

    int len = s.length();

    // 给定一个字符串，将其改为回文串，最少需要改几步
    // 每次都算用时太多，用 DP 处理一下
    // 和判断是否为回文串类似
    vector<vector<int>> dp(len, vector<int>(len, INT_MAX));

    // 如果两边相同看中间
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == 1) { // 长度为 1，不需要替换
                dp[i - 1][j] = 0;
            } else {
                int end = j + i - 1;
                if (end >= len) {
                    break;
                }

                // 长度为 2，直接比较最两边
                // 长度大于 2，比较最两边并加上中间
                dp[i - 1][j] = i == 2 ? (s[j] != s[end])
                                      : dp[i - 3][j + 1] + (s[j] != s[end]);
            }
        }
    }

    // 每次拆一个，分解问题的时候经常都是每次拆一个，能覆盖所有的结果
    vector<vector<vector<int>>> mem(
        len + 1, vector<vector<int>>(len + 1, vector<int>(k + 1, -1)));
    function<int(int, int, int)> dfs = [&](int bng, int end, int tt) {
        if (tt == 1) {
            // end - bng + 1 - 1
            return dp[end - bng][bng];
        }

        if (mem[bng][end][tt] != -1) {
            return mem[bng][end][tt];
        }

        int res = INT_MAX;
        // 前面留 tt - 1 个
        for (int i = bng + tt - 1; i <= end; i++) {
            res = min(res, dfs(bng, i - 1, tt - 1) + dp[end - i][i]);
        }

        mem[bng][end][tt] = res;
        return res;
    };

    return dfs(0, len - 1, k);
}

int main(int argc, char *argv[]) {
    // 1
    cout << palindromePartition("abc", 2) << endl;
    // 0
    cout << palindromePartition("aabbc", 3) << endl;
    // 0
    cout << palindromePartition("abcdefgh", 8) << endl;

    return 0;
}
