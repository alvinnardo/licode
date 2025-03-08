#include "../template/head.h"
#include <bits/stdc++.h>

long long maximumBeauty(vector<int> flowers, long long newFlowers, int target,
                        int full, int partial) {
    // 思路：贪心 + 模拟, 排序 + 二分
    // 时间 O(nlogn)，空间 O(n)

    // 这道题思路能想到，但中间有许多细节
    // 最大化最小值考虑二分
    sort(flowers.begin(), flowers.end());
    int sz = flowers.size();
    long long res = 0;
    vector<long long> need(sz); // 补花的个数

    // 补花到 target - 1，广义递增
    for (int i = 1; i < sz; i++) {
        if (flowers[i] == flowers[i - 1] || flowers[i - 1] >= target - 1) {
            need[i] = need[i - 1];
        } else {
            int t = min(flowers[i], target - 1);
            need[i] = need[i - 1] + (long long)(t - flowers[i - 1]) * i;
        }
    }

    // 逐次使前面的完善
    long long full_sum = 0;
    bool first = true;
    for (int i = sz; i >= 0; i--) {
        // 获取所有完善值
        while (i >= 1 && flowers[i - 1] >= target) {
            full_sum += full;
            i--;
        }

        // 使前面的完善
        if (!first) {
            if (newFlowers < target - flowers[i]) {
                break;
            }

            full_sum += full;
            newFlowers -= target - flowers[i];
        }

        first = false;
        // 剩余的新花补充后面，使最小值最大
        // 找第一个小于等于的位置
        int pos = upper_bound(need.begin(), need.begin() + i, newFlowers) -
                  need.begin() - 1;

        // need 的第一项是 0，所以 pos >= 0
        // 剩余的是否可以多几层
        long long min_level = 0;
        if (i > 0) {
            min_level =
                min((long long)flowers[pos] +
                        (long long)((newFlowers - need[pos]) / (pos + 1)),
                    (long long)target - 1);
        }
        res = max(res, full_sum + min_level * partial);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 14
    cout << maximumBeauty({1, 3, 1, 1}, 7, 6, 12, 1) << endl;
    // 30
    cout << maximumBeauty({2, 4, 5, 3}, 10, 5, 2, 6) << endl;
    // 32436
    cout << maximumBeauty({469, 349, 380, 477, 252, 916, 401, 230, 852, 575,
                           968, 571, 544, 612, 620, 813, 149, 316, 982, 721},
                          757, 411, 324, 68)
         << endl;
    // 3812
    cout << maximumBeauty({49, 46, 52, 93, 64, 74, 38, 79, 26, 61}, 68, 94, 72,
                          68)
         << endl;

    return 0;
}
