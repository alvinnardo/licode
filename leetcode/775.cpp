#include "../template/head.h"
#include <bits/stdc++.h>

bool isIdealPermutation(vector<int> nums) {
    // 优化：从右到左，判断当前值右边一个元素的再右边的最小值是否小于当前值
    // 时间 O(n)，空间 O(1)
    int sz = nums.size();
    int minv = nums.back();
    for (int i = sz - 3; i >= 0; i--) {
        if (minv < nums[i]) {
            return false;
        }
        minv = min(minv, nums[i + 1]);
    }
    return true;
}

bool isIdealPermutation_my(vector<int> nums) {
    // 思路：贪心，从右到左，判断最小值是不是在它右边，如果不是则比局部要大
    // 第二小的要大于它
    // 时间：O(n)，空间 O(1)
    int sz = nums.size();
    int minv = nums.back(), minv2 = INT_MAX;
    for (int i = sz - 2; i >= 0; i--) {
        if (nums[i] > minv && (minv != nums[i + 1] || minv2 < nums[i])) {
            return false;
        }

        if (nums[i] < minv) {
            minv2 = minv;
            minv = nums[i];
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << isIdealPermutation({1, 0, 2}) << endl;
    // 0
    cout << isIdealPermutation({1, 2, 0}) << endl;
    // 0
    cout << isIdealPermutation({4, 2, 3, 1}) << endl;
    // 0
    cout << isIdealPermutation({2, 0, 1}) << endl;

    return 0;
}
