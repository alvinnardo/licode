#include "../template/head.h"
#include <bits/stdc++.h>

int minPairSum(vector<int> nums) {
    // 思路：贪心 + 排序
    // 大值和小值中和
    // 时间 O(nlogn)，空间 O(logn)
    int res = INT_MIN;
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        res = max(res, nums[i++] + nums[j--]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << minPairSum({3, 5, 2, 3}) << endl;
    // 8
    cout << minPairSum({3, 5, 4, 2, 4, 6}) << endl;

    return 0;
}
