#include "../template/head.h"
#include <bits/stdc++.h>

int minimumArea(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)
    int min_row = INT_MAX, max_row = INT_MIN;
    int min_col = INT_MAX, max_col = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j]) {
                cnt++;
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }

    return cnt == 0 ? 0 : (max_row - min_row + 1) * (max_col - min_col + 1);
}

int main(int argc, char *argv[]) {
    // 6
    cout << minimumArea({{0, 1, 0}, {1, 0, 1}}) << endl;
    // 1
    cout << minimumArea({{0, 0}, {1, 0}}) << endl;

    return 0;
}
