#include "../template/head.h"
#include <bits/stdc++.h>

double minimumAverage(vector<int> nums) {
    // 思路：排序
    // 时间 O(nlogn)，空间 O(1)

    sort(nums.begin(), nums.end());
    int n = nums.size() / 2, res = INT_MAX;
    int i = 0, j = nums.size() - 1;
    while (i < n) {
        res = min(res, nums[i] + nums[j]);
        i++;
        j--;
    }

    return res * 1.0 / 2;
}

int main(int argc, char *argv[]) {
    // 5.5
    cout << minimumAverage({7, 8, 3, 4, 15, 13, 4, 1}) << endl;
    // 5.5
    cout << minimumAverage({1, 9, 8, 3, 10, 5}) << endl;
    // 5.0
    cout << minimumAverage({1, 2, 3, 7, 8, 9}) << endl;

    return 0;
}
