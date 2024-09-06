#include "../template/head.h"
#include <bits/stdc++.h>

int maximumLength(vector<int> nums, int k) {
    // 思路：DFS
    // 时间 O(n2k)，空间 O(nk)

    int sz = nums.size();

    vector<vector<int>> dp(sz, vector<int>(k + 1, 0));
    std::function<int(int, int)> dfs = [&](int pos, int k) {
        if (dp[pos][k] != 0) {
            return dp[pos][k];
        }

        int res = 1;
        for (int i = 0; i < pos; i++) {
            if (nums[i] == nums[pos]) {
                res = max(res, dfs(i, k) + 1);
            } else if (k > 0) {
                res = max(res, dfs(i, k - 1) + 1);
            }
        }

        dp[pos][k] = res;
        return res;
    };

    int res = INT_MIN;
    for (int i = 0; i < sz; i++) {
        res = max(res, dfs(i, k));
    }
    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maximumLength({1, 2, 1, 1, 3}, 2) << endl;
    // 2
    cout << maximumLength({1, 2, 3, 4, 5, 1}, 0) << endl;

    return 0;
}
