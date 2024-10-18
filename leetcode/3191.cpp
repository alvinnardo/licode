#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums) {
    // 思路：模拟
    // 贪心：碰到 0 一定要翻，1 不用翻
    // 时间 O(n)，空间 O(1)
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (i + 1 == nums.size() || i + 2 == nums.size()) {
                return -1;
            }
            nums[i] = 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            res++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minOperations({0, 1, 1, 1, 0, 0}) << endl;
    // -1
    cout << minOperations({0, 1, 1, 1}) << endl;
    // 0
    cout << minOperations({1, 1, 1}) << endl;
    // 1
    cout << minOperations({0, 0, 0}) << endl;
    // 9
    cout << minOperations({1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1})
         << endl;

    return 0;
}
