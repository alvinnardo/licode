#include "../template/head.h"
#include <bits/stdc++.h>

int differenceOfSum(vector<int> nums) {
    // 思路：模拟
    // 时间 O(nk)，空间 O(1)，k 是最长十进制位数

    int sum1 = 0, sum2 = 0;
    auto getSum = [&](int num) {};

    for (int i = 0; i < nums.size(); i++) {
        sum1 += nums[i];
        while (nums[i]) {
            sum2 += nums[i] % 10;
            nums[i] /= 10;
        }
    }

    return sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
}

int main(int argc, char *argv[]) {
    // 9
    cout << differenceOfSum({1, 15, 6, 3}) << endl;
    // 0
    cout << differenceOfSum({1, 2, 3, 4}) << endl;

    return 0;
}
