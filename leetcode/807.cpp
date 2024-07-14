#include "../template/head.h"
#include <bits/stdc++.h>

int maxIncreaseKeepingSkyline(vector<vector<int>> grid) {
    // 思路：贪心，找到每行和每一列的最大值
    // 再对每个元素进行遍历，达到行和列的最大值的最小值
    // 时间 O(n2)，空间 O(n)

    int n = grid.size();
    vector<int> row(n, INT_MIN);
    vector<int> col(n, INT_MIN);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row[i] = max(grid[i][j], row[i]);
            col[j] = max(grid[i][j], col[j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += min(row[i], col[j]) - grid[i][j];
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 35
    cout << maxIncreaseKeepingSkyline(
                {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}})
         << endl;
    // 0
    cout << maxIncreaseKeepingSkyline({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}})
         << endl;

    return 0;
}
