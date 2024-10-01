#include "../template/head.h"
#include <bits/stdc++.h>
int mincostTickets(vector<int> days, vector<int> costs) {
    // 思路：DP
    // 时间 O(mn)，空间 O(mn)
    int m = days.size(), n = costs.size();
    vector<int> end_pos(n);
    vector<int> dp(m, INT_MAX);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int end_day = days[i] + (j == 0 ? 1 : (j == 1 ? 7 : 30));
            int end_cost = (i == 0 ? 0 : dp[i - 1]) + costs[j];
            while (end_pos[j] < m && days[end_pos[j]] < end_day) {
                dp[end_pos[j]] = min(dp[end_pos[j]], end_cost);
                end_pos[j]++;
            }
        }
    }

    return dp[m - 1];
}

int mincostTickets1(vector<int> days, vector<int> costs) {
    // 思路：记忆化搜索
    // 从 pos 开始选择每种方案的最小值
    // 时间 O(mn)，空间 O(mn)

    int m = days.size(), n = costs.size();
    vector<vector<int>> vec(m, vector<int>(n, -1));
    auto getNum = [](int choose) {
        if (choose == 0) {
            return 1;
        } else if (choose == 1) {
            return 7;
        }

        return 30;
    };

    function<int(int, int)> dfs = [&](int pos, int choose) {
        if (vec[pos][choose] >= 0) {
            return vec[pos][choose];
        }

        int pre_end = days[pos] - getNum(choose);
        int tot = costs[choose];
        while (pos >= 0 && days[pos] > pre_end) {
            pos--;
        }

        if (pos < 0) {
            return tot;
        }

        // 这里要及时保存
        vec[pos][0] = dfs(pos, 0);
        vec[pos][1] = dfs(pos, 1);
        vec[pos][2] = dfs(pos, 2);
        return tot + min(min(vec[pos][0], vec[pos][1]), vec[pos][2]);
    };

    return min(min(dfs(m - 1, 0), dfs(m - 1, 1)), dfs(m - 1, 2));
}

int main(int argc, char *argv[]) {
    // 11
    cout << mincostTickets({1, 4, 6, 7, 8, 20}, {2, 7, 15}) << endl;
    // 17
    cout << mincostTickets({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, {2, 7, 15})
         << endl;
    // 6307
    cout << mincostTickets({10,  21,  55,  66,  83,  86,  89,  98,  108, 110,
                            113, 116, 124, 130, 131, 161, 186, 200, 221, 222,
                            225, 227, 243, 246, 263, 267, 316, 319, 330, 353},
                           {921, 571, 717})
         << endl;

    return 0;
}
