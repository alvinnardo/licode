#include "../template/head.h"
#include <bits/stdc++.h>
bool canPartitionKSubsets(vector<int> nums, int k) {
    // 题解2：状压 DP
    // 时间 O(n * 2^n)，空间 O(2^n)
    int all = accumulate(nums.begin(), nums.end(), 0);
    if (all % k) {
        return false;
    }

    int per = all / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > per) { // 放不下
        return false;
    }

    int n = nums.size();
    vector<bool> dp(1 << n, false);
    vector<int> curSum(1 << n, 0);
    dp[0] = true;
    for (int i = 0; i < 1 << n; i++) {
        if (!dp[i]) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (curSum[i] + nums[j] > per) {
                break;
            }

            if (((i >> j) & 1) == 0) {
                int next = i | (1 << j);
                if (!dp[next]) {
                    curSum[next] = (curSum[i] + nums[j]) % per;
                    dp[next] = true;
                }
            }
        }
    }

    return dp[(1 << n) - 1];
}

bool canPartitionKSubsets_dfs(vector<int> nums, int k) {
    // 题解：状压 + 记忆化搜索
    // 时间 O(n * 2^n)，空间 O(2^n)
    int all = accumulate(nums.begin(), nums.end(), 0);
    if (all % k) {
        return false;
    }

    int per = all / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > per) { // 放不下
        return false;
    }

    int n = nums.size();
    // 下标是物品放与不放的所有状态，值 true 表示可以探测
    vector<bool> dp(1 << n, 1);

    function<bool(int, int)> dfs = [&](int s, int p) -> bool {
        if (s == 0) {
            return true;
        }

        if (!dp[s]) { // 表示该状态不可以探测
            return dp[s];
        }

        dp[s] = false;
        // 对每一个都尝试放一下
        for (int i = 0; i < n; i++) {
            if (nums[i] + p > per) { // 剪枝，后面的都不能放了
                break;
            }

            if ((s >> i) & 1) { // 如果没放过就尝试放一下
                if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
                    return true;
                }
            }
        }
        return false;
    };

    return dfs((1 << n) - 1, 0);
}

bool canPartitionKSubsets_my(vector<int> nums, int k) {
    // 思路：DP
    // 对上次的结果进行遍历，如果能放则放，不能放就找一个新的放
    int sz = nums.size(), sum = 0, maxv = -1;
    if (sz < k) { // 个数不够
        return false;
    }
    for (auto &num : nums) {
        sum += num;
        maxv = max(num, maxv);
    }
    if (sum % k) { // 不能整除
        return false;
    }

    int every = sum / k;
    if (maxv > every) { // 放不下
        return false;
    }

    // 从大到小排序，能使中间结果更少
    sort(nums.begin(), nums.end(), std::greater<int>());
    vector<vector<int>> vv(1, vector(k, 0));
    for (int i = 0; i < nums.size(); i++) {
        vector<vector<int>> tmp;
        for (auto &state : vv) {
            bool zero = false;
            for (int j = 0; j < state.size(); j++) {
                if (zero) {
                    break;
                }
                if (state[j] == 0) {
                    zero = true;
                }

                if (state[j] + nums[i] <= every) {
                    tmp.push_back(state);
                    tmp.back()[j] += nums[i];
                }
            }
        }

        vv = tmp;
    }

    return !vv.empty();
}

int main(int argc, char *argv[]) {
    // 1
    cout << canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4) << endl;
    // 0
    cout << canPartitionKSubsets({1, 2, 3, 4}, 3) << endl;

    // 1
    cout << canPartitionKSubsets({605, 454, 322, 218, 8, 19, 651, 2220, 175,
                                  710, 2666, 350, 252, 2264, 327, 1843},
                                 4)
         << endl;
    // 0
    cout << canPartitionKSubsets(
                {3, 3, 10, 2, 6, 5, 10, 6, 8, 3, 2, 1, 6, 10, 7, 2}, 6)
         << endl;
    // 1
    cout << canPartitionKSubsets({129, 17, 74, 57, 1421, 99, 92, 285, 1276, 218,
                                  1588, 215, 369, 117, 153, 22},
                                 3)
         << endl;
    // 0
    cout << canPartitionKSubsets({1, 1}, 3) << endl;
    // 1
    cout << canPartitionKSubsets(
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 16)
         << endl;

    return 0;
}
