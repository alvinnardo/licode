#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> onesMinusZeros(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(m + n)
    int m = grid.size(), n = grid[0].size();
    vector<int> cols(n), rows(m);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += grid[i][j];
            cols[j] += grid[i][j];
        }

        rows[i] = cnt;
    }

    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{0,0,4},{0,0,4},{-2,-2,2}}
    printVectorVector(onesMinusZeros({{0, 1, 1}, {1, 0, 1}, {0, 0, 1}}));
    // {{5,5,5},{5,5,5}}
    printVectorVector(onesMinusZeros({{1, 1, 1}, {1, 1, 1}}));

    return 0;
}
