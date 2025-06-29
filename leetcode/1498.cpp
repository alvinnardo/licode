#include "../template/head.h"
#include <bits/stdc++.h>

int numSubseq(vector<int> &&nums, int target) {
    // 思路：排序 + 二分 + 快速幂
    // 时间 O(nlogn)，空间 O(logn)
    // 以每个数字作为最小值，二分找到满足条件的最大值，
    // 则中间的都可以满足使成立的最大值，可以用公式求得

    // 示例 2 中给出可以重复子序列，则不需要考虑相同数字的影响

    sort(nums.begin(), nums.end());
    int sz = nums.size();
    long long res = 0;
    const int mod = 1e9 + 7;

    // 首项为 1, 公比为 2 的等比数列前 n 项和
    auto cal = [&](int cnt) {
        if (cnt == 0) {
            return 0;
        }

        // 需要考虑取模，用一个快速幂
        // 1 * (1 - 2^n) / (1 - 2) = 2^n - 1
        long long res = 1, base = 2;
        while (cnt) {
            if (cnt & 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            cnt >>= 1;
        }

        return (int)res - 1;
    };

    for (int i = 0; i < sz; i++) {
        // a + b <= target
        // b <= target - a 且 b >= a

        int newt = target - nums[i];
        if (newt < nums[i]) {
            continue;
        }
        auto pos =
            upper_bound(nums.begin(), nums.end(), newt) - nums.begin() - 1;
        if (pos < i) {
            continue;
        }

        // [i, i] 需要 +1
        // [i, i + 1] 2^0
        // [i, i + 2] 2^1
        res = (res + cal(pos - i) + 1) % mod;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << numSubseq({3, 5, 6, 7}, 9) << endl;
    // 6
    cout << numSubseq({3, 3, 6, 8}, 10) << endl;
    // 61
    cout << numSubseq({2, 3, 3, 4, 6, 7}, 12) << endl;

    return 0;
}
