#include "../template/head.h"
#include <bits/stdc++.h>

int maximumPrimeDifference(vector<int> nums) {
    // 思路：素筛 + 贪心
    // 时间 O(n + k)，k 是数据范围上限
    // 空间 O(k)
    unordered_set<int> uset{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int left = -1, right = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (uset.count(nums[i])) {
            if (left == -1) {
                left = i;
            }
            right = i;
        }
    }

    return right - left;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maximumPrimeDifference({4, 2, 9, 5, 3}) << endl;
    // 0
    cout << maximumPrimeDifference({4, 8, 2, 8}) << endl;

    return 0;
}
