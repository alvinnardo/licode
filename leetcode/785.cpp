#include "../template/head.h"
#include <bits/stdc++.h>

bool isBipartite(vector<vector<int>> graph) {
    // 思路：BFS，层次遍历
    // 时间 O(m + n)，空间 O(n)，m 是边的个数，n 是点的个数

    unordered_map<int, int> umap;

    queue<int> qu;

    auto handle = [&]() -> bool {
        int level = 0;

        while (!qu.empty()) {

            int cnt = qu.size();
            while (cnt--) {

                int t = qu.front();
                qu.pop();
                if (!umap.count(t)) {
                    umap[t] = level % 2;
                } else if (level % 2 != umap[t]) {
                    return false;
                }

                for (int e : graph[t]) {
                    if (!umap.count(e)) {
                        qu.emplace(e);
                    }
                }
            }
            level++;
        }

        return true;
    };

    for (int i = 0; i < graph.size(); i++) {
        if (umap.count(i)) {
            continue;
        }

        qu.emplace(i);
        if (!handle()) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 0
    cout << isBipartite({{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}) << endl;
    // 1
    cout << isBipartite({{1, 3}, {0, 2}, {1, 3}, {0, 2}}) << endl;
    // 0
    cout << isBipartite({{1, 3},
                         {0, 2},
                         {1, 3},
                         {0, 2},
                         {5, 6, 7},
                         {4, 6},
                         {4, 5, 7},
                         {4, 6}})
         << endl;
    // 1
    cout
        << isBipartite(
               {{1, 3}, {0, 2}, {1, 3}, {0, 2}, {5, 7}, {4, 6}, {5, 7}, {4, 6}})
        << endl;

    return 0;
}
