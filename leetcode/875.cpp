#include "../template/head.h"
#include <bits/stdc++.h>

int minEatingSpeed(vector<int> piles, int h) {
    // 思路：二分
    // 时间 O(nlogn)，空间 O(1)

    // 最大是 max(piles)，每次吃一堆
    int r = *max_element(piles.begin(), piles.end());
    int l = 1;
    int res = 0;

    auto check = [&](int k) {
        long long cnt = 0;
        for (auto &p : piles) {
            cnt += ((p - 1) / k) + 1;
        }
        return cnt <= (long long)h;
    };

    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minEatingSpeed({3, 6, 7, 11}, 8) << endl;
    // 30
    cout << minEatingSpeed({30, 11, 23, 4, 20}, 5) << endl;
    // 23
    cout << minEatingSpeed({30, 11, 23, 4, 20}, 6) << endl;

    return 0;
}
