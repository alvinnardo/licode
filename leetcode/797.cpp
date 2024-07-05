#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    // 思路：DFS
    // 时间 O(nk)，k 是每个点平均边数，空间 O(n)
    // 时间最坏是 O(n*2^n)
    vector<vector<int>> res;

    int sz = graph.size();

    vector<int> tmp{0};
    function<void(int)> dfs = [&](int pos) {
        if (pos == sz - 1) {
            res.push_back(tmp);
            return;
        }

        for (int i : graph[pos]) {
            tmp.push_back(i);
            dfs(i);
            tmp.pop_back();
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    // {{0,1,3},{0,2,3}}
    printVectorVector(allPathsSourceTarget({{1, 2}, {3}, {3}, {}}));
    // {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}
    printVectorVector(
        allPathsSourceTarget({{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}}));
    printVectorVector(allPathsSourceTarget(
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
         {7, 8, 9, 10, 11, 12, 13, 14, 15},
         {8, 9, 10, 11, 12, 13, 14, 15},
         {9, 10, 11, 12, 13, 14, 15},
         {10, 11, 12, 13, 14, 15},
         {11, 12, 13, 14, 15},
         {12, 13, 14, 15},
         {13, 14, 15},
         {14, 15},
         {15},
         {}}));

    return 0;
}
