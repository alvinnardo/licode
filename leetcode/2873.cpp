#include "../template/head.h"
#include <bits/stdc++.h>

long long maximumTripletValue(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)
    long long res = 0;
    int sz = nums.size();
    bool has = false;
    for (int i = 1; i < sz - 1; i++) {
        if (nums[i] < nums[i - 1]) {
            has = true;
            break;
        }
    }

    if (!has) {
        return 0;
    }

    int k = INT_MIN;
    for (int i = sz - 1; i >= 2; i--) {
        k = max(k, nums[i]); // 第 3 个数

        // 第 2 个数
        int minv = nums[i - 1], minus = INT_MIN;
        for (int j = i - 2; j >= 0; j--) { // 遍历第一个数
            if (nums[j] > minv) {
                minus = max(minus, nums[j] - minv);
            }
            minv = min(minv, nums[j]);
        }

        if (minus < 0) {
            minus = 0;
        }

        res = max(res, (long long)minus * k);
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
