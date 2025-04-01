#include "../template/head.h"
#include <bits/stdc++.h>

long long mostPoints(vector<vector<int>> questions) {
    // 题解：DP
    // 时间 O(n)，空间 O(n)

    // 与我的思路不同，题解是从后到前遍历的
    // dp[i] = max(dp[i + 1], dp[i + questions[i][1]] + questions[i][0]

    int sz = questions.size();
    vector<long long> dp(sz);
    for (int i = sz - 1; i >= 0; i--) {
        int p = i + questions[i][1] + 1;

        // 不选当前的，和后面的分数相同
        // 选当前的，则后面冷冻期的不能选
        dp[i] = max((i + 1 < sz ? dp[i + 1] : 0),
                    (questions[i][0] + (p < sz ? dp[p] : 0)));
    }

    return dp[0];
}

long long mostPoints1(vector<vector<int>> questions) {
    // 思路：DP
    // 时间 O(n)，空间 O(n)

    int sz = questions.size();
    vector<long long> dp(sz); // 存放当前题起始的分数
    long long res = 0;
    for (int i = 0; i < sz; i++) {
        if (i + 1 < sz) { // 不选
            dp[i + 1] = max(dp[i + 1], dp[i]);
        } else {
            res = max(res, dp[i]);
        }

        int l = i + questions[i][1] + 1;
        if (l < sz) { // 选
            dp[l] = max(dp[l], dp[i] + questions[i][0]);
        } else {
            res = max(res, dp[i] + questions[i][0]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << mostPoints({{3, 2}, {4, 3}, {4, 4}, {2, 5}}) << endl;
    // 7
    cout << mostPoints({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}) << endl;

    return 0;
}
