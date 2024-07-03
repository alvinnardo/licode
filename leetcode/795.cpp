#include "../template/head.h"
#include <bits/stdc++.h>

int numSubarrayBoundedMax(vector<int> nums, int left, int right) {
    // 优化：贪心
    // 时间 O(n)，空间 O(1)
    auto getSum = [&](int limit) {
        int cnt = 0, sum = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] > limit) {
                cnt = 0;
            } else {
                cnt++;
                sum += cnt;
            }
        }

        return sum;
    };

    return getSum(right) - getSum(left - 1);
}

int numSubarrayBoundedMax1(vector<int> nums, int left, int right) {
    // 思路：贪心
    // 把小于等于 right 的统计出来，再把小于等于 left - 1 的统计出来
    // 时间 O(n)，空间 O(1)
    auto getSum = [&](int limit) {
        int l = -1, r = -1;
        int sum = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] > limit) {
                if (l != -1) {
                    sum += (long long)(r - l + 2) * (r - l + 1) / 2;
                    l = r = -1;
                }
            } else {
                if (l == -1) {
                    l = i;
                }
                r = i;
            }
        }

        return sum;
    };

    return getSum(right) - getSum(left - 1);
}

int main(int argc, char *argv[]) {
    // 3
    cout << numSubarrayBoundedMax({2, 1, 4, 3}, 2, 3) << endl;
    // 7
    cout << numSubarrayBoundedMax({2, 9, 2, 5, 6}, 2, 8) << endl;

    return 0;
}
