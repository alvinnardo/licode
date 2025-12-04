#include "../template/head.h"
#include <bits/stdc++.h>

int largest1BorderedSquare(vector<vector<int>> &&grid) {
    // 思路：二维前缀和
    // 时间 O(m*n*min(m, n))，空间 O(mn)

    int m = grid.size(), n = grid[0].size();
    int up{}, left{}, xie{};
    vector<vector<int>> vec(m, vector<int>(n));
    // 生成二维前缀和数组
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            up = i > 0 ? vec[i - 1][j] : 0;
            left = j > 0 ? vec[i][j - 1] : 0;
            xie = i > 0 && j > 0 ? vec[i - 1][j - 1] : 0;
            vec[i][j] = grid[i][j] + up + left - xie;
        }
    }

    // 从 (0, 0) 到 (a, b) 的二维前缀和
    auto getNum = [&](int a, int b) {
        return a < 0 || b < 0 || a >= m || b >= n ? 0 : vec[a][b];
    };

    // 从 (a, b) 到 (c, d) 的二维前缀和
    auto getSquareNum = [&](int a, int b, int c, int d) {
        if (a > c || b > d) {
            return 0;
        }
        return getNum(c, d) - getNum(c, b - 1) - getNum(a - 1, d) +
               getNum(a - 1, b - 1);
    };

    int res{};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int md = min(i, j) + 1; // 遍历以 (i, j) 为右下角的正方形
            for (int k = 1; k <= md; k++) {
                // 1 的个数等于周长
                if (getSquareNum(i - k + 1, j - k + 1, i, j) -
                        getSquareNum(i - k + 2, j - k + 2, i - 1, j - 1) ==
                    (k == 1 ? 1 : ((k << 1) + ((k - 2) << 1)))) {
                    res = max(res, k);
                }
            }
        }
    }

    // 最后只乘一次，优化时间
    return res * res;
}

int main(int argc, char *argv[]) {
    // 9
    cout << largest1BorderedSquare({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}) << endl;
    // 1
    cout << largest1BorderedSquare({{1, 1, 0, 0}}) << endl;
    // 4
    cout << largest1BorderedSquare({{1, 1}, {1, 1}}) << endl;

    return 0;
}
