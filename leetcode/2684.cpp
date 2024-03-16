#include <bits/stdc++.h>
using namespace std;

int maxMoves(vector<vector<int>> grid) {

    int maxv = 0;
    int m = grid.size(), n = grid[0].size();
    // vector<vector<int>> dp(m, vector<int>(n));
    // 优化空间
    vector<int> dp(m);

    for (int j = 1; j < n; j++) {
        vector<int> tmp = dp; // 有覆盖了，先做快照
        for (int i = 0; i < m; i++) {
            int t = 0;
            if (i - 1 >= 0 && grid[i - 1][j - 1] < grid[i][j]) {
                if (j == 1) {
                    t = 1;
                } else if (tmp[i - 1] == 0) {
                    t = max(t, 0);
                } else {
                    t = max(tmp[i - 1] + 1, t);
                }
            }
            if (grid[i][j - 1] < grid[i][j]) {
                if (j == 1) {
                    t = 1;
                } else if (tmp[i] == 0) {
                    t = max(t, 0);
                } else {
                    t = max(tmp[i] + 1, t);
                }
            }
            if (i + 1 < m && grid[i + 1][j - 1] < grid[i][j]) {
                if (j == 1) {
                    t = 1;
                } else if (tmp[i + 1] == 0) {
                    t = max(t, 0);
                } else {
                    t = max(tmp[i + 1] + 1, t);
                }
            }
            dp[i] = t;
            maxv = max(maxv, t);
        }
    }
    return maxv;
}

int main(void) {
    cout << maxMoves(
                {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}})
         << endl;
    cout << maxMoves({{3, 2, 4}, {2, 1, 9}, {1, 1, 7}}) << endl;

    return 0;
}
