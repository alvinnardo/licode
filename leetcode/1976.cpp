#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 最短时间路径数

struct cmp {
    bool operator()(const pair<int, int64_t> &a, const pair<int, int64_t> &b) {
        return a.second > b.second;
    }
};

int countPaths_my(int n, const vector<vector<int>> &roads) {
    if (n == 1 || roads.empty())
        return 1;

    vector<vector<int>> nei(n, vector<int>(n, INT_MAX));
    for (auto &road : roads) {
        nei[road[0]][road[1]] = road[2];
        nei[road[1]][road[0]] = road[2];
    }

    priority_queue<pair<int, int64_t>, vector<pair<int, int64_t>>, cmp> pq;
    vector<int64_t> dist(n, LLONG_MAX);
    // 在队列中可能存在两个相同的节点值，虽然求最短路径时不会出错，
    // 但是求个数时会有问题，所以用 set
    vector<unordered_set<int>> path(n);

    // init
    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int node = t.first;
        int d = t.second;

        for (int i = 0; i < nei[node].size(); i++) {
            if (nei[node][i] != INT_MAX) {
                int64_t newd = dist[node] + nei[node][i];
                if (newd < dist[i]) {
                    dist[i] = newd;
                    path[i].clear();
                    path[i].insert(node);
                    pq.emplace(i, dist[i]);
                } else if (newd == dist[i]) {
                    path[i].insert(node);
                }
            }
        }
    }

    // 倒推
    unordered_map<int, int64_t> umap;
    function<int64_t(int)> dfs = [&](int x) -> int64_t {
        if (x == 0)
            return 1;
        if (umap.find(x) != umap.end())
            return umap[x];

        int64_t tot = 0;
        for (auto &c : path[x]) {
            tot = (tot + dfs(c) % 1000000007) % 1000000007;
        }

        umap[x] = tot;
        return tot;
    };

    return (int)dfs(n - 1);
}

using LL = long long;
int countPaths(int n, const vector<vector<int>> &roads) {
    const int64_t mod = 1e9;
    if (n == 1 || roads.empty())
        return 1;

    // 邻接表更好，这里就不写了
    vector<vector<int>> nei(n, vector<int>(n, INT_MAX));
    for (auto &road : roads) {
        nei[road[0]][road[1]] = road[2];
        nei[road[1]][road[0]] = road[2];
    }

    // <大小，节点>, 这样保存可以直接用 std::greater，根据大小排序
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                   std::greater<pair<int64_t, int>>>
        pq;
    vector<int64_t> dist(n, LLONG_MAX);
    // 用来保存个数，如果相等，加上父节点的；如果小于，等于父节点的
    vector<int64_t> ways(n);

    // init
    dist[0] = 0;
    ways[0] = 1;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int d = t.first;
        int node = t.second;

        // 有重复的节点，后一次的路径被更新成了更小的 dist，更大的就无效了
        // 能够避免重复统计路径
        if (d > dist[node]) {
            continue;
        }

        for (int i = 0; i < nei[node].size(); i++) {
            if (nei[node][i] != INT_MAX) {
                int64_t newd = dist[node] + nei[node][i];
                if (newd < dist[i]) {
                    dist[i] = newd;
                    ways[i] = ways[node];
                    pq.emplace(dist[i], i);
                } else if (newd == dist[i]) {
                    ways[i] = (ways[i] + ways[node]) % mod;
                }
            }
        }
    }

    return ways[n - 1];
}

int main(void) {
    cout << countPaths(7, {{0, 6, 7},
                           {0, 1, 2},
                           {1, 2, 3},
                           {1, 3, 3},
                           {6, 3, 3},
                           {3, 5, 1},
                           {6, 5, 1},
                           {2, 5, 1},
                           {0, 4, 5},
                           {4, 6, 2}})
         << endl;                                // 4
    cout << countPaths(2, {{1, 0, 10}}) << endl; // 1
    cout << countPaths(1, {{}}) << endl;         // 1
    cout << countPaths(5, {{0, 1, 1},
                           {1, 2, 4},
                           {0, 4, 3},
                           {3, 2, 5},
                           {3, 4, 1},
                           {3, 0, 5},
                           {1, 3, 1}})
         << endl; // 2

    vector<vector<int>> tmp;
    for (int i = 0; i < 200; i++) {
        vector<int> tt{i, i + 1, 1000000000};
        tmp.push_back(tt);
    }
    cout << countPaths(201, tmp) << endl;

    return 0;
}
