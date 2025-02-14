#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistance(vector<int> position, int m) {
    // 思路：二分
    // 任意两个最小距离，简化成每个相邻之间的距离
    // 求最大值就是相邻之间距离的最大值
    // 时间 O(nlogn)，空间 O(1)

    // 不一定是相邻的，不是 1
    // if (position.size() == m) {
    //     return 1;
    // }

    sort(position.begin(), position.end());
    if (m == 2) {
        return position.back() - position[0];
    }

    int sz = position.size();
    // j 是能取到的最大值，m 个数，间距是 m - 1
    int i = 1, j = (position.back() - position[0]) / (m - 1);
    int res = 1;

    auto test = [&](int dis) -> bool {
        // pos 指向前一个
        int pos = 0, rem = m - 1;
        for (int i = 1; i < sz; i++) {
            if (position[i] >= position[pos] + dis) {
                if (res == 0) {
                    return true;
                }

                rem--; // 放一个
                pos = i;
            }
        }

        return rem <= 0;
    };

    while (i <= j) {
        int mid = i + ((j - i) >> 1);
        if (test(mid)) {
            res = max(res, mid);
            i = mid + 1; // 成立后再试更大值
        } else {
            j = mid - 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxDistance({1, 2, 3, 4, 7}, 3) << endl;
    // 999999999
    cout << maxDistance({5, 4, 3, 2, 1, 1000000000}, 2) << endl;
    // 10
    cout << maxDistance({14, 72, 20, 51, 38, 46, 81, 13, 10, 61}, 6) << endl;
    // 5
    cout << maxDistance({79, 74, 57, 22}, 4) << endl;

    return 0;
}
