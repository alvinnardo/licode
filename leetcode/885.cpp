#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                    int cStart) {
    // 思路：模拟
    // 时间 O(max(m, n) * max(m, n))，空间 O(1)

    vector<vector<int>> res;

    vector<vector<int>> direct{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int pos = 0, tot = rows * cols;

    int pre = 1, cur = 1;
    res.push_back({rStart, cStart});
    while (res.size() < tot) {
        rStart += direct[pos][0];
        cStart += direct[pos][1];
        cur--;
        if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
            res.push_back({rStart, cStart});
        }

        if (cur == 0) {
            pos = (pos + 1) % 4;
            if (pos == 2 || pos == 0) {
                cur = ++pre;
            } else {
                cur = pre;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{0,0},{0,1},{0,2},{0,3}}
    printVectorVector(spiralMatrixIII(1, 4, 0, 0));
    // {{1,4},{1,5},{2,5},{2,4},{2,3},{1,3},{0,3},{0,4},{0,5},{3,5},{3,4},{3,3},{3,2},{2,2},{1,2},{0,2},{4,5},{4,4},{4,3},{4,2},{4,1},{3,1},{2,1},{1,1},{0,1},{4,0},{3,0},{2,0},{1,0},{0,0}}
    printVectorVector(spiralMatrixIII(5, 6, 1, 4));

    return 0;
}
