#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums) {
    // 从后往前，判断当前是否还有下一个值
    int maxv = INT_MIN;
    int sz = nums.size();
    int i = sz - 1;
    for (; i >= 0; i--) {
        if (nums[i] < maxv) { // 表示有下一个值
            break;
        } else {
            maxv = nums[i];
        }
    }
    cout << i << endl;

    if (i == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    int minv = INT_MAX;
    int pos = -1;
    // 从第 i 位，找出后面大于它的那个最小值
    int j = i + 1;
    for (; j < sz; j++) {
        if (nums[j] > nums[i] && nums[j] < minv) {
            minv = nums[j];
            pos = j;
        }
    }
    cout << pos << endl;

    // swap
    int t = nums[i];
    nums[i] = nums[pos];
    nums[pos] = t;

    // 找到了下一个大值，后面排序
    sort(nums.begin() + i + 1, nums.end());
}

int main(void) {
    vector<int> nums{5, 4, 3, 2, 1};
    nums = {3, 1, 2};
    nums = {1, 2, 3};
    nums = {1, 1, 100, 1, 1, 2, 2, 3, 3, 3, 1, 1, 2};
    nums = {1, 1, 2, 0, 1, 1};
    nextPermutation(nums);
    printVector(nums);

    return 0;
}
