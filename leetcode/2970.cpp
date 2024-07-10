#include "../template/head.h"
#include <bits/stdc++.h>

int incremovableSubarrayCount(vector<int> nums) {
    // 思路：暴力
    // 时间 O(n3)，空间 O(1)
    int cnt = 0;
    int sz = nums.size();

    auto check = [&](int l, int r) {
        int pre = -1;
        for (int i = 0; i < sz; i++) {
            if (i >= l && i <= r) {
                continue;
            }
            if (nums[i] > pre) {
                pre = nums[i];
            } else {
                return false;
            }
        }

        return true;
    };

    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            cnt += check(i, j);
        }
    }

    return cnt;
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
