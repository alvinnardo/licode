#include "../template/head.h"
#include <bits/stdc++.h>

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    // 思路：dijkstra
    // 单源有权有向最短路，贪心思想
    // 时间 O(mlogm)，空间 O(m + n)
    vector<vector<pair<int, int>>> edges(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    for (auto &t : times) {
        edges[t[0]].emplace_back(t[1], t[2]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    dist[k] = 0;
    pq.emplace(0, k);

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) {
            continue;
        }

        for (auto &e : edges[node]) {
            int newd = d + e.second;
            if (newd < dist[e.first]) {
                dist[e.first] = newd;
                pq.emplace(newd, e.first);
            }
        }

        // 用是否已经计算过进行判断
        /*
        if (dist[node] != INT_MAX) { // 已经到达了该点
            continue;
        }

        dist[node] = dt;
        for (const auto &it : edges[node]) {
            if (dist[it.second] == INT_MAX) { // 如果没有被访问过
                // 更新到各点的距离
                pq.emplace(dt + it.first, it.second);
            }
        }
        */
    }

    int maxv = *max_element(dist.begin() + 1, dist.end());
    return maxv == INT_MAX ? -1 : maxv;
}

int main(int argc, char *argv[]) {

    // 2
    cout << networkDelayTime({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2) << endl;
    // 1
    cout << networkDelayTime({{1, 2, 1}}, 2, 1) << endl;
    // -1
    cout << networkDelayTime({{1, 2, 1}}, 2, 2) << endl;
    // 3
    cout << networkDelayTime({{1, 2, 1}, {2, 3, 2}, {1, 3, 4}}, 3, 1) << endl;

    return 0;
}
