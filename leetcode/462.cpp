#include "../template/head.h"
#include <bits/stdc++.h>
int minMoves2(vector<int> nums) {
    // 优化：
    // 1. 可以得出在偶数时，两个中位数的差值和是相同的，则可以与奇数情况合并
    // 2. 找第 k 个数，可以用快速选择，对应 nth_element() 函数
    // 时间 O(logn), 空间 O(logn) 快速选择中的栈
    int sz = nums.size();
    // 重排元素，nth 位置是排序后的元素位置
    nth_element(nums.begin(), nums.begin() + (sz >> 1), nums.end());
    int mid = nums[sz >> 1];

    int cnt = 0;
    for (auto &num : nums) {
        cnt += abs(num - mid);
    }

    return cnt;
}

int minMoves2_my(vector<int> nums) {

    // 思路：这道题可以 +1，也可以 -1，所以要向中间值靠拢
    // 奇数时，向最中间的值靠拢；
    // 偶数时，向中间的两个数靠拢，比较并得最小值
    // 时间 O(nlogn), 空间 O(1)
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int cnt = 0, pos = sz >> 1;
    if (sz & 1) {
        int mid = nums[pos];
        for (auto &num : nums) {
            cnt += abs(num - mid);
        }
    } else {
        int left = nums[pos - 1], left_cnt = 0;
        int right = nums[pos], right_cnt = 0;
        for (auto &num : nums) {
            left_cnt += abs(num - left);
            right_cnt += abs(num - right);
        }
        cnt = min(left_cnt, right_cnt);
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minMoves2({1, 2, 3}) << endl;
    // 16
    cout << minMoves2({1, 10, 2, 9}) << endl;

    return 0;
}
