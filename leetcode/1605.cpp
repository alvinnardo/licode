#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> restoreMatrix(vector<int> rowSum, vector<int> colSum) {
    // 思路：贪心
    // 每一行遍历，能放就放，最后肯定成立
    // sum(rowSum) == sum(colSum)
    // 时间 O(n2)，空间 O(1)
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rowSum[i] == 0) {
                break;
            }

            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{3,0}, {1,7}}
    printVectorVector(restoreMatrix({3, 8}, {4, 7}));
    // {{0,5,0}, {6,1,0}, {2,0,8}}
    printVectorVector(restoreMatrix({5, 7, 10}, {8, 6, 8}));
    // {{0,9,5}, {6,0,3}}
    printVectorVector(restoreMatrix({14, 9}, {6, 9, 8}));

    return 0;
}
