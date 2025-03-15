#include "../template/head.h"
#include <bits/stdc++.h>

int triangularSum(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            nums[j] = (nums[j] + nums[j - 1]) % 10;
        }
    }

    return nums.back();
}

int main(int argc, char *argv[]) {
    // 8
    cout << triangularSum({1, 2, 3, 4, 5}) << endl;
    // 5
    cout << triangularSum({5}) << endl;

    return 0;
}
