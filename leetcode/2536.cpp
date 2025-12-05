#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &&queries) {
    // 思路：二维差分
    // 时间 O(k + n2)，空间 O(n2)
    vector<vector<int>> diff(n, vector<int>(n));
    vector<vector<int>> res(n, vector<int>(n));

    // 类似一维差分，起始位置 +，结束位置 -
    // 二维多减了，所以在相交点 +
    // 差分 计算前缀和 得到原数组

    auto modify = [&](int x, int y, int k) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return;
        }
        diff[x][y] += k;
    };

    for (auto &query : queries) {
        modify(query[0], query[1], +1);
        modify(query[0], query[3] + 1, -1);
        modify(query[2] + 1, query[1], -1);
        modify(query[2] + 1, query[3] + 1, +1);
    }

    int up{}, left{}, xie{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            up = i - 1 >= 0 ? res[i - 1][j] : 0;
            left = j - 1 >= 0 ? res[i][j - 1] : 0;
            xie = (i - 1 >= 0 && j - 1 >= 0) ? res[i - 1][j - 1] : 0;
            res[i][j] = diff[i][j] + up + left - xie;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{1,1,0},{1,2,1},{0,1,1}}
    cout << rangeAddQueries(3, {{1, 1, 2, 2}, {0, 0, 1, 1}}) << endl;
    // {{1,1},{1,1}}
    cout << rangeAddQueries(2, {{0, 0, 1, 1}}) << endl;

    return 0;
}
