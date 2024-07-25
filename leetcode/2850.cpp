#include "../template/head.h"
#include <bits/stdc++.h>

int minimumMoves(vector<vector<int>> grid) {
    // 思路：DFS
    // 1 个空位，1 种可能
    // 2 个空位，2 个多的位置，最多 4 种可能
    // 3 个空位，3 个多的位置，最多 27 种可能
    // 4 空，4 多，最多 256 种可能
    // 5 空，4 多，最多 1024
    // 6 空, 3 多，最多 729
    // 7 空，2 多，最多 128
    // 8 空，1 多，最多 8
    vector<pair<int, int>> kong;
    vector<vector<int>> you;
    int sz = grid.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (grid[i][j] == 0) {
                kong.emplace_back(i, j);
            } else if (grid[i][j] > 1) {
                you.push_back({i, j, grid[i][j] - 1});
            }
        }
    }

    int res = INT_MAX;
    function<void(int, int)> dfs = [&](int pos, int tot) {
        if (pos == kong.size()) {
            res = min(res, tot);
            return;
        }

        for (int i = 0; i < you.size(); i++) {
            if (you[i][2] > 0) {
                you[i][2]--;
                dfs(pos + 1, tot + abs(kong[pos].first - you[i][0]) +
                                 abs(kong[pos].second - you[i][1]));
                you[i][2]++;
            }
        }
    };

    dfs(0, 0);

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimumMoves({{1, 1, 0}, {1, 1, 1}, {1, 2, 1}}) << endl;
    // 4
    cout << minimumMoves({{1, 3, 0}, {1, 0, 0}, {1, 0, 3}}) << endl;
    // 0
    cout << minimumMoves({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}) << endl;

    return 0;
}
