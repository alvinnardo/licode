#include "../template/head.h"
#include <bits/stdc++.h>

int findTargetSumWays(vector<int> nums, int target) {
    // 思路：DP
    // 时间 O(2001n)，空间 O(2001n)
    int sz = nums.size();
    // 和的范围是 [-1000,1000]，转为 [0, 2000]
    vector<vector<int>> dp(sz, vector<int>(2001));

    auto getNum = [](int t) { return t + 1000; };

    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            // 注意第一位相同的情况
            dp[0][nums[i] + 1000] += 1;
            dp[0][-nums[i] + 1000] += 1;
            continue;
        }

        for (int j = 0; j < 2001; j++) {
            if (dp[i - 1][j]) {
                dp[i][j + nums[i]] += dp[i - 1][j];
                dp[i][j - nums[i]] += dp[i - 1][j];
            }
        }
    }

    return dp[sz - 1][target + 1000];
}

int main(int argc, char *argv[]) {
    // 5
    cout << findTargetSumWays({1, 1, 1, 1, 1}, 3) << endl;
    // 1
    cout << findTargetSumWays({1}, 1) << endl;
    // 256
    cout << findTargetSumWays({0, 0, 0, 0, 0, 0, 0, 0, 1}, 1) << endl;

    return 0;
}
