#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfPairs(vector<vector<int>> &&points) {
    // 思路：排序 + 模拟
    // 时间 O(nlogn + n3)，空间 O(1)
    // 数据量不大，先按高度排序再暴力模拟即可
    int sz = points.size();
    sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] >= b[1];
    });

    int res{};
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (points[i][0] > points[j][0]) {
                continue;
            }

            bool valid = true;
            for (int k = 0; k < sz; k++) {
                if (k == i || k == j) {
                    continue;
                }

                if (points[k][0] >= points[i][0] &&
                    points[k][0] <= points[j][0] &&
                    points[k][1] >= points[j][1] &&
                    points[k][1] <= points[i][1]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 0
    cout << numberOfPairs({{1, 1}, {2, 2}, {3, 3}}) << endl;
    // 2
    cout << numberOfPairs({{6, 2}, {4, 4}, {2, 6}}) << endl;
    // 2
    cout << numberOfPairs({{3, 1}, {1, 3}, {1, 1}}) << endl;

    return 0;
}
