#include "../template/head.h"
#include <bits/stdc++.h>

long long sumDigitDifferences(vector<int> nums) {
    // 思路：遍历 + 统计
    // 对每一位进行统计
    // 时间 O(kn)，空间 O(1)
    int sz = nums.size(), zero_cnt = 0;
    vector<int> bit_count(10);
    long long res = 0;
    while (zero_cnt != sz) {
        zero_cnt = 0;

        for (int i = 0; i < sz; i++) {
            int t = nums[i] % 10;
            nums[i] /= 10;
            // 这个地方判断去掉最后一位后剩下的是否是 0
            // 而不是判断最后一位是否是 0
            zero_cnt += nums[i] == 0;
            bit_count[t]++;

            res += i - bit_count[t] + 1;
        }

        for (int i = 0; i < 10; i++) {
            bit_count[i] = 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << sumDigitDifferences({13, 23, 12}) << endl;
    // 0
    cout << sumDigitDifferences({10, 10, 10, 10}) << endl;
    // 2
    cout << sumDigitDifferences({100, 220}) << endl;

    return 0;
}
