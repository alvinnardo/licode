#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> generateMatrix(int n) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)，保存结果的不算
    vector<vector<int>> res(n, vector<int>(n));
    // 方向
    vector<vector<int>> direct{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    pair<int, int> cur{0, -1};
    int num = 1, pos = 0;
    for (int i = 0; i < n * n; i++) {
        while (true) {
            int new_row = cur.first + direct[pos][0];
            int new_col = cur.second + direct[pos][1];
            if (new_row >= n || new_row < 0 || new_col >= n || new_col < 0 ||
                res[new_row][new_col]) {
                pos = (pos + 1) % direct.size();
            } else {
                cur.first = new_row;
                cur.second = new_col;
                break;
            }
        }
        res[cur.first][cur.second] = num++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [[1,2,3],[8,9,4],[7,6,5]]
    printVectorVector(generateMatrix(3));
    // [[1]]
    printVectorVector(generateMatrix(1));

    return 0;
}
