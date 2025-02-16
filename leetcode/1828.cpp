#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> countPoints(vector<vector<int>> points,
                        vector<vector<int>> queries) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < points.size(); j++) {
            if ((queries[i][0] - points[j][0]) *
                        (queries[i][0] - points[j][0]) +
                    (queries[i][1] - points[j][1]) *
                        (queries[i][1] - points[j][1]) <=
                queries[i][2] * queries[i][2]) {
                cnt++;
            }
        }
        res[i] = cnt;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,2,2}
    printVector(countPoints({{1, 3}, {3, 3}, {5, 3}, {2, 2}},
                            {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}}));
    // {2,3,2,4}
    printVector(countPoints({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}},
                            {{1, 2, 2}, {2, 2, 2}, {4, 3, 2}, {4, 3, 3}}));

    return 0;
}
