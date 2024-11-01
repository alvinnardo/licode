#include "../template/head.h"
#include <bits/stdc++.h>

// 只和前一个状态有关，可以进一步优化
long long maxEnergyBoost2(vector<int> energyDrinkA, vector<int> energyDrinkB) {
    // 思路：DP
    // 时间 O(n)，空间 O(n)
    int n = energyDrinkA.size();
    vector<vector<long long>> dp(2, vector<long long>(n));
    dp[0][0] = energyDrinkA[0];
    dp[1][0] = energyDrinkB[0];
    dp[0][1] = energyDrinkA[0] + energyDrinkA[1];
    dp[1][1] = energyDrinkB[0] + energyDrinkB[1];
    for (int i = 2; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 2]) + energyDrinkA[i];
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 2]) + energyDrinkB[i];
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

// 记忆化搜索过不了，应该和数据是 long long 有关
long long maxEnergyBoost(vector<int> energyDrinkA, vector<int> energyDrinkB) {
    // 思路：记忆化搜索
    // 时间 O(n)，空间 O(n)
    int n = energyDrinkA.size();

    vector<vector<long long>> vec(2, vector<long long>(n));
    function<long long(int, int)> dfs = [&](int choose, int pos) -> long long {
        if (pos < 0) {
            return 0;
        }

        if (vec[choose][pos] != 0) {
            return vec[choose][pos];
        }

        auto &t = choose ? energyDrinkB : energyDrinkA;
        long long res =
            max(dfs(choose, pos - 1), dfs(choose ^ 1, pos - 2)) + t[pos];
        vec[choose][pos] = res;
        return res;
    };

    return max(dfs(0, n - 1), dfs(1, n - 1));
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxEnergyBoost({1}, {3}) << endl;
    // 5
    cout << maxEnergyBoost({1, 3, 1}, {3, 1, 1}) << endl;
    // 7
    cout << maxEnergyBoost({4, 1, 1}, {1, 1, 3}) << endl;

    return 0;
}
