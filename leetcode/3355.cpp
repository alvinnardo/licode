#include "../template/head.h"
#include <bits/stdc++.h>

bool isZeroArray(vector<int> nums, vector<vector<int>> queries) {
    // 思路：差分数组 + 贪心
    // 时间 O(m + n)，空间 O(1)

    // 因为是子集，所以先按区间都减去，小于等于 0 就能满足
    int sz = nums.size();
    for (int i = sz - 1; i >= 1; i--) {
        nums[i] = nums[i] - nums[i - 1];
    }

    nums.push_back(0);
    for (int i = 0; i < queries.size(); i++) {
        nums[queries[i][0]]--;
        nums[queries[i][1] + 1]++;
    }

    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            if (nums[i] > 0) {
                return false;
            }
        } else {
            nums[i] += nums[i - 1];
            if (nums[i] > 0) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // true
    cout << isZeroArray({1, 0, 1}, {{0, 2}}) << endl;
    // false
    cout << isZeroArray({4, 3, 2, 1}, {{1, 3}, {0, 2}}) << endl;
    // false
    cout << isZeroArray({3}, {{0, 0}, {0, 0}}) << endl;

    return 0;
}
