#include "../template/head.h"
#include <bits/stdc++.h>

int maxSum(vector<int> &&nums) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(k)
    // 注意不能全删空，如果只有负的，取最大的负的

    vector<bool> vec(201); // -100 -- 100
    int cnta = 0, cntb = 0;
    int a = INT_MIN, b = 0, t = 0;
    for (int i = 0; i < nums.size(); i++) {
        t = nums[i] + 100;
        if (!vec[t]) {
            if (nums[i] >= 0) {
                cntb++;
                b += nums[i];
            } else {
                cnta++;
                a = max(a, nums[i]);
            }
            vec[t] = true;
        }
    }

    return cntb == 0 ? a : b;
}

int main(int argc, char *argv[]) {
    // 15
    cout << maxSum({1, 2, 3, 4, 5}) << endl;
    // 1
    cout << maxSum({1, 1, 0, 1, 1}) << endl;
    // 3
    cout << maxSum({1, 2, -1, -2, 1, 0, -1}) << endl;

    return 0;
}
