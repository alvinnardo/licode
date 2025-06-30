#include "../template/head.h"
#include <bits/stdc++.h>

int findLHS(vector<int> &&nums) {
    // 思路：排序 + 双指针
    // 时间 O(nlogn)，空间 O(logn)

    // 子序列取数，取集合，可排序
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int res = 0;
    int j = 0;
    for (int i = 0; i < sz; i++) {
        while (j < sz && nums[j] < nums[i] - 1) {
            j++;
        }

        if (nums[j] == nums[i] - 1) {
            res = max(res, i - j + 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << findLHS({1, 3, 2, 2, 5, 2, 3, 7}) << endl;
    // 2
    cout << findLHS({1, 2, 3, 4}) << endl;
    // 0
    cout << findLHS({1, 1, 1, 1}) << endl;

    return 0;
}
