#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findBall(vector<vector<int>> grid) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<int> res;

    int m = grid.size(), n = grid[0].size();
    auto simul = [&](int pos) {
        // 行
        for (int i = 0; i < m; i++) {
            if (grid[i][pos] == 1 && pos + 1 < n && grid[i][pos + 1] == 1) {
                pos++;
            } else if (grid[i][pos] == -1 && pos - 1 >= 0 &&
                       grid[i][pos - 1] == -1) {
                pos--;
            } else {
                pos = -1;
                break;
            }
        }

        return pos;
    };

    // 列
    for (int i = 0; i < n; i++) {
        res.emplace_back(simul(i));
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,-1,-1,-1,-1}
    printVector(findBall({{1, 1, 1, -1, -1},
                          {1, 1, 1, -1, -1},
                          {-1, -1, -1, 1, 1},
                          {1, 1, 1, 1, -1},
                          {-1, -1, -1, -1, -1}}));
    // {-1}
    printVector(findBall({{-1}}));
    // {0,1,2,3,4,-1}
    printVector(findBall({{1, 1, 1, 1, 1, 1},
                          {-1, -1, -1, -1, -1, -1},
                          {1, 1, 1, 1, 1, 1},
                          {-1, -1, -1, -1, -1, -1}}));

    return 0;
}
