#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> nums) {
    // 思路：一眼双指针, 找等差相等的最长子数组
    // 如果长度小于 3，直接为 0；否则，求元素为 3 到 k 个的个数和
    // 公式为 1 + 2 + ... + (k - 2) = (k - 1) * (k - 2) / 2

    // 时间 O(n), 空间 O(k)
    // 有 4 个用例没过，太长了不好排查，换一个算法
    vector<pair<int, int>> vec; // 存放等差和个数
    for (int i = 1; i < nums.size(); i++) {
        int d = nums[i] - nums[i - 1];
        if (vec.empty() || vec.back().first != d) {
            vec.emplace_back(d, 1);
        } else {
            vec.back().second++;
        }
    }

    int sum = 0;
    for (auto &t : vec) {
        if (t.second != 1) {
            // 个数是公差个数 + 1
            sum += (t.second) * (t.second - 1) / 2;
        }
    }

    return sum;
}

int main(void) {
    // 3
    cout << numberOfArithmeticSlices({1, 2, 3, 4, 6, 7, 8, 9, 10}) << endl;
    // 0
    cout << numberOfArithmeticSlices({1}) << endl;

    return 0;
}
