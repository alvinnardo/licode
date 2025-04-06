#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    // 思路：DFS
    // 时间 O(e)，空间 O(h)

    vector<vector<int>> res;

    int tail = graph.size() - 1;
    function<void(vector<int> &)> dfs = [&](vector<int> &vec) {
        if (vec.back() == tail) {
            res.emplace_back(vec);
            return;
        }

        for (int n : graph[vec.back()]) {
            vec.push_back(n);
            dfs(vec);
            vec.pop_back();
        }
    };

    vector<int> vec{0};
    dfs(vec);
    return res;
}

int main(int argc, char *argv[]) {
    // {{0,1,3},{0,2,3}}
    printVectorVector(allPathsSourceTarget({{1, 2}, {3}, {3}, {}}));
    // {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}
    printVectorVector(
        allPathsSourceTarget({{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}}));

    return 0;
}
