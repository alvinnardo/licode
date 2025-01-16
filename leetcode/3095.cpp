#include "../template/head.h"
#include <bits/stdc++.h>

int minimumSubarrayLength(vector<int> nums, int k) {
    // 思路：暴力 + 模拟
    // 数据量小，纯暴力，无任何优化
    // 要求子数组
    // 时间 O(n2)，空间 O(1)
    int minv = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int tmp = 0, cnt = 0;
        for (int j = i; j < nums.size(); j++) {
            tmp |= nums[j];
            cnt++;
            if (tmp >= k) {
                minv = min(minv, cnt);
                break;
            }
        }
    }

    return minv == INT_MAX ? -1 : minv;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumSubarrayLength({1, 2, 3}, 2) << endl;
    // 3
    cout << minimumSubarrayLength({2, 1, 8}, 10) << endl;
    // 1
    cout << minimumSubarrayLength({1, 2}, 0) << endl;

    return 0;
}
