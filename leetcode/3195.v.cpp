#include "../template/head.h"
#include <bits/stdc++.h>

int minimumArea(vector<vector<int>> &&grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int left{INT_MAX}, right{INT_MIN}, up{INT_MAX}, down{INT_MIN};
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                left = min(left, j);
                right = max(right, j);
                up = min(up, i);
                down = max(down, i);
            }
        }
    }

    return (right - left + 1) * (down - up + 1);
}

int main(int argc, char *argv[]) {
    // 6
    cout << minimumArea({{0, 1, 0}, {1, 0, 1}}) << endl;
    // 1
    cout << minimumArea({{0, 0}, {1, 0}}) << endl;

    return 0;
}
