#include "../template/head.h"
#include <bits/stdc++.h>

int findValueOfPartition(vector<int> nums) {
    // 思路：排序 + 贪心
    // 找排序后相邻两值的最小差
    // 时间 O(nlogn)，空间 O(logn)
    sort(nums.begin(), nums.end());
    int res = INT_MAX;
    for (int i = 1; i < nums.size(); i++) {
        res = min(res, nums[i] - nums[i - 1]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << findValueOfPartition({1, 3, 2, 4}) << endl;
    // 9
    cout << findValueOfPartition({100, 1, 10}) << endl;

    return 0;
}
