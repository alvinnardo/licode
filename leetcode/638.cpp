#include "../template/head.h"
#include <bits/stdc++.h>

// 超时
int shoppingOffers(vector<int> price, vector<vector<int>> special,
                   vector<int> needs) {
    /* clang-format off */
    // 思路：DP + 哈希表，哈希表存放状态压缩值，将纵向多维转为横向多维
    // 转移方程为 f[a, b, c] = min(f[a, b, c], f[a - sp[0], b - sp[1], c - sp[2]] + sp[3])
    /* clang-format on */
    int sz = needs.size();

    auto getStr = [](const vector<int> &vec) {
        std::string res;
        for (auto &v : vec) {
            res += (char)('a' + v);
        }

        return res;
    };

    unordered_map<string, int> umap;
    vector<int> init(sz), tmp(sz);
    umap[getStr(init)] = 0;
    int res = 0;

    for (int i = 0; i < price.size(); i++) {
        init[i] = 1;
        special.push_back(init);
        special.back().push_back(price[i]);
        init[i] = 0;
    }

    function<void(int, int)> dfs = [&](int sp_pos, int pos) {
        if (pos == needs.size()) {
            string cur = getStr(init);
            bool valid = true;
            for (int i = 0; i < sz; i++) {
                tmp[i] = init[i] - special[sp_pos][i];
                if (tmp[i] < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                int t = INT_MAX;
                std::string tmp_str = getStr(tmp);
                if (umap.count(tmp_str)) {
                    t = min(t, umap[tmp_str] + special[sp_pos].back());
                }
                if (umap.count(cur)) {
                    t = min(t, umap[cur]);
                }

                if (t != INT_MAX) {
                    umap[cur] = t;
                }
            }

            return;
        }

        for (int i = 0; i <= needs[pos]; i++) {
            init[pos] = i;
            dfs(sp_pos, pos + 1);
        }
    };

    for (int i = 0; i < special.size(); i++) {
        // 最大 11 的 6 次方
        dfs(i, 0);
    }

    string res_str = getStr(needs);
    if (umap.count(res_str)) {
        return umap[res_str];
    }

    return 0;
}

int shoppingOffers1(vector<int> price, vector<vector<int>> special,
                    vector<int> needs) {
    // 思路：DP
    // 时间 O(n mul(k))，空间 O(mul(k))
    int sz = needs.size();
    int res = 0;
    if (sz == 1) {
        vector<int> dp(needs[0] + 1, INT_MAX);
        dp[0] = 0;

        special.push_back({1, price[0]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                if (a - special[i][0] >= 0 &&
                    dp[a - special[i][0]] != INT_MAX) {
                    dp[a] = min(dp[a], dp[a - special[i][0]] + special[i][1]);
                }
            }
        }

        res = dp[needs[0]];
    } else if (sz == 2) {
        vector<vector<int>> dp(needs[0] + 1,
                               vector<int>(needs[1] + 1, INT_MAX));
        dp[0][0] = 0;

        special.push_back({1, 0, price[0]});
        special.push_back({0, 1, price[1]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                for (int b = 0; b <= needs[1]; b++) {
                    if (a - special[i][0] >= 0 && b - special[i][1] >= 0 &&
                        dp[a - special[i][0]][b - special[i][1]] != INT_MAX) {
                        dp[a][b] = min(
                            dp[a][b], dp[a - special[i][0]][b - special[i][1]] +
                                          special[i][2]);
                    }
                }
            }
        }

        res = dp[needs[0]][needs[1]];
    } else if (sz == 3) {
        vector<vector<vector<int>>> dp(
            needs[0] + 1,
            vector<vector<int>>(needs[1] + 1,
                                vector<int>(needs[2] + 1, INT_MAX)));
        dp[0][0][0] = 0;

        special.push_back({1, 0, 0, price[0]});
        special.push_back({0, 1, 0, price[1]});
        special.push_back({0, 0, 1, price[2]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                for (int b = 0; b <= needs[1]; b++) {
                    for (int c = 0; c <= needs[2]; c++) {
                        if (a - special[i][0] >= 0 && b - special[i][1] >= 0 &&
                            c - special[i][2] >= 0 &&
                            dp[a - special[i][0]][b - special[i][1]]
                              [c - special[i][2]] != INT_MAX) {
                            dp[a][b][c] =
                                min(dp[a][b][c],
                                    dp[a - special[i][0]][b - special[i][1]]
                                      [c - special[i][2]] +
                                        special[i][3]);
                        }
                    }
                }
            }
        }

        res = dp[needs[0]][needs[1]][needs[2]];

    } else if (sz == 4) {
        vector<vector<vector<vector<int>>>> dp(
            needs[0] + 1,
            vector<vector<vector<int>>>(
                needs[1] + 1,
                vector<vector<int>>(needs[2] + 1,
                                    vector<int>(needs[3] + 1, INT_MAX))));
        dp[0][0][0][0] = 0;

        special.push_back({1, 0, 0, 0, price[0]});
        special.push_back({0, 1, 0, 0, price[1]});
        special.push_back({0, 0, 1, 0, price[2]});
        special.push_back({0, 0, 0, 1, price[3]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                for (int b = 0; b <= needs[1]; b++) {
                    for (int c = 0; c <= needs[2]; c++) {
                        for (int d = 0; d <= needs[3]; d++) {
                            if (a - special[i][0] >= 0 &&
                                b - special[i][1] >= 0 &&
                                c - special[i][2] >= 0 &&
                                d - special[i][3] >= 0 &&
                                dp[a - special[i][0]][b - special[i][1]]
                                  [c - special[i][2]][d - special[i][3]] !=
                                    INT_MAX) {
                                dp[a][b][c][d] = min(
                                    dp[a][b][c][d],
                                    dp[a - special[i][0]][b - special[i][1]]
                                      [c - special[i][2]][d - special[i][3]] +
                                        special[i][4]);
                            }
                        }
                    }
                }
            }
        }

        res = dp[needs[0]][needs[1]][needs[2]][needs[3]];

    } else if (sz == 5) {
        vector<vector<vector<vector<vector<int>>>>> dp(
            needs[0] + 1,
            vector<vector<vector<vector<int>>>>(
                needs[1] + 1,
                vector<vector<vector<int>>>(
                    needs[2] + 1,
                    vector<vector<int>>(needs[3] + 1,
                                        vector<int>(needs[4] + 1, INT_MAX)))));
        dp[0][0][0][0][0] = 0;

        special.push_back({1, 0, 0, 0, 0, price[0]});
        special.push_back({0, 1, 0, 0, 0, price[1]});
        special.push_back({0, 0, 1, 0, 0, price[2]});
        special.push_back({0, 0, 0, 1, 0, price[3]});
        special.push_back({0, 0, 0, 0, 1, price[4]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                for (int b = 0; b <= needs[1]; b++) {
                    for (int c = 0; c <= needs[2]; c++) {
                        for (int d = 0; d <= needs[3]; d++) {
                            for (int e = 0; e <= needs[4]; e++) {
                                if (a - special[i][0] >= 0 &&
                                    b - special[i][1] >= 0 &&
                                    c - special[i][2] >= 0 &&
                                    d - special[i][3] >= 0 &&
                                    e - special[i][4] >= 0 &&
                                    dp[a - special[i][0]][b - special[i][1]]
                                      [c - special[i][2]][d - special[i][3]]
                                      [e - special[i][4]] != INT_MAX) {
                                    dp[a][b][c][d][e] = min(
                                        dp[a][b][c][d][e],
                                        dp[a - special[i][0]][b - special[i][1]]
                                          [c - special[i][2]][d - special[i][3]]
                                          [e - special[i][4]] +
                                            special[i][5]);
                                }
                            }
                        }
                    }
                }
            }
        }

        res = dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]];

    } else if (sz == 6) {
        vector<vector<vector<vector<vector<vector<int>>>>>> dp(
            needs[0] + 1,
            vector<vector<vector<vector<vector<int>>>>>(
                needs[1] + 1,
                vector<vector<vector<vector<int>>>>(
                    needs[2] + 1,
                    vector<vector<vector<int>>>(
                        needs[3] + 1,
                        vector<vector<int>>(
                            needs[4] + 1,
                            vector<int>(needs[5] + 1, INT_MAX))))));
        dp[0][0][0][0][0][0] = 0;

        special.push_back({1, 0, 0, 0, 0, 0, price[0]});
        special.push_back({0, 1, 0, 0, 0, 0, price[1]});
        special.push_back({0, 0, 1, 0, 0, 0, price[2]});
        special.push_back({0, 0, 0, 1, 0, 0, price[3]});
        special.push_back({0, 0, 0, 0, 1, 0, price[4]});
        special.push_back({0, 0, 0, 0, 0, 1, price[5]});

        for (int i = 0; i < special.size(); i++) {
            for (int a = 0; a <= needs[0]; a++) {
                for (int b = 0; b <= needs[1]; b++) {
                    for (int c = 0; c <= needs[2]; c++) {
                        for (int d = 0; d <= needs[3]; d++) {
                            for (int e = 0; e <= needs[4]; e++) {
                                for (int f = 0; f <= needs[5]; f++) {
                                    if (a - special[i][0] >= 0 &&
                                        b - special[i][1] >= 0 &&
                                        c - special[i][2] >= 0 &&
                                        d - special[i][3] >= 0 &&
                                        e - special[i][4] >= 0 &&
                                        f - special[i][5] >= 0 &&
                                        dp[a - special[i][0]][b - special[i][1]]
                                          [c - special[i][2]][d - special[i][3]]
                                          [e - special[i][4]]
                                          [f - special[i][5]] != INT_MAX) {
                                        dp[a][b][c][d][e][f] =
                                            min(dp[a][b][c][d][e][f],
                                                dp[a - special[i][0]]
                                                  [b - special[i][1]]
                                                  [c - special[i][2]]
                                                  [d - special[i][3]]
                                                  [e - special[i][4]]
                                                  [f - special[i][5]] +
                                                    special[i][6]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        res = dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 14
    cout << shoppingOffers({2, 5}, {{3, 0, 5}, {1, 2, 10}}, {3, 2}) << endl;
    // 11
    cout << shoppingOffers({2, 3, 4}, {{1, 1, 0, 4}, {2, 2, 1, 9}}, {1, 2, 1})
         << endl;
    // 11
    cout << shoppingOffers({9}, {{1, 10}, {2, 2}}, {3}) << endl;

    return 0;
}
