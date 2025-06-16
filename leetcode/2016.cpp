#include "../template/head.h"
#include <bits/stdc++.h>

int maximumDifference(vector<int> &&nums) {
    // 思路：遍历
    // 时间 O(n)，空间 O(1)
    int res = INT_MIN;

    int minv = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int t = nums[i] - minv;
        if (t > 0) { // 题目给出必须大于
            res = max(res, t);
        }
        minv = min(minv, nums[i]);
    }

    return res < 0 ? -1 : res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maximumDifference({7, 1, 5, 4}) << endl;
    // -1
    cout << maximumDifference({9, 4, 3, 2}) << endl;
    // 9
    cout << maximumDifference({1, 5, 2, 10}) << endl;

    return 0;
}
