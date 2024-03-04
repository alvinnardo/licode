#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool validPartition(const vector<int> &nums) {
    // 1 1 1 1 1 2 3 4
    // 1 1 2 3 4 5 6 7
    // 1 1 1 2 3 4 5
    // 动态规划

    int sz = nums.size();
    vector<bool> dp(sz + 1);
    dp[0] = true;
    dp[1] = false;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            // 两个相等：判断上上个是否成立, 如 t,1,1
            // 三个相等：判断上上上个是否成立, 如 t,1,1,1
            dp[i+1] = dp[i-1] || i > 1 && dp[i-2] && nums[i] == nums[i-2];
        } else if (nums[i] - nums[i-1] == 1) {
            // 三个相连：判断上上上个是否成立，如 t,1,2,3
            dp[i+1] = (i <= 1 || dp[i-2] == false) ? false : nums[i] - nums[i-2] == 2;
        } else {
            dp[i+1] = false;
        }
    }

    printBool(dp[sz]);

    return 0;
}

int main(void) {
    validPartition({4, 4, 4, 5, 6}); // 1
    validPartition({1,2}); // 0
    validPartition({1,2,3}); // 1
    validPartition({2,1,1}); // 0
    validPartition({1,1,1,2}); // 0
    validPartition({1,1,1}); // 1
    validPartition({1,1,1,2,3,4}); // 1
    validPartition({1,1,1,2,3,4,5}); // 0
    validPartition({1,1,1,2,3,4,5,6}); // 1
    validPartition({1,1,2,3,4,5,6}); // 0
    validPartition({1,1,2,3,4,5,6,7}); // 1

    return 0;
}
