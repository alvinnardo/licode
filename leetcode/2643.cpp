#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> rowAndMaximumOnes(vector<vector<int>> mat) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<int> res(2);
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++) {
        int cnt = count_if(mat[i].begin(), mat[i].end(),
                           [](int a) { return a == 1; });
        if (cnt > res[1]) {
            res[0] = i;
            res[1] = cnt;
        }
    }

    return res;
}
int main(int argc, char *argv[]) {
    // {0,1}
    printVector(rowAndMaximumOnes({{0, 1}, {1, 0}}));
    // {1,2}
    printVector(rowAndMaximumOnes({{0, 0, 0}, {0, 1, 1}}));
    // {1,2}
    printVector(rowAndMaximumOnes({{0, 0}, {1, 1}, {0, 0}}));

    return 0;
}
