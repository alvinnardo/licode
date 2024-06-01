#include <bits/stdc++.h>
using namespace std;

void upper_bound(int target, vector<int> &nums) {

    // 如 target = 8, nums = {1, 2, 7, 7, 8, 8, 10}
    // 求 >= 8
    int sz = nums.size();
    int left = 0, right = sz - 1; // 闭区间

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) { // 与 lower_bound 相比，多了一个等号
            // 表示 left 左边都是 小于等于的，则 left 是第一个大于的
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}
