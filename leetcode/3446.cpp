#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> sortMatrix(vector<vector<int>> &&grid) {
    // 思路：模拟 + 排序
    // 时间 O(n2logn)，空间 O(n)
    int n = grid.size();
    vector<int> vec;

    auto handle = [&](int x, int y, bool less) {
        int p = x, q = y;
        while (p >= 0 && p < n && q >= 0 && q < n) {
            vec.push_back(grid[p++][q++]);
        }

        if (less) {
            std::ranges::sort(vec, std::less<int>());
        } else {
            std::ranges::sort(vec, std::greater<int>());
        }

        p = x, q = y;

        int i{};
        while (p >= 0 && p < n && q >= 0 && q < n) {
            grid[p++][q++] = vec[i++];
        }
        vec.clear();
    };

    for (int i = 0; i < n; i++) {
        handle(i, 0, false);
    }

    for (int i = 1; i < n; i++) {
        handle(0, i, true);
    }

    return grid;
}

int main(int argc, char *argv[]) {
    // {{8,2,3},{9,6,7},{4,5,1}}
    cout << sortMatrix({{1, 7, 3}, {9, 8, 2}, {4, 5, 6}}) << endl;
    // {{2,1},{1,0}}
    cout << sortMatrix({{0, 1}, {1, 2}}) << endl;
    // {{1}}
    cout << sortMatrix({{1}}) << endl;

    return 0;
}
