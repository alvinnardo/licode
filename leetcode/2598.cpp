#include "../template/head.h"
#include <bits/stdc++.h>

int findSmallestInteger(vector<int> &&nums, int value) {
    // 思路：贪心 + 统计
    // 时间 O(m + n)，空间 O(n)

    // 先求每个值对 value 取余
    // 从 0 开始统计个数
    // 最后遍历数组求第一个最小值，就是缺的值的余数
    int m = nums.size();
    vector<int> vec(value);

    // 要考虑负数取余
    for (int i = 0; i < m; i++) {
        vec[((nums[i] % value) + value) % value]++;
    }

    int minv = INT_MAX, minp{};
    for (int i = 0; i < value; i++) {
        if (vec[i] < minv) {
            minp = i;
            minv = vec[i];
        }
    }

    return minv * value + minp;
}

int main(int argc, char *argv[]) {
    // 4
    cout << findSmallestInteger({1, -10, 7, 13, 6, 8}, 5) << endl;
    // 2
    cout << findSmallestInteger({1, -10, 7, 13, 6, 8}, 7) << endl;

    return 0;
}
