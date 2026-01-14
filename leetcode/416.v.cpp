#include "../template/head.h"
#include <bits/stdc++.h>

bool canPartition(vector<int> &&nums) {
    // 思路：DP
    // 时间 O(kn)，空间 O(k)，k 是 sum(nums) / 2，上限是 1e4
    // 类似 0-1背包
    int sz = nums.size();
    int sum = reduce(nums.begin(), nums.end(), 0);
    if (sum & 1) {
        return 0;
    }

    sum >>= 1;

    vector<bool> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < sz; ++i) {
        // 从后往前，否则会覆盖同一次遍历的结果
        for (int j = dp.size() - 1; j >= 0; --j) {
            if (dp[j] && nums[i] + j < dp.size()) {
                dp[nums[i] + j] = 1;
            }
        }
    }

    return dp.back();
}

int main(int argc, char *argv[]) {

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
    // false
    printBool(canPartition({1, 2, 5}));

    return 0;
}
