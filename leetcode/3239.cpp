#include "../template/head.h"
#include <bits/stdc++.h>

int minFlips(vector<vector<int>> grid) {
    // 思路：遍历
    // 时间 O(mn)，空间 O(1)
    int m = grid.size(), n = grid[0].size();
    int row = 0, col = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (n >> 1); j++) {
            col += grid[i][j] != grid[i][n - 1 - j];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < (m >> 1); i++) {
            row += grid[i][j] != grid[m - 1 - i][j];
        }
    }

    return min(row, col);
}

int main(int argc, char *argv[]) {
    // 2
    cout << minFlips({{1, 0, 0}, {0, 0, 0}, {0, 0, 1}}) << endl;
    // 1
    cout << minFlips({{0, 1}, {0, 1}, {0, 0}}) << endl;
    // 0
    cout << minFlips({{1}, {0}}) << endl;

    return 0;
}
