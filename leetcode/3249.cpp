#include "../template/head.h"
#include <bits/stdc++.h>

int countGoodNodes(vector<vector<int>> edges) {
    // 思路：DFS
    // 时间 O(n)，空间 O(n2)
    // 建图
    int sz = edges.size();
    vector<vector<int>> neibor(sz + 1);
    for (int i = 0; i < sz; i++) {
        neibor[edges[i][0]].push_back(edges[i][1]);
        neibor[edges[i][1]].push_back(edges[i][0]);
    }

    int res = 0;

    // 所有可能子树，注意不是二叉树
    function<int(int, int)> dfs = [&](int node, int fa) {
        // 注意根节点没有父节点
        if (node != 0 && neibor[node].size() == 1) { // 只有父节点
            res++;
            return 1;
        }

        int first = 0, cnt = 0, tot = 0;
        for (int i = 0; i < neibor[node].size(); i++) {
            if (neibor[node][i] == fa) {
                continue;
            }

            int child = dfs(neibor[node][i], node);
            tot += child;
            if (first == 0) {
                first = child;
                cnt = 1;
            } else if (child != first) {
                cnt = 0;
            } else {
                cnt++;
            }
        }

        // 如果是根节点，则直接比较个数
        // 如果不是根节点，比较时需要去掉父节点
        res += cnt == neibor[node].size() - (node != 0);
        return tot + 1;
    };

    dfs(0, -1);
    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << countGoodNodes({{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}})
         << endl;
    // 12
    cout << countGoodNodes({{0, 1},
                            {1, 2},
                            {1, 3},
                            {1, 4},
                            {0, 5},
                            {5, 6},
                            {6, 7},
                            {7, 8},
                            {0, 9},
                            {9, 10},
                            {9, 12},
                            {10, 11}})
         << endl;
    // 6
    cout
        << countGoodNodes(
               {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}})
        << endl;
    // 2
    cout << countGoodNodes({{0, 1}}) << endl;
    // 3
    cout << countGoodNodes({{0, 1}, {0, 2}, {1, 3}}) << endl;

    return 0;
}
