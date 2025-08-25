#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findDiagonalOrder(vector<vector<int>> &&mat) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int m = mat.size(), n = mat[0].size();
    int x{0}, y{0}, total{m * n};
    bool up{true};

    // 相当于绕圈测试哪边能走
    vector<vector<int>> up_test{{-1, 1}, {0, 1}, {1, 0}};
    vector<vector<int>> down_test{{1, -1}, {1, 0}, {0, 1}};

    vector<int> res;
    while (true) {
        res.push_back(mat[x][y]);
        if (res.size() == total) {
            break;
        }

        auto &vec = up ? up_test : down_test;
        int newx = -1, newy = -1, i{};
        for (; i < vec.size(); i++) {
            auto &t = vec[i];
            newx = x + t[0];
            newy = y + t[1];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                x = newx, y = newy;
                break;
            }
        }

        if (i != 0) { // 换方向了
            up = !up;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,2,4,7,5,3,6,8,9}
    cout << findDiagonalOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) << endl;
    // {1,2,3,4}
    cout << findDiagonalOrder({{1, 2}, {3, 4}}) << endl;
    printVector(findDiagonalOrder({{1, 2, 3, 4}}));
    printVector(findDiagonalOrder({{1}, {2}, {3}, {4}}));

    return 0;
}
