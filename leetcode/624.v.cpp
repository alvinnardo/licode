#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistance(vector<vector<int>> arrays) {
    // 思路：模拟
    // 保存第一大和第二大，第一小和第二小
    // 保存位置，如果相同，则选择一个即可
    // 时间 O(n)，空间 O(1)

    // 624.cpp 中写过更好的解法，用了点小窍门
    int maxv = INT_MIN, maxv2 = INT_MIN, minv2 = INT_MAX, minv = INT_MAX,
        max_pos = -1, min_pos = -1;
    for (int i = 0; i < arrays.size(); i++) {
        const auto &arr = arrays[i];
        int tmin = arr[0], tmax = arr.back();
        if (tmin <= minv2) {
            if (tmin <= minv) {
                minv2 = minv;
                minv = tmin;
                min_pos = i;
            } else {
                minv2 = tmin;
            }
        }

        if (tmax >= maxv2) {
            if (tmax >= maxv) {
                maxv2 = maxv;
                maxv = tmax;
                max_pos = i;
            } else {
                maxv2 = tmax;
            }
        }
    }

    return min_pos == max_pos ? max(maxv - minv2, maxv2 - minv) : maxv - minv;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxDistance({{1, 2, 3}, {4, 5}, {1, 2, 3}}) << endl;
    // 0
    cout << maxDistance({{1}, {1}}) << endl;
    // 30
    cout << maxDistance({{1, 2, 3}, {-10, 1, 20}, {-3, 2, 9}, {-10, 1, 20}})
         << endl;
    // 23
    cout << maxDistance({{1, 2, 3}, {-10, 1, 20}, {-3, 2, 9}}) << endl;
    // 1
    cout << maxDistance({{1}, {2}}) << endl;

    return 0;
}
