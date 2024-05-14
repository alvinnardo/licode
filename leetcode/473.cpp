#include "../template/head.h"
#include <bits/stdc++.h>
bool makesquare(vector<int> matchsticks) {
    // 思路：状压 DP
    // 时间 O(n * 2^n)，空间 O(2^n)
    int sum = 0, maxv = INT_MIN, sz = matchsticks.size();
    if (sz < 4) {
        return false;
    }
    for (int i = 0; i < sz; i++) {
        sum += matchsticks[i];
        if (matchsticks[i] > maxv) {
            maxv = matchsticks[i];
        }
    }
    sort(matchsticks.begin(), matchsticks.end());

    // 当总和不是 4 的倍数，或者最长边比最后分割的最长边要长，则不成立
    if (sum % 4 != 0 || maxv > sum / 4) {
        return false;
    }

    vector<int> dp(1 << sz);
    int every = sum / 4;

    function<bool(int, int)> dfs = [&](int status, int cur) {
        if (status == 0) {
            return true;
        }

        if (dp[status] != 0) {
            return dp[status] == 1 ? true : false;
        }

        // status 中的 1 表示可以用
        bool res = false;
        for (int i = 0; i < matchsticks.size(); i++) {
            if (status & (1 << i) && matchsticks[i] + cur <= every) {
                if (dfs(status ^ (1 << i), (matchsticks[i] + cur) % every)) {
                    res = true;
                    break;
                }
            }
        }

        dp[status] = res ? 1 : -1;
        return res;
    };

    return dfs((1 << sz) - 1, 0);
}
bool makesquare2(vector<int> matchsticks) {
    // 思路: DFS，先检查是否能够拆成两部分
    // 如果可以再分别检查能否再分成两部分
    // 时间 O(n2^n), 空间 O(n2)
    int sum = 0, maxv = INT_MIN, sz = matchsticks.size();
    if (sz < 4) {
        return false;
    }
    for (int i = 0; i < sz; i++) {
        sum += matchsticks[i];
        if (matchsticks[i] > maxv) {
            maxv = matchsticks[i];
        }
    }
    sort(matchsticks.begin(), matchsticks.end());

    // 当总和不是 4 的倍数，或者最长边比最后分割的最长边要长，则不成立
    if (sum % 4 != 0 || maxv > sum / 4) {
        return false;
    }

    // 用来存放成立的边
    vector<vector<int>> vv;
    auto hasCheck = [&](const vector<int> &vec) {
        for (auto &vele : vv) {
            if (vele.size() == vec.size()) {
                int flag = true;
                for (int i = 0; i < vec.size(); i++) {
                    if (vele[i] != vec[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }

        return false;
    };

    bool res = false;
    vector<int> tmp, tmp2, tmp3;

    function<bool(int, int, int, vector<int> &, bool)> dfs =
        [&](int pos, int cur, int target, vector<int> &ori, bool check) {
            if (cur == target) {
                if (check && !hasCheck(tmp)) {
                    vv.emplace_back(tmp);
                    tmp2.clear();
                    tmp3.clear();
                    int pos = 0;
                    for (int stick : matchsticks) {
                        if (pos >= tmp.size() || stick != tmp[pos]) {
                            tmp2.push_back(stick);
                        } else {
                            pos++;
                        }
                    }
                    tmp3 = tmp;
                    if (!res) {
                        res = dfs(0, 0, cur / 2, tmp2, false) &&
                              dfs(0, 0, cur / 2, tmp3, false);
                    }
                }
                // 第一层直接返回 true，需要保存第二层的结果到 res 中
                return true;
            }
            if (pos == ori.size()) {
                return false;
            }

            int no_put = dfs(pos + 1, cur, target, ori, check);
            tmp.push_back(ori[pos]);
            int put = dfs(pos + 1, cur + ori[pos], target, ori, check);
            tmp.pop_back();
            return no_put || put;
        };

    dfs(0, 0, sum / 2, matchsticks, true);
    return res;
}

// 贪心不行，错误用例 {10, 6, 5, 5, 5, 3, 3, 3, 2, 2, 2, 2}
bool makesquare_wrong(vector<int> matchsticks) {

    // 思路：排序 + 贪心
    // 时间 O(nlogn), 空间 O(1)
    sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
    int edges[4]{};

    auto getMinPos = [&]() {
        int minv = INT_MAX, min_pos = -1;
        for (int i = 0; i < 4; i++) {
            if (edges[i] < minv) {
                minv = edges[i];
                min_pos = i;
            }
        }
        return min_pos;
    };

    for (auto stick : matchsticks) {
        edges[getMinPos()] += stick;
    }

    return edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3];
}

int main(int argc, char *argv[]) {
    // 0
    cout << makesquare({3, 3, 3, 3, 4}) << endl;
    // 1
    cout << makesquare({3, 3, 3, 3}) << endl;
    // 1
    cout << makesquare({2, 2, 2, 1, 1}) << endl;
    // 1
    cout << makesquare({10, 6, 5, 5, 5, 3, 3, 3, 2, 2, 2, 2}) << endl;
    // 1
    cout << makesquare({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1})
         << endl;
    // 0
    cout << makesquare({2, 2, 2, 2, 2, 2}) << endl;
    // 1
    cout << makesquare({2, 2, 4, 4, 1, 3}) << endl;
    // 0
    cout << makesquare({2, 3, 4, 4, 3}) << endl;

    return 0;
}
