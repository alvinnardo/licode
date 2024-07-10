#include "../template/head.h"
#include <bits/stdc++.h>

// 2970 的高阶版
long long incremovableSubarrayCount(vector<int> nums) {
    // 题解：双指针
    // 首先确保左边是一个递增的数组，然后依次枚举右边递增数组的最左值
    // 每次遍历压缩左边的最大值
    // 时间 O(n)，空间 O(1)
    // 模式：左右子数组，中间断开
    int sz = nums.size();
    int i = 0;
    long long res = 0;
    while (i + 1 < sz) {
        if (nums[i + 1] > nums[i]) {
            i++;
        } else {
            break;
        }
    }

    // 右端全删掉的可能个数
    // 如 [1,2,3,4,5,6]，可能个数就是 5 + 1
    //    [1,2,3,4,5,6,5]，可能个数就是 5 + 2
    // 判断左边的最大值和右边的最小值中间有没有可能去掉的数组
    // 如果相连，则没有
    res += i == sz - 1 ? i + 1 : i + 2;

    int j = sz - 1;
    while (j == sz - 1 || j >= 0 && nums[j] < nums[j + 1]) {
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
        }
        res += i == j - 1 ? i + 1 : i + 2;
        j--;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 10
    cout << incremovableSubarrayCount({1, 2, 3, 4}) << endl;
    // 7
    cout << incremovableSubarrayCount({6, 5, 7, 8}) << endl;
    // 3
    cout << incremovableSubarrayCount({8, 7, 6, 6}) << endl;

    return 0;
}
