#include "../template/head.h"
#include <bits/stdc++.h>

int maximumUniqueSubarray(vector<int> &&nums) {
    // 思路：双指针 + 哈希表
    // 时间 O(n)，空间 O(n)
    // 要求数组
    // 时间太长，哈希表用数组改写一下
    int res = 0, span = 0;
    vector<int> vec(10001);
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
        while (vec[nums[i]]) {
            span -= nums[j];
            vec[nums[j++]]--;
        }

        span += nums[i];
        vec[nums[i]]++;
        res = max(res, span);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 17
    cout << maximumUniqueSubarray({4, 2, 4, 5, 6}) << endl;
    // 8
    cout << maximumUniqueSubarray({5, 2, 1, 2, 5, 2, 1, 2, 5}) << endl;

    return 0;
}
