#include "../template/head.h"
#include <bits/stdc++.h>
int smallestRangeII(vector<int> nums, int k) {
    // 题解：贪心 + 枚举
    // 思路比我的思路更清晰，就是贪心地将小值变大，大值变小
    // 时间 O(nlogn)，空间 O(1)

    sort(nums.begin(), nums.end());
    int n = nums.size(), maxv = 0, minv = 0;
    int res = nums[n - 1] - nums[0]; // 初始化为都变大或都变小的差值
    for (int i = 0; i < n - 1; i++) {
        int maxv = max(nums[n - 1] - k, nums[i] + k);
        int minv = min(nums[0] + k, nums[i + 1] - k);
        res = min(res, maxv - minv);
    }

    return res;
}

// 这道题比较难想，大约做了 2 个小时
// 最后做出来了
int smallestRangeII_my(vector<int> nums, int k) {
    /* clang-format off */
    // 思路：模拟
    // 之前的思路：先求平均值，再往平均值靠，如果数据中有平均值则分类讨论一下
    // 但有问题，无论加或者减都有可能会超过平均值，导致过度
    // 最大值肯定出现在 +k 中，那么从大到小遍历 +k 中的大值，然后找 +k 中的最小值
    // 如果找下一个最大值，那么之前的最大值位置就只能选 -k 的值
    // 时间 O(nlogn)，空间 O(n)
    /* clang-format on */

    multiset<int, greater<int>> ss_big, ss_small;
    for (int num : nums) {
        ss_big.insert(num + k);
    }

    k += k;
    int res = INT_MAX, t = 0, cnt = nums.size();
    while (cnt--) {
        if (ss_small.empty() || *ss_small.begin() < *ss_big.begin()) {
            t = ss_small.empty() ? *ss_big.rbegin()
                                 : min(*ss_big.rbegin(), *ss_small.rbegin());

            res = min(res, *ss_big.begin() - t);
            ss_small.insert(*ss_big.begin() - k);
            ss_big.erase(ss_big.begin());
        } else { // 不能再减少了
            res = min(res, *ss_small.begin() -
                               min(*ss_big.rbegin(), *ss_small.rbegin()));
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 0
    cout << smallestRangeII({1}, 0) << endl;
    // 6
    cout << smallestRangeII({0, 10}, 2) << endl;
    // 3
    cout << smallestRangeII({1, 3, 6}, 3) << endl;
    // 0
    cout << smallestRangeII({1, 1, 1, 1, 1}, 3) << endl;
    // 47
    cout << smallestRangeII({45, 81, 58, 1, 92, 66, 96, 52, 7, 78, 94, 8, 17,
                             65, 93, 43, 77},
                            24)
         << endl;

    return 0;
}
