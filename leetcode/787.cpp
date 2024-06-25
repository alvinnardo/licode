#include "../template/head.h"
#include <bits/stdc++.h>
int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst,
                      int k) {
    // 优化空间
    // 时间 O(ktn), 空间 O(n)，t 是每个城市平均航线数
    vector<int> dp(n, INT_MAX);
    vector<vector<pair<int, int>>> edges(n);
    for (auto &flight : flights) {
        edges[flight[0]].emplace_back(flight[1], flight[2]);
    }

    dp[src] = 0;

    vector<int> tmp = dp;
    for (int i = 1; i < k + 2; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[j] != INT_MAX) {
                for (auto &e : edges[j]) {
                    tmp[e.first] = min(tmp[e.first], dp[j] + e.second);
                }
            }
        }
        dp = tmp;
    }

    return dp[dst] == INT_MAX ? -1 : dp[dst];
}

int findCheapestPrice2(int n, vector<vector<int>> flights, int src, int dst,
                       int k) {
    // 优化：DP，转移方程 dp[i][j] = min(dp[i - 1][t] + cost[t][j])
    // 时间: O(ktn)，空间 O(kn)

    vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
    vector<vector<pair<int, int>>> edges(n);
    for (auto &flight : flights) {
        edges[flight[0]].emplace_back(flight[1], flight[2]);
    }

    dp[0][src] = 0;

    for (int i = 1; i < k + 2; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i - 1][j] != INT_MAX) {
                for (auto &e : edges[j]) {
                    dp[i][e.first] =
                        min(dp[i][e.first], dp[i - 1][j] + e.second);
                }
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < k + 2; i++) {
        if (dp[i][dst] < res) {
            res = dp[i][dst];
        }
    }
    return res == INT_MAX ? -1 : res;
}

int findCheapestPrice1(int n, vector<vector<int>> flights, int src, int dst,
                       int k) {
    // 思路：BFS + DP
    // 时间 O(kn)，空间 O(kn)
    // 按步骤层序遍历，如果到下一层花费更小，则可以继续尝试
    vector<vector<pair<int, int>>> edges(n);
    for (auto &flight : flights) {
        edges[flight[0]].emplace_back(flight[1], flight[2]);
    }

    queue<int> qu;
    qu.emplace(src);
    // k 个中转，则走 k + 1 步，加上初始 0，共 k + 2 个
    vector<vector<int>> cost(k + 2, vector<int>(n, INT_MAX));
    cost[0][src] = 0;

    int level = 0;
    while (!qu.empty()) {

        int cnt = qu.size();
        while (cnt--) {

            auto t = qu.front();
            qu.pop();

            // 走一步同时到达某个点
            for (auto &e : edges[t]) {
                int newd = e.second + cost[level][t];
                if (newd <= cost[level][e.first] &&
                    newd <= cost[level + 1][e.first]) {
                    cost[level + 1][e.first] = newd;
                    if (e.first != dst) {
                        qu.push(e.first);
                    }
                }
            }
        }

        level++; // 走一步
        if (level == k + 1) {
            break;
        }
    }

    // 考虑 k 没有走完的情况
    int minv = INT_MAX;
    for (int i = 0; i < k + 2; i++) {
        if (cost[i][dst] < minv) {
            minv = cost[i][dst];
        }
    }
    return minv == INT_MAX ? -1 : minv;
}

int main(int argc, char *argv[]) {

    // 700
    cout << findCheapestPrice(4,
                              {{0, 1, 100},
                               {1, 2, 100},
                               {2, 0, 100},
                               {1, 3, 600},
                               {2, 3, 200}},
                              0, 3, 1)
         << endl;
    // 200
    cout << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2,
                              1)
         << endl;
    // 500
    cout << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2,
                              0)
         << endl;
    // 6
    cout << findCheapestPrice(4, {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}},
                              0, 3, 1)
         << endl;
    // 1
    cout << findCheapestPrice(3, {{0, 1, 2}, {1, 2, 1}, {2, 0, 10}}, 1, 2, 1)
         << endl;

    // 7
    cout << findCheapestPrice(5,
                              {{0, 1, 5},
                               {1, 2, 5},
                               {0, 3, 2},
                               {3, 1, 2},
                               {1, 4, 1},
                               {4, 2, 1}},
                              0, 2, 2)
         << endl;

    return 0;
}
