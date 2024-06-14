#include "../template/head.h"
#include <bits/stdc++.h>

long long maxScore(vector<int> nums, int x) {
    // 思路：DP，从后往前遍历，保存奇偶能够获取的最大值
    // 时间 O(n)，空间 O(1)
    int sz = nums.size();
    long long odd = 0, even = 0;
    for (int i = sz - 1; i >= 0; i--) {
        if (nums[i] & 1) {
            odd = max(nums[i] + odd, nums[i] + even - x);
        } else {
            even = max(nums[i] + even, nums[i] + odd - x);
        }
    }

    return (nums[0] & 1) ? odd : even;
}

int main(int argc, char *argv[]) {
    // 13
    cout << maxScore({2, 3, 6, 1, 9, 2}, 5) << endl;
    // 20
    cout << maxScore({2, 4, 6, 8}, 3) << endl;
    cout << maxScore({2, 3}, 4) << endl;

    return 0;
}
