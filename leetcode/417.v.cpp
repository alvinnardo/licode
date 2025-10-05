#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> pacificAtlantic(vector<vector<int>> &&heights) {
    // 思路：BFS
    // 时间 O(mn)，空间 O(mn)

    // 水往低处走，人往高出走
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> vv1(m, vector<int>(n)), vv2(m, vector<int>(n));
    vector<vector<int>> res;
    vector<pair<int, int>> tmp1, tmp2;
    // 初始化
    for (int i = 0; i < n; i++) {
        tmp1.emplace_back(0, i);
        tmp2.emplace_back(m - 1, i);
    }
    for (int i = 0; i < m; i++) {
        tmp1.emplace_back(i, 0);
        tmp2.emplace_back(i, n - 1);
    }

    vector<vector<int>> direct{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    auto run = [&](auto &tmp, auto &vv, int tag) {
        queue<pair<int, int>> qu;
        int newa{}, newb{};
        for (int i = 0; i < tmp.size(); i++) {
            auto [posa, posb] = tmp[i];
            if (vv[posa][posb] == tag) {
                continue;
            }

            qu.emplace(posa, posb);
            while (!qu.empty()) {
                auto [posa, posb] = qu.front();
                qu.pop();
                if (vv[posa][posb] == tag) {
                    continue;
                }
                vv[posa][posb] = tag;
                // 第二次遍历时直接生成结果，再次优化时间
                if (tag == 2 && vv1[posa][posb] == 1 && vv2[posa][posb] == 2) {
                    res.push_back({posa, posb});
                }

                for (auto &di : direct) {
                    newa = posa + di[0];
                    newb = posb + di[1];
                    if (newa >= 0 && newa < m && newb >= 0 && newb < n &&
                        vv[newa][newb] != tag &&
                        heights[newa][newb] >= heights[posa][posb]) {
                        qu.emplace(newa, newb);
                    }
                }
            }
        }
    };

    run(tmp1, vv1, 1);
    run(tmp2, vv2, 2);
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (vv1[i][j] == 1 && vv2[i][j] == 2) {
    //             res.push_back({i, j});
    //         }
    //     }
    // }

    return res;
}

int main(int argc, char *argv[]) {
    // {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}}
    cout << pacificAtlantic({{1, 2, 2, 3, 5},
                             {3, 2, 3, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {5, 1, 1, 2, 4}})
         << endl;
    // {{0,0},{0,1},{1,0},{1,1}}
    cout << pacificAtlantic({{2, 1}, {1, 2}}) << endl;

    return 0;
}
