#include "../template/head.h"
#include <bits/stdc++.h>

int numMagicSquaresInside(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(n2k)，空间 O(k)
    // 其实都是 45/3 = 15
    int m = grid.size(), n = grid[0].size();

    vector<int> tmp;
    auto check = [&](int row, int col) -> bool {
        if (row + 2 >= m || col + 2 >= n) {
            return false;
        }

        tmp.clear();
        tmp.assign(10, 0);

        int left =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int right =
            grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (left != right) {
            return false;
        }

        vector<int> row_sum(3), col_sum(3);
        int row_cnt = 0, col_cnt = 0;
        for (int i = row; i <= row + 2; i++) {
            col_cnt = 0;
            for (int j = col; j <= col + 2; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) {
                    return false;
                }
                if (tmp[grid[i][j]]) {
                    return false;
                }
                tmp[grid[i][j]]++;
                row_sum[row_cnt] += grid[i][j];
                col_sum[col_cnt++] += grid[i][j];
            }
            row_cnt++;
        }
        return row_sum[0] == row_sum[1] && row_sum[1] == row_sum[2] &&
               row_sum[2] == col_sum[0] && col_sum[0] == col_sum[1] &&
               col_sum[1] == col_sum[2] && col_sum[2] == left;
    };

    int res = 0;
    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            res += check(i, j);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << numMagicSquaresInside({{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}})
         << endl;
    // 0
    cout << numMagicSquaresInside({{8}}) << endl;

    return 0;
}
