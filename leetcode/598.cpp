#include "../template/head.h"
#include <bits/stdc++.h>

int maxCount(int m, int n, vector<vector<int>> ops) {
    // 思路：统计
    // 都是从 0 开始，越小覆盖越多
    // 时间 O(n)，空间 O(1)
    int row = m, col = n;
    for (const auto &op : ops) {
        row = min(row, op[0]);
        col = min(col, op[1]);
    }

    return row * col;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxCount(3, 3, {{2, 2}, {3, 3}}) << endl;
    // 4
    cout << maxCount(3, 3,
                     {{2, 2},
                      {3, 3},
                      {3, 3},
                      {3, 3},
                      {2, 2},
                      {3, 3},
                      {3, 3},
                      {3, 3},
                      {2, 2},
                      {3, 3},
                      {3, 3},
                      {3, 3}})
         << endl;
    // 9
    cout << maxCount(3, 3, {}) << endl;
    // 6
    cout << maxCount(26, 17,
                     {{20, 10},
                      {26, 11},
                      {2, 11},
                      {4, 16},
                      {2, 3},
                      {23, 13},
                      {7, 15},
                      {11, 11},
                      {25, 13},
                      {11, 13},
                      {13, 11},
                      {13, 16},
                      {26, 17}})
         << endl;

    return 0;
}
