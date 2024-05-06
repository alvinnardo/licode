#include "../template/head.h"
#include <bits/stdc++.h>

int minMoves(vector<int> nums) {

    // 思路：找最小的 n - 1 个值 +1，就相当于最大的值 -1
    // 当依次减时，每个数都有可能成为最大值，
    // 直到当所有值都减到和最小值相等时结束
    // 遍历求与最小值的差和
    // 时间 O(n), 空间 O(1)
    int minv = *min_element(nums.begin(), nums.end());
    int cnt = 0;
    for (auto &num : nums) {
        cnt += num - minv;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minMoves({1, 2, 3}) << endl;
    // 0
    cout << minMoves({1, 1, 1}) << endl;
    // 16
    cout << minMoves({0, 1, 3, 5, 7}) << endl;
    // 17
    cout << minMoves({3, 4, 7, 8, 10}) << endl;
    // 114
    cout << minMoves({3, 4, 7, 8, 10, 11, 12, 13, 14, 15, 17, 19, 20}) << endl;
    // 2000000000
    cout << minMoves({-1000000000, 1000000000}) << endl;

    return 0;
}
