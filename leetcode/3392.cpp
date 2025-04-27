#include "../template/head.h"
#include <bits/stdc++.h>

int countSubarrays(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    int sz = nums.size();
    int cnt = 0;
    for (int i = 1; i < sz - 1; i++) {
        // 可能有负数，不要直接右移
        // 用乘法，用除法有小数
        if (nums[i] == ((nums[i - 1] + nums[i + 1]) * 2)) {
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << countSubarrays({1, 2, 1, 4, 1}) << endl;
    // 0
    cout << countSubarrays({1, 1, 1}) << endl;
    // 1
    cout << countSubarrays({-1, -4, -1, 4}) << endl;

    return 0;
}
