#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> nums) {
    // 思路：动态规划 O(n2)

    sort(nums.begin(), nums.end());

    int sz = nums.size();
    vector<vector<int>> dp(sz);
    int max_len = 0, max_pos = -1;
    for (int i = 0; i < sz; i++) {
        int pos = -1;
        int psz = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j].size() > psz) {
                psz = dp[j].size();
                pos = j;
            }
        }

        // 局部
        if (pos != -1) {
            dp[i] = dp[pos];
        }
        dp[i].push_back(nums[i]);

        // 全局
        if (dp[i].size() > max_len) {
            max_len = dp[i].size();
            max_pos = i;
        }
    }

    return dp[max_pos];
}

int main(void) {
    printVector(largestDivisibleSubset({1, 2, 3}));
    printVector(largestDivisibleSubset({1, 2, 4, 8}));
    printVector(largestDivisibleSubset({2, 3, 4, 5, 7, 8, 9, 11, 18, 27, 36}));
    auto tmp = getNRandom(1, 2000, 1000, true);
    printVector(tmp);
    printVector(largestDivisibleSubset(tmp));

    return 0;
}
