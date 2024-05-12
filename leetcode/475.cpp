#include "../template/head.h"
#include <bits/stdc++.h>

int findRadius(vector<int> houses, vector<int> heaters) {

    // 思路：二分法，把范围先找出来，再检查能否包围
    // 时间 O(mlogm + nlogn + mlogk + nlogk), 空间 O(1)
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int pos = 0;
    int l = 0, r = 1e9; // 半径可以是 0
    int res = 0;
    while (l <= r) {
        pos = 0;
        int mid = l + ((r - l) >> 1);
        int kl = INT_MIN, kr = INT_MAX;
        for (int h : heaters) {
            if (kl == INT_MIN || h - mid > kr) {
                kl = h - mid;
                kr = h + mid;
            } else { // 合并区间
                kr = h + mid;
            }

            // 检查区间能够容纳的房屋
            if (pos == houses.size() || houses[pos] < kl) {
                break;
            } else {
                while (pos < houses.size() && houses[pos] <= kr) {
                    pos++;
                }
            }
        }

        if (pos == houses.size()) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << findRadius({1, 2, 3}, {2}) << endl;
    // 1
    cout << findRadius({1, 2, 3, 4}, {1, 4}) << endl;
    // 3
    cout << findRadius({1, 5}, {2}) << endl;
    // 0
    cout << findRadius({1}, {1, 2, 3, 4}) << endl;

    return 0;
}
