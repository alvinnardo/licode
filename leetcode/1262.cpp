#include "../template/head.h"
#include <bits/stdc++.h>

int maxSumDivThree(vector<int> &&nums) {
    // 思路：DP
    // 时间 O(kn)，空间 O(k)，k = 3

    // 先取余，dp[i - 1][j] 是前 i - 1 个数的和对 3 取余为 j 的最大值
    int sz = nums.size();
    vector<int> dp(3), cur(3); // 两层交替，避免同一层冲突
    int t{}, z{};
    for (int i = 0; i < sz; i++) {
        cur = dp;

        t = nums[i] % 3;
        if (t == 0) { // 能整除的可以直接加到结果上
            z += nums[i];
        } else if (t == 1) { // 0->1, 1->2, 2->0
            cur[1] = max(dp[1], dp[0] + nums[i]);
            if (dp[1]) {
                cur[2] = max(dp[2], dp[1] + nums[i]);
            }

            if (dp[2]) {
                cur[0] = max(dp[0], dp[2] + nums[i]);
            }
        } else { // 0->2, 1->0, 2->1
            cur[2] = max(dp[2], dp[0] + nums[i]);
            if (dp[1]) {
                cur[0] = max(dp[0], dp[1] + nums[i]);
            }
            if (dp[2]) {
                cur[1] = max(dp[1], dp[2] + nums[i]);
            }
        }

        dp = cur;
    }

    return dp[0] + z;
}

int main(int argc, char *argv[]) {
    // 18
    cout << maxSumDivThree({3, 6, 5, 1, 8}) << endl;
    // 0
    cout << maxSumDivThree({4}) << endl;
    // 12
    cout << maxSumDivThree({1, 2, 3, 4, 4}) << endl;
    // 18
    cout << maxSumDivThree({1, 1, 5, 4, 7}) << endl;

    return 0;
}
