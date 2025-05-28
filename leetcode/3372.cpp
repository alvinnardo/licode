#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> maxTargetNodes(vector<vector<int>> edges1,
                           vector<vector<int>> edges2, int k) {
    // 思路：BFS
    // 时间 O(m2 + n2)，空间 O(max(m, n))

    // 计算第一棵树 k 路径，计算第 2 棵树的 k - 1 路径
    // 结果是第一棵树 k 路径 + 第 2 棵树最大值
    // 就是将最大的点直接连在第一棵树的每个点上
    int n = edges1.size() + 1, m = edges2.size() + 1;

    if (k == 0) {
        return vector<int>(n, 1);
    }
    vector<vector<int>> nei1(n), nei2(m);
    // 转图
    auto prep = [](auto &edges, auto &nei) {
        for (int i = 0; i < edges.size(); i++) {
            nei[edges[i][0]].push_back(edges[i][1]);
            nei[edges[i][1]].push_back(edges[i][0]);
        }
    };
    prep(edges1, nei1);
    prep(edges2, nei2);

    vector<int> node1(n), node2(m);
    auto getNum = [](int node, auto &nei, int len, auto &visited) {
        queue<int> qu; // 层次遍历
        qu.push(node);

        int res = 0;
        for (int i = 0; i < visited.size(); i++) {
            visited[i] = 0;
        }
        for (int i = 0; i <= len; i++) {
            int cnt = qu.size();
            if (cnt == 0) {
                break;
            }

            while (cnt--) {
                int t = qu.front();
                qu.pop();

                if (visited[t] == 0) {
                    res++;
                    visited[t] = 1;

                    for (int next : nei[t]) {
                        if (visited[next] == 0) {
                            qu.push(next);
                        }
                    }
                }
            }
        }

        return res;
    };

    auto func = [getNum](auto &nei, auto &node_cnt, int len, auto &visited) {
        int sz = node_cnt.size();
        for (int i = 0; i < sz; i++) {
            node_cnt[i] = getNum(i, nei, len, visited);
        }
    };

    vector<int> visited1(n), visited2(m);
    func(nei1, node1, k, visited1);
    func(nei2, node2, k - 1, visited2);

    int maxv = *max_element(node2.begin(), node2.end());
    for (int i = 0; i < n; i++) {
        node1[i] += maxv;
    }

    return node1;
}

int main(int argc, char *argv[]) {
    // {6,3,3,3,3}
    printVector(maxTargetNodes({{0, 1}, {0, 2}, {0, 3}, {0, 4}},
                               {{0, 1}, {1, 2}, {2, 3}}, 1));
    // {9,7,9,8,8}
    printVector(maxTargetNodes(
        {{0, 1}, {0, 2}, {2, 3}, {2, 4}},
        {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}}, 2));

    return 0;
}
