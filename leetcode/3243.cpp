#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> queries) {
    // 思路：dijstra
    // 有向无权稀疏图
    // 时间 O(m2 + mn)，空间 O(m + n)
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        edges[i].push_back(i + 1);
    }

    int sz = queries.size();

    vector<int> dist;
    auto getLen = [&]() {
        dist.assign(n, INT_MAX);
        dist[0] = 0;

        queue<int> qu;
        qu.push(0);

        while (!qu.empty()) {
            int front = qu.front();
            qu.pop();

            for (int i : edges[front]) {
                if (dist[i] != INT_MAX) {
                    continue;
                }

                dist[i] = dist[front] + 1;
                qu.push(i);
            }
        }

        return dist.back();
    };

    vector<int> res(sz);
    for (int i = 0; i < sz; i++) {
        edges[queries[i][0]].push_back(queries[i][1]);
        res[i] = getLen();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3, 2, 1}
    printVector(shortestDistanceAfterQueries(5, {{2, 4}, {0, 2}, {0, 4}}));
    // {1, 1}
    printVector(shortestDistanceAfterQueries(4, {{0, 3}, {0, 2}}));

    return 0;
}
