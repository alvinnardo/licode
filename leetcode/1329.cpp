#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> diagonalSort(vector<vector<int>> mat) {
    // 思路：对所有对角线进行遍历，排序对角线上的元素
    // 时间 O(n), 空间 O(1)
    int bucket[101]; // 计数排序

    int m = mat.size(), n = mat[0].size();

    auto handle = [&](int i, int j) {
        memset(bucket, 0, sizeof(bucket));

        int p = i, q = j;
        while (p < m && q < n) {
            bucket[mat[p][q]]++;
            p++;
            q++;
        }

        int idx = 1;
        while (i < m && j < n) {
            while (bucket[idx] == 0) {
                idx++;
            }

            mat[i][j] = idx;
            bucket[idx]--;

            i++;
            j++;
        }
    };

    // 第一行
    for (int i = 0; i < n; i++) {
        handle(0, i);
    }

    // 第一列
    for (int i = 1; i < m; i++) {
        handle(i, 0);
    }

    return mat;
}

int main(int argc, char *argv[]) {

    printVectorVector(diagonalSort({{1}}));
    printVectorVector(diagonalSort({{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}}));
    printVectorVector(diagonalSort({{11, 25, 66, 1, 69, 7},
                                    {23, 55, 17, 45, 15, 52},
                                    {75, 31, 36, 44, 58, 8},
                                    {22, 27, 33, 25, 68, 4},
                                    {84, 28, 14, 11, 5, 50}}));

    return 0;
}
