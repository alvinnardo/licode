#include "../template/head.h"
#include <bits/stdc++.h>
#include <fstream>
int rotatedDigits(int n) {
    // 题解：数位 DP
    // 时间 O(10 * logn * 2^10)，空间 O(logn * 2^10)
    // 使用 数位DP 模板构造数字，其中 3 4 7 不能选

    string s = to_string(n);
    vector<vector<int>> dp(s.length(), vector<int>(1 << 10, -1));
    function<int(int, int, bool)> dfs = [&](int pos, int mask, bool is_limit) {
        if (pos == s.length()) {
            if ((mask >> 2) & 1 || (mask >> 5) & 1 || (mask >> 6) & 1 ||
                (mask >> 9) & 1) {
                return 1;
            }
            return 0;
        }

        if (!is_limit && dp[pos][mask] >= 0) {
            return dp[pos][mask];
        }

        int res = 0;
        if (mask == 0) {
            res = dfs(pos + 1, mask, false);
        }

        int bng = mask ? 0 : 1, end = is_limit ? s[pos] - '0' : 9;
        for (; bng <= end; bng++) {
            if (bng == 3 || bng == 4 || bng == 7) {
                continue;
            }
            res += dfs(pos + 1, mask | (1 << bng), is_limit && bng == end);
        }

        if (!is_limit) {
            dp[pos][mask] = res;
        }
        return res;
    };

    return dfs(0, 0, true);
}

int rotatedDigits1(int n) {
    // 思路：模拟
    // 时间：O(nlogn)，空间：O(logn)
    unordered_map<int, int> umap{{0, 0}, {1, 1}, {2, 5}, {5, 2},
                                 {6, 9}, {8, 8}, {9, 6}};

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        int before = i;
        string before_str = to_string(i), after_str;
        bool match = true;
        while (before) {
            int t = before % 10;
            if (!umap.count(t)) {
                match = false;
                break;
            }
            after_str += (char)('0' + umap[t]);
            before /= 10;
        }

        if (match) {
            reverse(after_str.begin(), after_str.end());
            if (before_str == after_str) {
                match = false;
            }
        }

        cnt += match;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 4
    cout << rotatedDigits(10) << endl;
    // 2320
    cout << rotatedDigits(10000) << endl;

    // ofstream foss("788.dat");
    // int bng = -1;
    // int num = -1;
    // int cnt = 0;
    // foss << "{";
    // for (int i = 0; i <= 10005; i++) {
    //     int t = rotatedDigits(i);
    //     if (t == num) {
    //         continue;
    //     } else {
    //         foss << "{" << bng << ", " << num << "},";
    //         // cout << bng << ": " << num << endl;
    //         cnt++;
    //         if (cnt % 20 == 0) {
    //             foss << endl;
    //         }
    //         bng = i;
    //         num = t;
    //     }
    // }
    // foss << "}";

    return 0;
}
