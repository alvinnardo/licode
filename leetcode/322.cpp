#include <bits/stdc++.h>
using namespace std;

int coinChange(const vector<int> &coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (auto &c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int coinChange_my(const vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        int t = INT_MAX;
        for (auto &c : coins) {
            if (i - c < 0 || dp[i - c] == -1) {
                continue;
            }

            t = min(t, dp[i - c] + 1);
        }

        if (t != INT_MAX) {
            dp[i] = t;
        }
    }
    return dp[amount];
}

int main(void) {

    cout << coinChange({1, 2, 5}, 11) << endl;
    ;
    cout << coinChange({2, 3}, 1) << endl;
    ;
    cout << coinChange({1}, 0) << endl;
    ;
    cout << coinChange({1, 2, 4, 5}, 10000) << endl;
    ;

    return 0;
}
