#include "../template/head.h"
#include <bits/stdc++.h>

int areaOfMaxDiagonal(vector<vector<int>> &&dimensions) {
    // 思路：遍历
    // 时间 O(n)，空间 O(1)

    int maxv = INT_MIN, res = INT_MIN;
    for (int i = 0; i < dimensions.size(); i++) {
        auto t = dimensions[i][0] * dimensions[i][0] +
                 dimensions[i][1] * dimensions[i][1];
        if (t > maxv) { // 对角线长的面积不一定大，根据题目要求走
            res = dimensions[i][0] * dimensions[i][1];
            maxv = t;
        } else if (t == maxv) {
            res = max(res, dimensions[i][0] * dimensions[i][1]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 48
    cout << areaOfMaxDiagonal({{9, 3}, {8, 6}}) << endl;
    // 12
    cout << areaOfMaxDiagonal({{3, 4}, {4, 3}}) << endl;

    return 0;
}
