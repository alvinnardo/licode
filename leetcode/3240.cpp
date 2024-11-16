#include "../template/head.h"
#include <bits/stdc++.h>

int minFlips(vector<vector<int>> grid) {
    // 思路：分类讨论
    // 结果是 4 的倍数，其实要求的是最中间那个值必须是 0
    // 四周的变成 0 或 1 都是 4 的倍数，中间的行或列都变成 0 即可
    // 时间 O(mn)，空间 O(1)

    int m = grid.size(), n = grid[0].size();
    int one_cnt = 0, res = 0;
    for (int i = 0; i < (m >> 1); i++) {
        for (int j = 0; j < (n >> 1); j++) {
            one_cnt = 0;
            one_cnt += grid[i][j] == 1;
            one_cnt += grid[i][n - j - 1] == 1;
            one_cnt += grid[m - i - 1][j] == 1;
            one_cnt += grid[m - i - 1][n - j - 1] == 1;

            res += one_cnt <= 2 ? one_cnt : 4 - one_cnt;
        }
    }

    int t = 0, diff_cnt = 0;
    one_cnt = 0;
    if (m & 1) {
        t = m >> 1;
        for (int j = 0; j < (n >> 1); j++) {
            if (grid[t][j] != grid[t][n - j - 1]) {
                diff_cnt++;
            } else if (grid[t][j] == 1) {
                one_cnt++;
            }
        }
    }
    if (n & 1) {
        t = n >> 1;
        for (int i = 0; i < (m >> 1); i++) {
            if (grid[i][t] != grid[m - i - 1][t]) {
                diff_cnt++;
            } else if (grid[i][t] == 1) {
                one_cnt++;
            }
        }
    }

    // 把中间行和中间列不同的加上
    res += diff_cnt;
    // 中间行和中间列如果 1 的对数是 1 3 5，
    // 那么就需要把全变成 0 的改为有一对为 1
    if (diff_cnt == 0 && (one_cnt & 1)) {
        res += 2;
    }

    // 把中间的值加上
    return res + (int)((m & 1) && (n & 1) && (grid[m >> 1][n >> 1] == 1));
}

int main(int argc, char *argv[]) {
    // 3
    cout << minFlips({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) << endl;
    // 2
    cout << minFlips({{0, 1}, {0, 1}, {0, 0}}) << endl;
    // 2
    cout << minFlips({{1}, {1}}) << endl;

    return 0;
}
