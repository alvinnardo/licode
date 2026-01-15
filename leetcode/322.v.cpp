#include <bits/stdc++.h>
using namespace std;

int coinChange2(vector<int> &&coins, int amount) {
    // 思路：DP
    // 时间 O(nk)，空间 O(k)
    // 往前减，最多 amount 个，初始值 amount + 1 即可
    int MAX = amount + 1;
    vector<int> vec(amount + 1, MAX);
    vec[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                vec[i] = min(vec[i], vec[i - coin] + 1);
            }
        }
    }

    return vec.back() == MAX ? -1 : vec.back();
}

int coinChange(vector<int> &&coins, int amount) {
    // 思路：DP
    // 时间 O(nk)，空间 O(k)
    // 往后加

    vector<int> vec(amount + 1, INT_MAX);
    vec[0] = 0;
    for (int i = 0; i <= amount; ++i) {
        if (vec[i] == INT_MAX) {
            continue;
        }

        long long t{};
        for (int coin : coins) {
            t = (long long)i + coin;
            if (t <= amount) {
                vec[t] = min(vec[t], vec[i] + 1);
            }
        }
    }

    return vec.back() == INT_MAX ? -1 : vec.back();
}

int coinChange1(vector<int> &&coins, int amount) {
    // 思路：DFS
    // 时间 O(nk)，空间 O(n)

    vector<int> vec(amount + 1, INT_MAX);
    std::function<int(int)> dfs = [&](int tot) {
        if (tot == 0) {
            return 0;
        } else if (tot < 0) {
            return -1;
        }

        int res = INT_MAX;

        int tmp{};
        for (int coin : coins) {
            int t{tot - coin};
            if (t < 0) {
                continue;
            }
            if (vec[t] == INT_MAX) {
                tmp = dfs(t);
                vec[t] = tmp;
            } else {
                tmp = vec[t];
            }

            if (tmp >= 0) {
                res = min(res, tmp + 1);
            }
        }

        return res == INT_MAX ? -1 : res;
    };

    return dfs(amount);
}

int main(void) {

    // 3
    cout << coinChange({1, 2, 5}, 11) << endl;
    // -1
    cout << coinChange({2, 3}, 1) << endl;
    // 0
    cout << coinChange({1}, 0) << endl;
    // 2000
    cout << coinChange({1, 2, 4, 5}, 10000) << endl;
    // 2
    cout << coinChange({1, 2147483647}, 2) << endl;

    return 0;
}
