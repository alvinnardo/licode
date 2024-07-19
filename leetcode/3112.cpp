#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> minimumTime(int n, vector<vector<int>> edges,
                        vector<int> disappear) {
    // 思路：dijkstra，之前能够到达的就能继续往后走
    // 时间 O(eloge)，空间 O(loge)
    vector<vector<pair<int, int>>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].emplace_back(edge[1], edge[2]);
        nei[edge[1]].emplace_back(edge[0], edge[2]);
    }

    vector<long long> vec(n, LLONG_MAX);
    vec[0] = 0;

    auto cmp = [&](const vector<int> &a, const vector<int> &b) {
        if (vec[a[0]] == LLONG_MAX && vec[b[0]] == LLONG_MAX) {
            return a[2] > b[2];
        } else if (vec[a[0]] == LLONG_MAX) {
            return false;
        } else if (vec[b[0]] == LLONG_MAX) {
            return true;
        }

        return vec[a[0]] + a[2] > vec[b[0]] + b[2];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < nei[0].size(); i++) {
        pq.push({0, nei[0][i].first, nei[0][i].second});
    }

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        // 之前有路径可以到达
        if (vec[t[1]] != LLONG_MAX) {
            continue;
        }

        // 超时消失
        auto time = vec[t[0]] + t[2];
        if (time >= disappear[t[1]]) {
            continue;
        }

        vec[t[1]] = min(vec[t[1]], time);
        for (int i = 0; i < nei[t[1]].size(); i++) {
            if (vec[nei[t[1]][i].first] == LLONG_MAX) {
                pq.push({t[1], nei[t[1]][i].first, nei[t[1]][i].second});
            }
        }
    }

    vector<int> res(n);
    for (int i = 0; i < vec.size(); i++) {
        res[i] = vec[i] == LLONG_MAX ? -1 : vec[i];
    }

    return vector<int>(res);
}

int main(int argc, char *argv[]) {

    // {0,-1,4}
    printVector(minimumTime(3, {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}}, {1, 1, 5}));
    // {0,2,3}
    printVector(minimumTime(3, {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}}, {1, 3, 5}));
    // {0,-1}
    printVector(minimumTime(2, {{0, 1, 1}}, {1, 1}));

    // {0,1,8,7,5}
    printVector(minimumTime(5,
                            {{3, 1, 6},
                             {1, 4, 4},
                             {1, 0, 4},
                             {3, 3, 4},
                             {2, 2, 9},
                             {2, 4, 3},
                             {0, 1, 1},
                             {3, 2, 3}},
                            {13, 8, 20, 12, 11}));

    return 0;
}
