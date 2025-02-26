#include "../template/head.h"
#include <bits/stdc++.h>

int largestOverlap(vector<vector<int>> img1, vector<vector<int>> img2) {
    // 思路：模拟
    // 往左上，往左下，往右上，往右下
    // 时间 O(n4)，空间 O(1)，因为 n <= 30，所以 8e5 的复杂度还可以

    int n = img1.size();
    int res = 0;

    auto compare = [&](const vector<int> &a, const vector<int> &b) -> int {
        // a 是图 1 的左上和右下点
        // b 是图 2 的左上和右下点
        int cnt = 0;

        int diff_x = b[0] - a[0], diff_y = b[1] - a[1];
        for (int x = a[0]; x <= a[2]; x++) {
            for (int y = a[1]; y <= a[3]; y++) {
                cnt += img1[x][y] == 1 && img2[x + diff_x][y + diff_y] == 1;
            }
        }

        return cnt;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, compare({0, 0, n - 1 - j, n - 1 - i},
                                   {j, i, n - 1, n - 1}));
            res = max(res, compare({j, 0, n - 1, n - 1 - i},
                                   {0, i, n - 1 - j, n - 1}));
            res = max(res, compare({0, i, n - 1 - j, n - 1},
                                   {j, 0, n - 1, n - 1 - i}));
            res = max(res, compare({j, i, n - 1, n - 1},
                                   {0, 0, n - 1 - j, n - 1 - i}));
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << largestOverlap({{1, 1, 0}, {0, 1, 0}, {0, 1, 0}},
                           {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}})
         << endl;
    // 1
    cout << largestOverlap({{1}}, {{1}}) << endl;
    // 0
    cout << largestOverlap({{0}}, {{0}}) << endl;

    return 0;
}
