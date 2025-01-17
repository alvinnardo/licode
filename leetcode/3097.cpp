#include "../template/head.h"
#include <bits/stdc++.h>
int minimumSubarrayLength(vector<int> nums, int k) {
    // 思路: 双指针 + 统计
    /* 之前有一道题是关于与的，当时看错题了，
       认为是求子数组了，当时想了很久，没有想到如何处理去掉数字的位
       今天这道题，想到了可以用统计每一位的个数来求，删除数字可以删除该数的每一位
     */
    // 时间 O(kn)，空间 O(k)，k 为 32
    // 优化一个空间
    vector<int> nvv(32);
    int sz = nums.size();

    auto update = [&](int t, bool plus = true) -> bool {
        // 从最低位开始，但是比较的时候要从最高位比较
        // 哪个大选哪个，因为是位运算，所以只要大于 0，就是相同的
        // 优化判断逻辑
        bool res = true, judge = false;
        for (int i = 31; i >= 0; i--) {
            int c = (t >> i) & 1, e = (k >> i) & 1;
            nvv[i] += plus ? c : -c;
            if (!judge) {
                if (nvv[i] > 0 && e == 0) {
                    res = judge = true;
                } else if (nvv[i] == 0 && e > 0) {
                    judge = true;
                    res = false;
                }
            }
        }

        return judge ? res : true;
    };

    int j = 0, res = INT_MAX;
    for (int i = 0; i < sz; i++) {
        bool isT = update(nums[i]);
        while (isT) {
            res = min(res, i - j + 1);
            if (j < i) {
                isT = update(nums[j++], 0);
            } else {
                break;
            }
        }
    }

    return res == INT_MAX ? -1 : res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumSubarrayLength({1, 2, 3}, 2) << endl;
    // 3
    cout << minimumSubarrayLength({2, 1, 8}, 10) << endl;
    // 1
    cout << minimumSubarrayLength({1, 2}, 0) << endl;
    // -1
    cout << minimumSubarrayLength({2, 1, 9, 12}, 21) << endl;
    // 1
    cout << minimumSubarrayLength({41}, 3) << endl;
    // 1
    cout << minimumSubarrayLength({3}, 3) << endl;
    // -1
    cout << minimumSubarrayLength({1, 64, 32, 97, 15, 2}, 122) << endl;

    return 0;
}
