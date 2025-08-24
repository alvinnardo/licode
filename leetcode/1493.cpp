#include "../template/head.h"
#include <bits/stdc++.h>

int longestSubarray(vector<int> &&nums) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)

    // 题目要求必须删除一个，所以取值时需要判断一下
    int res = 0, sz(nums.size());
    int cnt0 = 0, cnt1 = 0;

    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (nums[i] == 0) {
            cnt0++;
        } else {
            cnt1++;
        }

        while (cnt0 > 1) {
            if (nums[j] == 0) {
                cnt0--;
            } else {
                cnt1--;
            }
            j++;
        }

        res = max(res, cnt1 - 1 + cnt0);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << longestSubarray({1, 1, 0, 1}) << endl;
    // 5
    cout << longestSubarray({0, 1, 1, 1, 0, 1, 1, 0, 1}) << endl;
    // 2
    cout << longestSubarray({1, 1, 1}) << endl;

    return 0;
}
