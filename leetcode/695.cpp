#include "../template/head.h"
#include <bits/stdc++.h>

int maxAreaOfIsland(vector<vector<int>> grid) {
    // 思路：BFS
    // 时间 O(mn)，空间 O(mn)
    int m = grid.size(), n = grid[0].size();
    int maxv = 0;
    vector<pair<int, int>> vec{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int cnt = 0;
                queue<pair<int, int>> qu;
                qu.emplace(i, j);
                while (!qu.empty()) {
                    auto t = qu.front();
                    qu.pop();
                    if (grid[t.first][t.second] != 1) {
                        continue;
                    } else {
                        grid[t.first][t.second] = 2;
                        cnt++;
                    }

                    for (auto &p : vec) {
                        int newi = t.first + p.first,
                            newj = t.second + p.second;
                        if (newi >= 0 && newi < m && newj >= 0 && newj < n &&
                            grid[newi][newj] == 1) {
                            qu.emplace(newi, newj);
                        }
                    }
                }
                maxv = max(maxv, cnt);
            }
        }
    }

    return maxv;
}

int main(int argc, char *argv[]) {

    // 6
    cout << maxAreaOfIsland({{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}})
         << endl;
    // 0
    cout << maxAreaOfIsland({{0, 0, 0, 0, 0, 0, 0, 0}}) << endl;

    return 0;
}
