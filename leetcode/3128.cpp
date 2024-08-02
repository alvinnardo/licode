#include "../template/head.h"
#include <bits/stdc++.h>

long long numberOfRightTriangles(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        long long pre = 0, next = 0;
        for (int j = 0; j < n; j++) {
            int right = n - 1 - j;
            if (grid[i][j] >= 1) {
                grid[i][j] += pre;
                pre++;
            }

            if (grid[i][right] >= 1) {
                grid[i][right] += next;
                next++;
            }
        }
    }

    // printVectorVector(grid);
    long long sum = 0;
    for (int j = 0; j < n; j++) {
        long long pre = 0, next = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] >= 1) {
                sum += pre;
                if (grid[i][j] >= 2) {
                    pre += grid[i][j] - 1;
                }
            }

            int down = m - 1 - i;
            if (grid[down][j] >= 1) {
                sum += next;
                if (grid[down][j] >= 2) {
                    next += grid[down][j] - 1;
                }
            }
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 2
    cout << numberOfRightTriangles({{0, 1, 0}, {0, 1, 1}, {0, 1, 0}}) << endl;
    // 0
    cout << numberOfRightTriangles({{1, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}})
         << endl;
    // 2
    cout << numberOfRightTriangles({{1, 0, 1}, {1, 0, 0}, {1, 0, 0}}) << endl;
    // 6
    cout << numberOfRightTriangles({{1, 1, 1}, {1, 0, 1}}) << endl;

    return 0;
}
