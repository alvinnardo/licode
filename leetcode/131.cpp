#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<string>> partition(string s) {
    // 之前的一个提交
    // 我都怀疑我之前能写出这么优秀的代码
    // 时间 O(n2n)，空间 O(n2)
    // 用选或不选的思路

    // 判断是否是回文用 DP
    vector<vector<int>> vv(s.length(), vector<int>(s.length(), false));

    // 需要知道开头位置和长度
    // 横是长度，纵是开始位置
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (i == 1) {
                vv[i - 1][j] = true;
                continue;
            }
            int end = j + i - 1;
            if (end >= s.length()) {
                break;
            }

            vv[i - 1][j] =
                s[j] == s[end] && (i == 2 || i > 2 && vv[i - 2 - 1][j + 1]);
        }
    }

    vector<vector<string>> res;
    function<void(vector<string> &, int)> dfs = [&](vector<string> &tmp,
                                                    int pos) {
        if (pos >= s.length()) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = 1; i <= s.length() - pos; i++) {
            string t = s.substr(pos, i);
            // 依次判断以 pos 为起点，长度为 i 的子串是否是回文
            // 如果是，放入 tmp，并继续往后测试
            if (vv[t.length() - 1][pos]) {
                tmp.emplace_back(t);
                dfs(tmp, pos + i);
                tmp.pop_back();
            }
        }
    };

    vector<string> tmp;
    dfs(tmp, 0);
    return res;
}

vector<vector<string>> partition2(string s) {
    // 思路：DP
    // 判断是否是回文用 DP
    vector<vector<int>> vv(s.length(), vector<int>(s.length(), false));

    // 需要知道开头位置和长度
    // 横是长度，纵是开始位置
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (i == 1) {
                vv[i - 1][j] = true;
                continue;
            }
            int end = j + i - 1;
            if (end >= s.length()) {
                break;
            }

            vv[i - 1][j] =
                s[j] == s[end] && (i == 2 || i > 2 && vv[i - 2 - 1][j + 1]);
        }
    }

    // DP 获取所有可能结果
    // 用数字表示结束位置，减少空间
    vector<vector<vector<int>>> dp(s.length());
    for (int end = 0; end < s.length(); end++) {
        for (int bng = 0; bng <= end; bng++) {
            if (vv[end - bng][bng]) {
                if (bng == 0) {
                    dp[end].push_back({end});
                } else {
                    for (auto &it : dp[bng - 1]) {
                        dp[end].emplace_back(it);
                        dp[end].back().emplace_back(end);
                    }
                }
            }
        }
    }

    // 处理结果
    vector<vector<string>> res;
    for (auto &it : dp.back()) {
        res.emplace_back();
        string tmp;
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp += s[i];
            if (i == it[pos]) {
                pos++;
                res.back().emplace_back(tmp);
                tmp = "";
            }
        }
    }
    return res;
}

vector<vector<string>> partition1(string s) {
    // 思路：DP
    // 判断是否是字符串
    // 时间 O(n2)，空间 O(n2)
    vector<vector<int>> vv(s.length(), vector<int>(s.length(), -1));

    // 判断是否是回文串
    function<bool(int, int)> isHui = [&](int bng, int end) {
        if (vv[bng][end] != -1) {
            return vv[bng][end];
        }

        if (bng == end) {
            vv[bng][end] = 1;
            return vv[bng][end];
        } else if (bng == end - 1) {
            vv[bng][end] = s[bng] == s[end] ? 1 : 0;
            return vv[bng][end];
        }

        vv[bng][end] = s[bng] == s[end] && isHui(bng + 1, end - 1) ? 1 : 0;
        return vv[bng][end];
    };

    for (short end = 0; end < s.length(); end++) {
        for (short bng = 0; bng <= end; bng++) {
            isHui(bng, end);
        }
    }

    // DP 获取所有可能结果
    // 用数字表示结束位置，减少空间
    vector<vector<vector<short>>> dp(s.length());
    for (short end = 0; end < s.length(); end++) {
        for (short bng = 0; bng <= end; bng++) {
            if (isHui(bng, end)) {
                if (bng == 0) {
                    dp[end].push_back({end});
                } else {
                    for (auto &it : dp[bng - 1]) {
                        dp[end].emplace_back(it);
                        dp[end].back().emplace_back(end);
                    }
                }
            }
        }
    }

    // 处理结果
    vector<vector<string>> res;
    for (auto &it : dp.back()) {
        res.emplace_back();
        string tmp;
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp += s[i];
            if (i == it[pos]) {
                pos++;
                res.back().emplace_back(tmp);
                tmp = "";
            }
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {{"a","a","b"},{"aa","b"}}
    printVectorVector(partition("aab"));
    // {{"a"}}
    printVectorVector(partition("a"));

    return 0;
}
