#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findDiagonalOrder(vector<vector<int>> mat) {

    // 思路：由于长和宽是不确定的，所以可以先保存下来，然后排序
    // 在同一条对角线上，和是相等的，如果和是偶数，行坐标从大到小；如果是奇数，行坐标从小到大
    // 看了一下结果，不用排序，遍历的时候按行优先，所以当要求和为相同值时，行小的自然在前面
    // 所以取结果的时候，奇数正序取数，偶数逆序取数
    // 时间 O(mn), 空间 O(mn)
    int m = mat.size(), n = mat[0].size();
    vector<vector<pair<int, int>>> tmp(m + n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i + j].emplace_back(i, j);
        }
    }

    vector<int> res;
    for (int i = 0; i < tmp.size(); i++) {
        if (i & 1) {
            for (int j = 0; j < tmp[i].size(); j++) {
                res.push_back(mat[tmp[i][j].first][tmp[i][j].second]);
            }
        } else {
            for (int j = tmp[i].size() - 1; j >= 0; j--) {
                res.push_back(mat[tmp[i][j].first][tmp[i][j].second]);
            }
        }
    }

    // for (auto &vec : tmp) {
    //     for (auto &p : vec) {
    //         cout << p.first << " " << p.second << ", ";
    //     }
    //     cout << endl;
    // }

    return res;
}

int main(int argc, char *argv[]) {
    // [1,2,4,7,5,3,6,8,9]
    printVector(findDiagonalOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
    // {1,2,3,4}
    printVector(findDiagonalOrder({{1, 2}, {3, 4}}));
    printVector(findDiagonalOrder({{1, 2, 3, 4}}));
    printVector(findDiagonalOrder({{1}, {2}, {3}, {4}}));

    return 0;
}
