#include "../template/head.h"
#include <bits/stdc++.h>

int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
    // 思路：模拟 + DP
    // 时间 O(n2)，空间 O(n)
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> tmp(n);
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    tmp[j] = obstacleGrid[i][j] == 1 ? 0 : 1;
                } else if (obstacleGrid[i][j] == 0) {
                    tmp[j] = tmp[j - 1];
                } else {
                    tmp[j] = 0;
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        tmp[j] = 0;
                    }
                } else if (obstacleGrid[i][j] == 0) {
                    // 上一层加前一个
                    tmp[j] += tmp[j - 1];
                } else {
                    tmp[j] = 0;
                }
            }
        }
    }

    return tmp.back();
}

int main(int argc, char *argv[]) {
    // 2
    cout << uniquePathsWithObstacles({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << endl;
    // 1
    cout << uniquePathsWithObstacles({{0, 1}, {0, 0}}) << endl;

    return 0;
}
