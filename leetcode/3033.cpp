#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> modifiedMatrix(vector<vector<int>> matrix) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<vector<int>> res;
    int m = matrix.size(), n = matrix[0].size();
    for (int j = 0; j < n; j++) {
        int maxv = -1;
        for (int i = 0; i < m; i++) {
            maxv = max(maxv, matrix[i][j]);
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = maxv;
            }
        }
    }

    return matrix;
}

int main(int argc, char *argv[]) {
    // {{1,2,9},{4,8,6},{7,8,9}}
    printVectorVector(modifiedMatrix({{1, 2, -1}, {4, -1, 6}, {7, 8, 9}}));
    // {{3,2},{5,2}}
    printVectorVector(modifiedMatrix({{3, -1}, {5, 2}}));

    return 0;
}
