#include "../template/head.h"
#include <bits/stdc++.h>

int minSteps(int n) {
    // 题解：DP，从质因数转移过来
    // 时间 O(n√n)，空间 O(n)
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        // 对所有因子进行遍历
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[j] + i / j);
                dp[i] = min(dp[i], dp[i / j] + j);
            }
        }
    }

    return dp[n];
}

int minSteps_my(int n) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(n)
    vector<pair<int, unordered_set<int>>> vec(n + 1);
    vec[1].first = 0;
    vec[1].second.insert(0);

    // 有两种选择，可以直接 copy 或 翻倍 copy
    for (int i = 2; i <= n; i++) {
        vec[i].first = INT_MAX;
        for (int j = i - 1; j >= 1; j--) {
            // 复制 + copy
            if (i % j == 0) {
                int t = vec[j].first + (i - j) / j + 1;
                if (t == vec[i].first) {
                    vec[i].second.insert(j);
                } else if (t < vec[i].first) {
                    vec[i].first = t;
                    vec[i].second.clear();
                    vec[i].second.insert(j);
                }
            }

            if (j == 1) {
                continue;
            }

            // 直接 copy
            for (auto &it : vec[j].second) {
                if ((i - j) % it != 0) {
                    continue;
                }
                int t = vec[j].first + (i - j) / it;
                if (t == vec[i].first) {
                    vec[i].second.insert(it);
                } else if (t < vec[i].first) {
                    vec[i].first = t;
                    vec[i].second.clear();
                    vec[i].second.insert(it);
                }
            }
        }
    }

    return vec[n].first;
}

int main(int argc, char *argv[]) {
    // 0
    cout << minSteps(1) << endl;
    // 3
    cout << minSteps(3) << endl;
    // 5
    cout << minSteps(5) << endl;
    // 7
    cout << minSteps(7) << endl;
    // 6
    cout << minSteps(8) << endl;
    // 6
    cout << minSteps(9) << endl;

    return 0;
}
