#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> nums) {
    // 根据题解优化：1. 判断最大值和寻找值的关系
    // 2. 使用 true 和 false 来判断，不需要用和来判断

    int sum = 0, maxv = 0;
    for (auto &num : nums) {
        sum += num;
        if (num > maxv) {
            maxv = num;
        }
    }
    if (sum & 1) {
        return false;
    }

    sum /= 2;
    if (maxv > sum) {
        return false;
    }

    int sz = nums.size();
    vector<vector<bool>> dp(sz + 1, vector<bool>(sum + 1));
    // 不选任何数，和为 0 成立
    for (int i = 0; i < sz + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[sz][sum];
}

bool canPartition_my(vector<int> nums) {
    // 思路：1. 先求和，如果和是奇数，肯定不能平分
    // 2. 变形的 0-1 背包问题，重量和价值相等，判断能否得到 tot / 2即可
    // 注意：如果是偶数不一定能够平分如: 4 4 4

    // 2025-04-07 思维固化了，没有往背包问题上想，一直想状压 DP 怎么做
    // 思路：DP
    // 时间 O(mn)，空间 O(mn)，m 是总和，n 是个数

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
        return false;
    }

    sum /= 2;
    int sz = nums.size();
    vector<vector<int>> dp(sz + 1, vector<int>(sum + 1));

    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) { // 放不下
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }

            if (dp[i][j] == sum) {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    // true
    printBool(canPartition({1, 5, 11, 5}));
    // false
    printBool(canPartition({1, 2, 3, 5}));
    // true
    printBool(canPartition({11, 11}));
    // false
    printBool(canPartition({11, 3, 11}));
    // false
    printBool(canPartition({11, 11, 11}));
    // true
    printBool(canPartition({11, 11, 11, 11}));
    // false
    printBool(canPartition({4, 4, 4}));
    // true
    printBool(canPartition({1, 2, 3, 4, 4, 5, 11}));

    return 0;
}
