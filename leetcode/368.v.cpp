#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> largestDivisibleSubset(vector<int> nums) {
    // 思路：DP
    // 时间 O(n2)，空间 O(n)
    int sz = nums.size();
    int maxv = 1, max_pos = 0;              // 保存最大长度和位置
    vector<pair<int, int>> dp(sz, {-1, 1}); // 保存前一个节点和长度

    sort(nums.begin(), nums.end()); // 先排序

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {

            // 如果能整除且形成更长的链，则更新
            if (nums[j] % nums[i] == 0 && dp[i].second + 1 > dp[j].second) {
                dp[j].first = i;
                dp[j].second = dp[i].second + 1;
                if (dp[j].second > maxv) { // 更新全局最大长度和位置
                    maxv = dp[j].second;
                    max_pos = j;
                }
            }
        }
    }

    // 从后往前输出结果
    vector<int> res(maxv);
    for (int i = maxv - 1; i >= 0; i--) {
        res[i] = nums[max_pos];
        max_pos = dp[max_pos].first;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,2}
    printVector(largestDivisibleSubset({1, 2, 3}));
    // {1,2,4,8}
    printVector(largestDivisibleSubset({1, 2, 4, 8, 9}));

    return 0;
}
