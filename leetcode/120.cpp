#include "../template/head.h"
#include <bits/stdc++.h>

int minimumTotal(vector<vector<int>> &&triangle) {
    // 思路：DP
    // 时间 O(n)，空间 O(1)
    if (triangle.size() == 1) {
        return triangle[0][0];
    }

    int res = INT_MAX;
    for (int i = 1; i < triangle.size(); i++) {

        auto &line = triangle[i];
        for (int j = 0; j < line.size(); j++) {
            if (j == 0) {
                line[j] += triangle[i - 1][j];
            } else if (j == line.size() - 1) {
                line[j] += triangle[i - 1][j - 1];
            } else {
                line[j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }

            // 最后一行再求值
            if (i == triangle.size() - 1) {
                res = min(res, line[j]);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 11
    cout << minimumTotal({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}) << endl;
    // -10
    cout << minimumTotal({{-10}}) << endl;

    return 0;
}
