#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int change(int amount, const vector<int> &coins) {

    int sz = coins.size();
    // dp[1][i] 对应 coins[0]
    vector<vector<int>> dp(sz + 1, vector<int>(amount + 1));
    dp[0][0] = 1;
    for (int i = 1; i < sz + 1; i++) {
        for (int j = 0; j < amount + 1; j++) {
            if (j - coins[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[sz][amount];
}

int change_dfs(int amount, const vector<int> &coins) {
    // dp[i] = sum(dp[i-coins[j]])
    // 爬楼梯是排列数，该题是组合数，选或不选

    std::unordered_map<int, int> umap;
    function<int(int, int)> dfs = [&](int tot, int pos) {
        if (tot == 0) {
            return 1;
        } else if (tot < 0) {
            return 0;
        }

        if (pos < 0) {
            return 0;
        }

        int t = tot * 1000 + pos;
        if (umap.find(t) != umap.end()) {
            return umap[t];
        }

        int a = dfs(tot, pos - 1);
        int b = dfs(tot - coins[pos], pos); // 选了还可以继续选
        // cout << "tot: " << tot << ", pos: " << pos << ", a: " << a << ", b: "
        // << b << endl;
        umap[t] = a + b;
        return umap[t];
    };

    return dfs(amount, coins.size() - 1);
}

int main(void) {
    std::cout << change(5, {1, 2, 5}) << std::endl;
    std::cout << change(3, {2}) << std::endl;
    std::cout << change(10, {10}) << std::endl;
    std::cout << change(1000, {8, 9, 10, 20, 30, 50, 100}) << std::endl;

    return 0;
}
