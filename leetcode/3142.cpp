#include "../template/head.h"
#include <bits/stdc++.h>

bool satisfiesConditions(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    // 先查第一行
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    return false;
                }
            } else {
                if (grid[i][j] != grid[i - 1][j]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << satisfiesConditions({{1, 0, 2}, {1, 0, 2}}) << endl;
    // 0
    cout << satisfiesConditions({{1, 1, 1}, {0, 0, 0}}) << endl;
    // 0
    cout << satisfiesConditions({{1}, {2}, {3}}) << endl;

    return 0;
}
