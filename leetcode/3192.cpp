#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums) {
    // 思路：模拟 + 差分思想
    // 因为要翻下一个到最后，那么可以保存当前翻转的总次数即是后面翻转的次数
    // 时间 O(n)，空间 O(n)
    int left = 0; // 表示之前有多少次翻转
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0 && (left & 1) == 0 ||
            nums[i] == 1 && (left & 1)) { // 需要翻转
            left++;
        }
    }

    return left;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minOperations({0, 1, 1, 0, 1}) << endl;
    // 1
    cout << minOperations({1, 0, 0, 0}) << endl;

    return 0;
}
