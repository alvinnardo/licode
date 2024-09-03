#include "../template/head.h"
#include <bits/stdc++.h>

long long maxStrength(vector<int> nums) {
    // 思路：分类讨论
    // 时间 O(n)，空间 O(1)
    int sz = nums.size();
    long long res = LLONG_MIN;
    int neg_cnt = 0, opt_cnt = 0, maxv = INT_MIN, max_neg = INT_MIN;

    for (int num : nums) {
        neg_cnt += num < 0;
        opt_cnt += num > 0;
        maxv = max(maxv, num);
        max_neg = (num < 0 && num > max_neg) ? num : max_neg;

        if (num != 0) {
            if (res == LLONG_MIN) {
                res = 1;
            }
            res *= num;
        }
    }

    if (res == LLONG_MIN) { // 全是 0
        return maxv;
    } else if (res > 0) {
        return res;
    } else if (neg_cnt == 1) {
        if (opt_cnt > 0) { // 有正数，除以最大负数
            return res / max_neg;
        } else {
            return maxv;
        }
    }

    return res / max_neg;
}

int main(int argc, char *argv[]) {
    // 1350
    cout << maxStrength({3, -1, -5, 2, 5, -9}) << endl;
    // 20
    cout << maxStrength({-4, -5, -4}) << endl;

    return 0;
}
