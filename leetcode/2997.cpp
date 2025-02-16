#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums, int k) {
    // 思路：遍历 + 模拟
    // 如果结果当前位是 1，但个数是偶数(异或为 0)，则翻转
    // 如果结果当前位是 0，但个数是奇数(异或为 1)，则翻转
    // 时间 O(nlogn)，空间 O(1)
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }

    return __builtin_popcount(res ^ k);
}

int main(int argc, char *argv[]) {
    // 2
    cout << minOperations({2, 1, 3, 4}, 1) << endl;
    // 0
    cout << minOperations({2, 0, 2, 0}, 0) << endl;

    return 0;
}
