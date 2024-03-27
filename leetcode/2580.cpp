#include <bits/stdc++.h>
using namespace std;

int countWays(const vector<vector<int>> &ori_ranges) {
    // 1. 区间合并
    // 2. 快速幂
    // 时间: O(nlogn)
    // 空间: O(n)
    auto ranges = ori_ranges;

    sort(ranges.begin(), ranges.end(),
         [](const vector<int> &a, const vector<int> &b) {
             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });

    vector<vector<int>> vec;
    for (auto &range : ranges) {
        if (vec.empty()) {
            vec.emplace_back(range);
            continue;
        }

        auto &back = vec.back();
        if (back[1] < range[0]) { // 不能合并
            vec.emplace_back(range);
        } else if (back[1] < range[1]) { // 能合并, 比较后元素
            back[1] = range[1];
        } // 否则不变
    }

    int mod = 1e9 + 7;

    auto quickPower = [&](int num, int power) -> int {
        if (num == 1)
            return 1;

        long long res = 1;
        long long tmp = 1;
        while (power) {
            if (tmp == 1) {
                tmp = num;
            } else {
                tmp = (tmp * tmp) % mod;
            }
            if (power & 1) {
                res = (res * tmp) % mod;
            }
            power >>= 1;
        }
        return res;
    };
    // for (int i = 1; i <= 100; i++) {
    //     cout << i << ": " << quickPower(2, i) << endl;
    // }

    return quickPower(2, vec.size());
}

int main(void) {
    cout << countWays({{1, 5}, {4, 11}, {10, 20}}) << endl;

    return 0;
}
