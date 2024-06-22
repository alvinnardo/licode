#include "../template/head.h"
#include <bits/stdc++.h>

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    // 思路：DFS 单源有权最短路径
    // 时间: O(eloge)，空间 O(e)
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
        auto &t = pq.top();
        auto d = t.first;
        auto node = t.second;
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
    }

    int maxv = INT_MIN;
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == INT_MAX) {
            return -1;
        } else if (dist[i] > maxv) {
            maxv = dist[i];
        }
    }
    return maxv;
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
