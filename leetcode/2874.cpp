#include "../template/head.h"
#include <bits/stdc++.h>

long long maximumTripletValue(vector<int> nums) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    // 枚举 j，保存 i 和 i-j 的最大值
    int sz = nums.size();
    int imax = max(nums[0], nums[1]), i_j_max = max(0, nums[0] - nums[1]);

    long long res = 0;
    for (int k = 2; k < sz; k++) {
        res = max(res, (long long)i_j_max * nums[k]);
        /* clang-format off */
        /** 以下两个顺序可以颠倒
         * 1. 如果当前是最大值 (最大的 (i - j) 在这个数之前)
         *   a. imax 变化，i_j_max = max(i_j_max, imax - nums[k] = 0)
         *   b. i_j_max = max(i_j_max, max(0, imax - nums[k] < 0)) = 0，imax 变化
         * 2. 如果当前是最小值或中间值
         *   a. imax 不变，i_j_max = max(i_j_max, imax - nums[k]) = imax - nums[k]
         *   b. i_j_max = max(i_j_max, imax - nums[k]) = imax - nums[k], imax 不变
         */
        /* clang-format on */
        imax = max(imax, nums[k]);
        i_j_max = max(i_j_max, imax - nums[k]);
    }

    return res;
}

long long maximumTripletValue1(vector<int> nums) {
    // 思路：贪心
    // 时间 O(n)，空间 O(n)

    // 枚举 j，保存 j 前的最大值和 j 后的最大值
    int sz = nums.size();
    vector<int> max_tail_vec(sz); // 保存该数后面的最大数
    long long res = 0;

    for (int i = sz - 2; i >= 0; i--) {
        max_tail_vec[i] = max(nums[i + 1], max_tail_vec[i + 1]);
    }

    int max_pre = nums[0];
    for (int i = 1; i < sz - 1; i++) {
        res =
            max(res, (long long)(max(0, max_pre - nums[i])) * max_tail_vec[i]);
        max_pre = max(max_pre, nums[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 77
    cout << maximumTripletValue({12, 6, 1, 2, 7}) << endl;
    // 133
    cout << maximumTripletValue({1, 10, 3, 4, 19}) << endl;
    // 0
    cout << maximumTripletValue({1, 2, 3}) << endl;

    return 0;
}
