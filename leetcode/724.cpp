#include "../template/head.h"
#include <bits/stdc++.h>

int pivotIndex(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++) {
        right -= nums[i];
        if (left == right) {
            return i;
        }
        left += nums[i];
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 3
    cout << pivotIndex({1, 7, 3, 6, 5, 6}) << endl;
    // -1
    cout << pivotIndex({1, 2, 3}) << endl;
    // 0
    cout << pivotIndex({2, 1, -1}) << endl;

    return 0;
}
