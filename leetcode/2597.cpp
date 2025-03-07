#include "../template/head.h"
#include <bits/stdc++.h>

int beautifulSubsets(vector<int> nums, int k) {
    // 思路：回溯 + 哈希表
    // 时间 O(2^n)，空间 O(n)
    // 个数范围上限是 18，指数复杂度能做

    int tot = 0;
    // 前后都要拒绝
    unordered_map<int, int> reject;

    function<void(int, int)> dfs = [&](int pos, int cnt) {
        if (pos >= nums.size()) {
            tot += cnt > 0;
            return;
        }

        // 不选
        dfs(pos + 1, cnt);
        // 选，在不拒绝的情况下
        if (!reject[nums[pos]]) {
            reject[nums[pos] + k]++;
            reject[nums[pos] - k]++;
            dfs(pos + 1, cnt + 1);
            reject[nums[pos] + k]--;
            reject[nums[pos] - k]--;
        }
    };

    dfs(0, 0);
    return tot;
}

int main(int argc, char *argv[]) {
    // 4
    cout << beautifulSubsets({2, 4, 6}, 2) << endl;
    // 1
    cout << beautifulSubsets({1}, 1) << endl;

    return 0;
}
