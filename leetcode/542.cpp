#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> updateMatrix(vector<vector<int>> mat) {
    /* clang-format off */
    // 思路：层序遍历，先改成 -1，表示未处理过
    // 时间 O(mn)，空间 O(mn)
    /* clang-format on */
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> qu;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                qu.emplace(i, j);
            }
            mat[i][j] = -1;
        }
    }

    int val = -1;

    vector<pair<int, int>> steer{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!qu.empty()) {

        val++;
        int cnt = qu.size();
        while (cnt--) {
            auto [i, j] = qu.front();
            qu.pop();
            if (mat[i][j] != -1) {
                continue;
            }

            mat[i][j] = val;
            for (auto &st : steer) {
                int row = i + st.first, col = j + st.second;
                if (row >= 0 && row < m && col >= 0 && col < n) {
                    qu.emplace(row, col);
                }
            }
        }
    }

    return mat;
}

int main(int argc, char *argv[]) {
    // {{0,0,0},{0,1,0},{0,0,0}}
    printVectorVector(updateMatrix({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}));
    // {{0,0,0},{0,1,0},{1,2,1}}
    printVectorVector(updateMatrix({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}));
    printVectorVector(updateMatrix({{0, 0, 0, 0, 0},
                                    {0, 1, 1, 1, 0},
                                    {0, 1, 1, 1, 0},
                                    {0, 1, 1, 1, 0},
                                    {0, 0, 0, 0, 1}}));

    return 0;
}
