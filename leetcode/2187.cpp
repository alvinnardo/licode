#include "../template/head.h"
#include <bits/stdc++.h>

long long minimumTime(vector<int> time, int totalTrips) {
    // 思路：二分
    // 时间 O(mlogn)，空间 O(1)
    // 时间最多就是 1e7 * 1e7，时间越长肯定能满足
    long long left = 1, right = 1e14, res = -1, total = totalTrips;

    auto check = [&](long long t) -> bool {
        long long cnt = 0;
        for (int i : time) {
            cnt += t / (long long)i;
        }

        return cnt >= total;
    };

    while (left <= right) {
        long long mid = left + ((right - left) >> 1);
        if (check(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimumTime({1, 2, 3}, 5) << endl;
    // 2
    cout << minimumTime({2}, 1) << endl;

    return 0;
}
