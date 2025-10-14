#include "../template/head.h"
#include <bits/stdc++.h>

int maxIncreasingSubarrays(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 直接模拟就行
    // 考虑 b 是连续两个的长度，a 和 b 是两个的长度
    int res{}, sz = nums.size();
    int a{}, b{};
    for (int i = 0; i < sz; i++) {
        if (i == 0 || nums[i] - nums[i - 1] > 0) {
            b++;
        } else {
            a = b;
            b = 1;
        }

        res = max(res, max((b >> 1), min(a, b)));
    }

    return res;
}
int maxIncreasingSubarrays1(vector<int> &&nums) {
    // 思路：二分
    // 时间 O(nlogn)，空间 O(1)
    int sz = nums.size();
    int l = 1, r = sz >> 1, mid{};
    int res{};
    auto check = [&](int t) {
        int a{}, b{}, dt = t << 1;
        for (int i = 0; i < sz; i++) {
            if (i == 0 || nums[i] - nums[i - 1] > 0) {
                b++;
            } else {
                a = b;
                b = 1;
            }

            if (b >= dt || a >= t && b >= t) {
                return true;
            }
        }
        return false;
    };

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxIncreasingSubarrays({2, 5, 7, 8, 9, 2, 3, 4, 3, 1}) << endl;
    // 2
    cout << maxIncreasingSubarrays({1, 2, 3, 4, 4, 4, 4, 5, 6, 7}) << endl;

    return 0;
}
