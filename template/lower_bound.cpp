#include <bits/stdc++.h>
using namespace std;

void lower_bound(int target, vector<int> &nums) {

    // 如 target = 8, nums = {1, 2, 7, 7, 8, 8, 10}
    // 求 >= 8
    int sz = nums.size();
    int left = 0, right = sz - 1; // 闭区间

    while (left <= right) {                  // 当区间不为空
        int mid = left + (right - left) / 2; // 也是向下取余
        // 要注意题目中的 >= 和 这里的逻辑要区分一下, 遇到二分题目可以比划一下
        if (nums[mid] < target) { // 如果小了，就 left 增大
            left = mid + 1;       // 确保闭区间
        } else {
            // 如果大了，就 right 减小；等于的话，要找第一个相等的，也 right
            // 减小 比如 8 8 8 8 8, right 不断减小
            right = mid - 1;
        }
    }

    // 最后得到的 right = 7, left = 8
    // 循环不变性，right + 1 始终 >= 8, left - 1 始终 < 8
    // 最后返回 right + 1 或 left
}
