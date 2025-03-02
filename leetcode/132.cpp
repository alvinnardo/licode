#include "../template/head.h"
#include <bits/stdc++.h>

int minCut(string s) {
    // 思路：DP
    // 时间 O(n2)，空间 O(n2)
    vector<vector<bool>> is_hui_vec(s.length(),
                                    vector<bool>(s.length(), false));

    // 长度和起始位置
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (i == 1) {
                is_hui_vec[i - 1][j] = true;
            } else {
                int tail = j + i - 1;
                // 长度超了直接跳过
                if (tail >= s.length()) {
                    break;
                }
                if (i == 2) { // 两边相等
                    is_hui_vec[i - 1][j] = s[j] == s[tail];
                } else { // 两边相等且中间相等
                    is_hui_vec[i - 1][j] =
                        s[j] == s[tail] && is_hui_vec[i - 3][j + 1];
                }
            }
        }
    }

    vector<int> dp;
    // 最小分割次数
    // dp[i] = min{dp[i - j]} + 1
    for (int end = 0; end < s.length(); end++) {
        int minv = INT_MAX;
        for (int bng = 0; bng <= end; bng++) {
            int len = end - bng + 1;
            if (is_hui_vec[len - 1][bng]) {
                if (bng == 0) {
                    minv = 0;
                    break;
                } else {
                    // 因为每个字母就是一个回文
                    // 所以前面的 DP 不会有 INT_MAX
                    minv = min(minv, dp[bng - 1] + 1);
                }
            }
        }
        dp.push_back(minv);
    }

    return dp.back();
}

int main(int argc, char *argv[]) {
    // 1
    cout << minCut("aab") << endl;
    // 0
    cout << minCut("a") << endl;
    // 1
    cout << minCut("ab") << endl;

    return 0;
}
