#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> nums) {
    // 进阶要求：时间 O(n), 空间 O(1)
    // 思路：该题可以用最长递增子序列来求
    // 贪心 + 单调栈，当存在最长为 3 时，可以返回 true

    // 有效的两个下标
    // 因为数字是 [INT_MIN, INT_MAX]，所以存下标更好判断
    int a = -1, b = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (a == -1 || nums[i] <= nums[a]) {
            a = i;
        } else if (b == -1 || nums[i] <= nums[b]) {
            b = i;
        } else {
            return true;
        }
    }

    return false;
}

int main(void) {
    printBool(increasingTriplet({1, 2, 3, 4, 5}));
    printBool(increasingTriplet({5, 4, 3, 2, 1}));
    printBool(increasingTriplet({2, 1, 5, 0, 4, 6}));

    return 0;
}
