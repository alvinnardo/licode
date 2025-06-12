#include "../template/head.h"
#include <bits/stdc++.h>

int maxAdjacentDistance(vector<int> &&nums) {
    // 思路：模拟
    // 时间  O(n)，空间 O(1)
    int sz = nums.size();
    int maxv = nums[0] > nums[sz - 1] ? nums[0] - nums[sz - 1]
                                      : nums[sz - 1] - nums[0];

    for (int i = 1; i < nums.size(); i++) {
        maxv = max(maxv, nums[i] > nums[i - 1] ? nums[i] - nums[i - 1]
                                               : nums[i - 1] - nums[i]);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxAdjacentDistance({1, 2, 4}) << endl;
    // 5
    cout << maxAdjacentDistance({-5, -10, -5}) << endl;

    return 0;
}
