#include "../template/head.h"
#include <bits/stdc++.h>

long long countFairPairs(vector<int> nums, int lower, int upper) {
    // 思路：二分
    // 时间 O(nlogn)，空间 O(1)

    // lower <= nums[i] + nums[j] <= upper
    // 等价于 lower - nums[i] <= nums[j] <= upper - nums[i];
    // 遍历 i，二分找到 j 的范围即可，如果范围包括 i 需要减去一个
    sort(nums.begin(), nums.end());

    int sz = nums.size();
    long long res = 0;
    for (int i = 0; i < sz; i++) {
        int left = lower - nums[i], right = upper - nums[i];

        auto posl = lower_bound(nums.begin(), nums.end(), left) - nums.begin();
        if (posl == sz) { // 没有大于等于 left 的
            continue;
        }
        auto posr =
            upper_bound(nums.begin(), nums.end(), right) - nums.begin() - 1;
        if (posr == -1) { // 没有小于等于 right 的
            continue;
        }

        res += (posr - posl + 1);
        if (posl <= i && i <= posr) {
            res--;
        }
    }

    // (i, j) 和 (j, i) 重复
    return res >> 1;
}

int main(int argc, char *argv[]) {
    // 6
    cout << countFairPairs({0, 1, 7, 4, 4, 5}, 3, 6) << endl;
    // 1
    cout << countFairPairs({1, 7, 9, 2, 5}, 11, 11) << endl;

    return 0;
}
