#include "../template/head.h"
#include <bits/stdc++.h>
#include <unordered_set>

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // 思路: 题解，DFS + 状压DP
    // 使用一个整数压缩状态，并保存在 DP 数组中，表示在当前状态下能否获胜
    // 如果某个状态没有访问过，就尝试遍历一下
    // 时间 O(n * 2^n)，空间 O(2^n)

    // 永远选不到
    if (desiredTotal == 0) {
        return true;
    }
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
        return false;
    }

    // 状压 DP，对于选与不选，则 n 个数共有 2^n 种状态
    vector<int> dp(1 << maxChoosableInteger, -1);

    auto bi2dec = [](int state) {
        int sum = 0;
        int start = 1;
        while (state) {
            if (state & 1) {
                sum += start;
            }
            start++;
            state >>= 1;
        }
        return sum;
    };

    function<int(int)> dfs = [&](int state) {
        if (dp[state] != -1) {
            return dp[state];
        }

        int res = 0;
        // 任意选一个没选过的数进行测试
        for (int i = 1 << (maxChoosableInteger - 1); i; i >>= 1) {
            if ((i & state) == 0) {
                int t = state + i;
                if (bi2dec(t) >= desiredTotal || dfs(t) == 0) {
                    res = 1;
                    break;
                }
            }
        }

        dp[state] = res;
        return dp[state];
    };

    return dfs(0); // 返回当前状态能否胜利
}

int main(int argc, char *argv[]) {
    // 1
    cout << canIWin(10, 0) << endl;
    // 1
    cout << canIWin(10, 1) << endl;
    // 0
    cout << canIWin(10, 11) << endl;
    // 1
    cout << canIWin(10, 12) << endl;
    // 1
    cout << canIWin(10, 21) << endl;
    // 0
    cout << canIWin(10, 22) << endl;
    // 1
    cout << canIWin(10, 23) << endl;
    // 1
    cout << canIWin(10, 24) << endl;
    // 0
    cout << canIWin(20, 300) << endl;
    // 0
    cout << canIWin(20, 210) << endl;

    return 0;
}
