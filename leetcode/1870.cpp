#include "../template/head.h"
#include <bits/stdc++.h>

int minSpeedOnTime(vector<int> dist, double hour) {
    // 思路：二分
    // 速度越快越好，求最小速度
    // 时间 O(nlogk)，空间 O(1)
    int left = 1, right = 1e7;
    int res = -1, n = dist.size();
    auto can = [&](int speed) -> bool {
        double h = 0;
        for (int i = 0; i < n - 1; i++) {
            h += (int)(dist[i] / speed);
            if (dist[i] % speed) { // 整点发车
                h += 1;
            }
        }

        // 最后一段路到达即可
        h += 1.0 * dist.back() / speed;

        return h <= hour;
    };

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (can(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minSpeedOnTime({1, 3, 2}, 6) << endl;
    // 3
    cout << minSpeedOnTime({1, 3, 2}, 2.7) << endl;
    // -1
    cout << minSpeedOnTime({1, 3, 2}, 1.9) << endl;

    return 0;
}
