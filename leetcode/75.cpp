#include "../template/head.h"
#include <bits/stdc++.h>
void sortColors(vector<int> &nums) {
    // 思路：贪心 + 双指针
    // 时间 O(n)，空间 O(1)

    // 一个指针指向 0 的位置，另一个指针指向 2 的位置
    int sz = nums.size();
    int a = 0, b = sz - 1, t = 0;
    while (t <= b) {
        if (nums[t] == 0) { // 0 和 2 中间的都赋值为 1
            nums[t] = 1;    // 先赋值，再更改为 0
            nums[a++] = 0;
            t++;
        } else if (nums[t] == 2) {
            nums[t] = nums[b]; // 先赋值，再更改为 2
            nums[b--] = 2;
        } else {
            t++;
        }
    }

    return;
}

int main(int argc, char *argv[]) {

    // {0,0,1,1,2,2}
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    printVector(nums);

    // {0,1,2}
    nums = {2, 0, 1};
    sortColors(nums);
    printVector(nums);

    return 0;
}
