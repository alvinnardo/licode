#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// simple
bool searchMatrix_simple(vector<vector<int>> matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// one dimension
bool searchMatrix_one_dimen(vector<vector<int>> matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    // 对每一行二分查找
    for (int i = 0; i < m; i++) {
        auto pos = lower_bound(matrix[i].begin(), matrix[i].end(), target) -
                   matrix[i].begin();
        if (pos < n && matrix[i][pos] == target) {
            return true;
        }
    }
    return false;
}

// over runtime
bool searchMatrix_my(vector<vector<int>> matrix, int target) {
    // 二维二分查找
    // 将矩阵分成四部分
    // 左上一定小，右下一定大，左下和右上不一定
    function<bool(int, int, int, int)> dfs = [&](int ax, int ay, int bx,
                                                 int by) {
        if (ax > bx || ay > by) {
            return false;
        }

        int row_mid = ax + (bx - ax) / 2;
        int col_mid = ay + (by - ay) / 2;

        int t = matrix[row_mid][col_mid];
        if (t == target) {
            return true;
        } else if (target < t) {
            return dfs(ax, ay, row_mid - 1, col_mid - 1) ||
                   dfs(row_mid, ay, row_mid, col_mid - 1) ||
                   dfs(ax, col_mid, row_mid - 1, col_mid) ||
                   dfs(ax, col_mid + 1, row_mid - 1, by) ||
                   dfs(row_mid + 1, ay, bx, col_mid - 1);

        } else {
            return dfs(row_mid + 1, col_mid + 1, bx, by) ||
                   dfs(row_mid, col_mid + 1, row_mid, by) ||
                   dfs(row_mid + 1, col_mid, bx, col_mid) ||
                   dfs(ax, col_mid + 1, row_mid - 1, by) ||
                   dfs(row_mid + 1, ay, bx, col_mid - 1);
        }
        return false;
    };

    return dfs(0, 0, matrix.size() - 1, matrix[0].size() - 1);
}

// Z 型查找
// 时间 O(m + n)
bool searchMatrix(vector<vector<int>> matrix, int target) {
    // 从右上角开始
    // 如果更大，就向下
    // 如果更小，就向右
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
        if (target == matrix[x][y]) {
            return true;
        } else if (target > matrix[x][y]) {
            x++;
        } else {
            y--;
        }
    }

    return false;
}

int main(void) {
    // true
    printBool(searchMatrix({{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}},
                           5));
    // false
    printBool(searchMatrix({{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}},
                           20));
    // true
    printBool(searchMatrix({{1, 4, 7, 11, 15}}, 15));
    // false
    printBool(searchMatrix({{1}, {4}, {7}, {11}, {15}}, 16));
    // true
    printBool(searchMatrix({{-1000000000}, {4}, {7}, {11}, {1000000000}},
                           -1000000000));
    // true
    printBool(searchMatrix({{0}}, 0));
    // false
    printBool(searchMatrix({{0}}, 1));
    // false
    printBool(searchMatrix({{0}}, -1));
    // true
    printBool(searchMatrix({{1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15},
                            {16, 17, 18, 19, 20},
                            {21, 22, 23, 24, 25}},
                           5));

    return 0;
}
