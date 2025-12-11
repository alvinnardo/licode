#include "../template/head.h"
#include <bits/stdc++.h>

int countCoveredBuildings(int n, vector<vector<int>> &&buildings) {
    // 题解：模拟
    // 时间 O(k)，空间 O(n)，k 是 buildings 个数

    // 只保存每行和每列的最大值和最小值即可
    vector<pair<int, int>> row(n + 1, {INT_MAX, INT_MIN});
    vector<pair<int, int>> col(n + 1, {INT_MAX, INT_MIN});

    int sz = buildings.size();
    for (int i = 0; i < sz; i++) {
        const auto &bd = buildings[i];
        row[bd[0]].first = min(row[bd[0]].first, bd[1]);
        row[bd[0]].second = max(row[bd[0]].second, bd[1]);
        col[bd[1]].first = min(col[bd[1]].first, bd[0]);
        col[bd[1]].second = max(col[bd[1]].second, bd[0]);
    }

    int res{};
    for (int i = 0; i < sz; i++) {
        const auto &bd = buildings[i];
        res += (bd[1] != row[bd[0]].first && bd[1] != row[bd[0]].second &&
                bd[0] != col[bd[1]].first && bd[0] != col[bd[1]].second);
    }

    return res;
}

int countCoveredBuildings1(int n, vector<vector<int>> &&buildings) {
    // 思路：哈希表 + 红黑树
    // 时间 O(klogk)，空间 O(k)，k 是 buildings 个数

    // 分别按行和列保存各点
    unordered_map<int, set<int>> row_map, col_map;
    int sz = buildings.size();
    for (int i = 0; i < sz; i++) {
        const auto &bd = buildings[i];
        row_map[bd[0]].insert(bd[1]);
        col_map[bd[1]].insert(bd[0]);
    }

    // 遍历各点，判断该点在不在行首 且 不在行尾 且 不在列首 且 不在列尾
    // 迭代器类型不能直接等，因为点互不相同，可以直接判断迭代器指向的值
    int res{};
    for (int i = 0; i < sz; i++) {
        const auto &bd = buildings[i];
        const auto &row_set = row_map[bd[0]];
        const auto &col_set = col_map[bd[1]];
        auto row_it = row_set.find(bd[1]);
        auto col_it = col_set.find(bd[0]);

        res += (*row_it != *row_set.begin() && *row_it != *row_set.rbegin() &&
                *col_it != *col_set.begin() && *col_it != *col_set.rbegin());
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << countCoveredBuildings(3, {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}})
         << endl;
    // 0
    cout << countCoveredBuildings(3, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}) << endl;
    // 1
    cout << countCoveredBuildings(5, {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}})
         << endl;

    return 0;
}
