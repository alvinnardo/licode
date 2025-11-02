#include "../template/head.h"
#include <bits/stdc++.h>

int countUnguarded(int m, int n, vector<vector<int>> &&guards,
                   vector<vector<int>> &&walls) {
    // 思路：模拟 + 二分
    // 时间: O(mnlogk + plogp + qlogq)，空间 O(p + q)
    // p 是 guards 元素个数, q 是 walls 元素个数，
    // k 是每行或每列警卫和强的最大数量

    // 遍历格子，检查该行或该列是否有警卫且距离警卫间是否有墙
    // 找最近的警卫和最近的墙
    vector<vector<int>> guards_rows(m), guards_cols(n), walls_rows(m),
        walls_cols(n);

    auto init = [](const vector<vector<int>> &vv, vector<vector<int>> &dest1,
                   vector<vector<int>> &dest2) {
        for (auto &v : vv) {
            dest1[v[0]].push_back(v[1]);
            dest2[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < dest1.size(); i++) {
            std::ranges::sort(dest1[i]);
        }

        for (int i = 0; i < dest2.size(); i++) {
            std::ranges::sort(dest2[i]);
        }
    };

    // 横向和纵向
    init(guards, guards_rows, guards_cols);
    init(walls, walls_rows, walls_cols);

    auto check = [](int i, int j, auto &gv, auto &wv, bool pro) {
        if (gv[i].empty()) { // 该行或该列没有警卫
            return false;
        }

        if (pro) { // 正向
            // 找小于等于的，等于是用来判断当前位置是否有警卫或墙
            auto pos1 = std::upper_bound(gv[i].begin(), gv[i].end(), j) -
                        gv[i].begin() - 1;
            if (pos1 < 0 || gv[i][pos1] == j) { // 前面没有警卫或当前位有警卫
                return false;
            }

            auto pos2 = std::upper_bound(wv[i].begin(), wv[i].end(), j) -
                        wv[i].begin() - 1;
            if (pos2 < 0) { // 前面没有墙
                return true;
            } else if (wv[i][pos2] == j) { // 当前位是墙
                return false;
            }

            // 警卫的位置更近
            return gv[i][pos1] > wv[i][pos2];
        } else { // 负向
            // 找大于等于的
            auto pos1 =
                std::lower_bound(gv[i].begin(), gv[i].end(), j) - gv[i].begin();
            if (pos1 == gv[i].size() ||
                gv[i][pos1] == j) { // 后面没有警卫或当前位是警卫
                return false;
            }

            auto pos2 =
                std::lower_bound(wv[i].begin(), wv[i].end(), j) - wv[i].begin();
            if (pos2 == wv[i].size()) { // 后面没有墙
                return true;
            } else if (wv[i][pos2] == j) { // 当前位是墙
                return false;
            }

            // 警卫的位置更近
            return gv[i][pos1] < wv[i][pos2];
        }
    };

    int res{};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j, guards_rows, walls_rows, true) ||
                check(i, j, guards_rows, walls_rows, false) ||
                check(j, i, guards_cols, walls_cols, true) ||
                check(j, i, guards_cols, walls_cols, false)) {
                res++;
            }
        }
    }

    // 总数 - 保卫的个数 - 警卫的个数 - 墙的个数
    return m * n - res - guards.size() - walls.size();
}

int main(int argc, char *argv[]) {
    // 7
    cout << countUnguarded(4, 6, {{0, 0}, {1, 1}, {2, 3}},
                           {{0, 1}, {2, 2}, {1, 4}})
         << endl;
    // 4
    cout << countUnguarded(3, 3, {{1, 1}}, {{0, 1}, {1, 0}, {2, 1}, {1, 2}})
         << endl;

    return 0;
}
