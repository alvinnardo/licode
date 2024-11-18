#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> imageSmoother(vector<vector<int>> img) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<vector<int>> nine_vec{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
                                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int m = img.size(), n = img[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    int newi = 0, newj = 0, t = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t = 0;
            for (const auto &it : nine_vec) {
                newi = i + it[0];
                newj = j + it[1];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    res[i][j] += img[newi][newj];
                    t++;
                }
            }
            res[i][j] /= t;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{0, 0, 0},{0, 0, 0}, {0, 0, 0}}
    printVectorVector(imageSmoother({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}));
    // {{137,141,137},{141,138,141},{137,141,137}}
    printVectorVector(
        imageSmoother({{100, 200, 100}, {200, 50, 200}, {100, 200, 100}}));

    return 0;
}
