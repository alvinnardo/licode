#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> findColumnWidth(vector<vector<int>> grid) {

    int m = grid.size(), n = grid[0].size();
    vector<int> res(n, INT_MIN);

    auto get_width = [&](int num) {
        if (num == 0) {
            return 1;
        }

        bool neg = num < 0 ? true : false;
        num = neg ? -num : num;

        int len = 0;
        while (num) {
            len++;
            num /= 10;
        }

        return neg ? len + 1 : len;
    };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[j] = max(res[j], get_width(grid[i][j]));
        }
    }

    return res;
}

int main(void) {
    // [3]
    printVector(findColumnWidth({{1}, {22}, {333}}));
    // [1]
    printVector(findColumnWidth({{0}, {0}, {0}}));
    // [11]
    printVector(findColumnWidth({{-1000000000}, {1000000000}, {0}}));
    // [3, 1, 2]
    printVector(findColumnWidth({{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}}));
    return 0;
}
