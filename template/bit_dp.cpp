#include "../template/head.h"
#include <bits/stdc++.h>

int bit_dp(string s) {

    /* clang-format off */
    /**
       题目给出 《互不相同》
       1. 以 pos 为开始，能够生成数的个数
       2. mask 判断数字使用情况
       3. is_limit 是否上一位被限制住了，如果被限制，那么当前位也就被限制
       4. 注意前导 0 的情况，如果 mask = 0，且当前要填 0 时，不成立
    */

    /** 注意 is_limit 不用记忆化
       因为如果当前位被限制，那么前面的都被限制，只会计算一遍不会重复计算
       比如 s = 213，当 pos = 2 时，处理 0000000110 的情况，表示 12 被选中,
       如果前 2 位选中了 12，则 pos = 2 时，可以选 0 ~ 9
       如果前 2 位选中了 21，则 pos = 2 时，可以选 0 ~ 3
       全 limit 的这种情况是只有一种的，单独计算即可，不需要记忆化
       如果当前为是 limit，则之前的位也都是 limit
     */
    // 需要考虑前导零 和 位数限制两种情况
    /* clang-format on */
    vector<vector<int>> dp(s.size(), vector<int>(1 << 10, -1));
    function<int(int, int, bool)> dfs = [&](int pos, int mask, bool is_limit) {
        if (pos == s.length()) {
            // 如果都是前导 0，则没有放过数字
            // 否则返回 1，表示一个正常的数字
            return mask == 0 ? 0 : 1;
        }
        if (!is_limit && dp[pos][mask] >= 0) {
            return dp[pos][mask];
        }

        int res = 0;
        // 如果是前导 0，跳过当前位，表示继续尝试前导 0
        // 因为第一位跳过后，后面就没有限制了
        if (mask == 0) {
            res = dfs(pos + 1, mask, false);
        }

        int bng = mask ? 0 : 1, end = is_limit ? s[pos] - '0' : 9;
        for (; bng <= end; bng++) {
            // 这里使用右移，因为数字和数组的下标递增不同
            if (((mask >> bng) & 1) == 0) {
                // 之前 limit，且当前也选取到当前位最大，才限制住下一位
                res += dfs(pos + 1, mask | (1 << bng), is_limit && bng == end);
            }
        }

        if (!is_limit) {
            dp[pos][mask] = res;
        }
        return res;
    };

    return dfs(0, 0, true);
}

int main(int argc, char *argv[]) {
    // 10
    cout << bit_dp("10") << endl;
    // 10
    cout << bit_dp("11") << endl;

    return 0;
}
