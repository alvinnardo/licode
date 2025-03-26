#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(n)
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    unordered_map<int, int> up, down;

    auto setV = [&](int i, int j) {
        int diff = j - i;
        up.clear();
        down.clear();
        int tj = j;
        while (tj + 1 < n && tj - diff + 1 < m) {
            down[grid[tj - diff + 1][tj + 1]]++;
            tj++;
        }

        bool minus = false;
        while (j - diff < m && j < n) {
            int newi = j - diff;
            if (!minus) {
                minus = true;
            } else {
                if (--down[grid[newi][j]] == 0) {
                    down.erase(grid[newi][j]);
                }
            }
            res[newi][j] = abs((int)up.size() - (int)down.size());
            up[grid[newi][j]]++;
            j++;
        }
    };

    for (int i = 0; i < m; i++) {
        setV(i, 0);
    }
    for (int j = 1; j < n; j++) {
        setV(0, j);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{1,1,0},{1,0,1},{0,1,1}}
    // printVectorVector(
    //     differenceOfDistinctValues({{1, 2, 3}, {3, 1, 5}, {3, 2, 1}}));
    // // {{0}}
    // printVectorVector(differenceOfDistinctValues({{1}}));
    // {{3,3,2,1,0},{3,2,1,0,1},{2,1,0,1,2},{1,0,1,2,3},{0,1,2,3,3}}
    printVectorVector(differenceOfDistinctValues({{23, 49, 2, 36, 5},
                                                  {45, 8, 16, 41, 26},
                                                  {38, 19, 38, 19, 46},
                                                  {25, 8, 37, 8, 37},
                                                  {29, 36, 19, 8, 21}}));

    return 0;
}
