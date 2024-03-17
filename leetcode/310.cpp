#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // 根据提示，一个树里面最多有几个最小高度树
    // 可以找到最长的链，如果最长链有奇数个节点，那么最小高度树就是一个
    // 如果最长链有偶数个节点，那么最小高度就是两个
    /*if (n == 1) {
        return {0};
    } else if (n == 2) {
        return {0, 1};
    }*/

    // 建树
    vector<vector<int>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].push_back(edge[1]);
        nei[edge[1]].push_back(edge[0]);
    }
    // 思路都有了，就是求最长叶子节点路径方法有问题
    // 看了题解，方法是： 1. 任意点为起点，找最长路径的终点 x
    // 再以 x 为起点，找最长路径的终点 y

    // 两次 BFS
    vector<int> parents(n); // 存放父节点
    auto bfs = [&](int node) {
        int last = node;
        queue<int> qu;
        qu.push(node);
        vector<int> visited(n);

        while (!qu.empty()) {
            auto t = qu.front();
            visited[t] = 1;
            last = t;
            qu.pop();

            for (auto c : nei[t]) {
                if (visited[c] == 0) {
                    qu.push(c);
                    parents[c] = t;
                }
            }
        }
        return last;
    };

    int x = bfs(0);
    int y = bfs(x);

    /*
    vector<int> path;
    path.push_back(x);
    vector<int> res;
    vector<int> visited(n);
    function<void(int, int)> dfs = [&](int node, int target) {
        if (node == target) {
            int mid = path.size() / 2;
            if (path.size() & 1) {
                res = {path[mid]};
            } else {
                res = {path[mid - 1], path[mid]};
            }
        }
        for (auto c : nei[node]) {
            if (visited[c] == 1) {
                continue;
            }

            path.push_back(c);
            visited[c] = 1;
            dfs(c, target);
            path.pop_back();
            visited[c] = 0;
        }
    };
    dfs(x, y);
    */

    // 遍历父节点
    vector<int> path;
    path[x] = -1;
    while (y != -1) {
        path.push_back(y);
        y = parents[y];
    }
    int mid = path.size() / 2;
    if (path.size() & 1) {
        return {path[mid]};
    }

    return {path[mid - 1], path[mid]};
}
