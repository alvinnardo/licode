#include "../template/head.h"
#include <bits/stdc++.h>

long long maximumTotalDamage(vector<int> &&power) {
    // 思路：排序 + DP
    // 时间 O(nlogn)，空间 O(n)

    // t 是 power 值小于 power[i] - 2 所在的下标
    // 这是第一次写的递推方程：dp[i] = dp[t] + power[i];
    // 这是 WA 之后写的递推方程 dp[i] = dp[t] + power[i] * count[i]

    // 先排序，方便往前找小的
    std::ranges::sort(power);

    // 相同的值需要合并，因为 [7, 9, 9, 10, 10] 合并后可能威力更高
    vector<pair<long long, int>> unique_vec;
    for (int i = 0; i < power.size(); i++) {
        if (unique_vec.empty() || power[i] != unique_vec.back().first) {
            unique_vec.emplace_back(power[i], 1);
        } else {
            unique_vec.back().second++;
        }
    }

    int sz = unique_vec.size();
    vector<long long> dp(sz); // 保存以 i 为结尾的数组能形成的最大值

    for (int i = 0; i < sz; i++) {
        bool find = false;
        for (int j = 1; j <= 3; j++) {
            if (int t = i - j;
                t >= 0 && unique_vec[i].first - unique_vec[t].first > 2) {
                dp[i] = max(dp[i - 1],
                            dp[t] + unique_vec[i].first * unique_vec[i].second);
                find = true;
                break;
            }
        }
        if (!find) {
            long long t = unique_vec[i].first * unique_vec[i].second;
            dp[i] = i > 0 ? max(dp[i - 1], t) : t;
        }
    }

    return dp.back();
}

int main(int argc, char *argv[]) {
    // 6
    cout << maximumTotalDamage({1, 1, 3, 4}) << endl;
    // 13
    cout << maximumTotalDamage({7, 1, 6, 6}) << endl;
    // 31
    cout << maximumTotalDamage({5, 9, 2, 10, 2, 7, 10, 9, 3, 8}) << endl;

    return 0;
}
