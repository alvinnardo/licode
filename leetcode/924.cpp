#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

int minMalwareSpread(vector<vector<int>> graph, vector<int> initial) {
    // 思路：并查集，统计最多个数的集合，最后得到该集合中索引最小的
    // O(n2logn)
    int n = graph.size();
    vector<int> ufs(n);
    iota(ufs.begin(), ufs.end(), 0);

    function<int(int)> find_ufs = [&](int idx) {
        if (ufs[idx] != idx) {
            ufs[idx] = find_ufs(ufs[idx]);
        }

        return ufs[idx];
    };

    auto union_ufs = [&](int a, int b) {
        int a_fa = find_ufs(a);
        int b_fa = find_ufs(b);
        ufs[b_fa] = a_fa;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j] == 1) {
                union_ufs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        find_ufs(i);
    }

    // 找到感染的集合
    unordered_set<int> uset_node, uset_fa;
    for (auto i : initial) {
        uset_node.insert(i);
        uset_fa.insert(ufs[i]);
    }

    // 记录祖父，{节点个数，感染源个数}
    int minv = -1;
    vector<vector<int>> map_vec(n);
    for (int i = 0; i < n; i++) {
        // 该集合未被感染
        if (uset_fa.find(ufs[i]) == uset_fa.end()) {
            continue;
        }

        // 感染集合中节点个数
        if (map_vec[ufs[i]].empty()) {
            map_vec[ufs[i]] = {1, 0};
        } else {
            map_vec[ufs[i]][0]++;
        }

        // 感染集合中感染源节点个数
        if (uset_node.find(i) != uset_node.end()) {
            map_vec[ufs[i]][1]++;
            // 第一个最小索引的感染源，如果没有单感染源的集合，就用该结果
            if (minv == -1) {
                minv = i;
            }
        }
    }

    // 找单感染源的
    int maxv = INT_MIN;
    unordered_set<int> ans_fa; // 存父节点
    for (int i = 0; i < n; i++) {
        if (!map_vec[i].empty() && map_vec[i][1] == 1) {
            if (map_vec[i][0] > maxv) {
                maxv = map_vec[i][0];
                ans_fa.clear();
                ans_fa.insert(i);
            } else if (map_vec[i][0] == maxv) {
                ans_fa.insert(i);
            }
        }
    }

    // 没有找到单感染源的
    if (ans_fa.empty()) {
        return minv;
    }

    // 找到了，找最小的感染源
    for (int i = 0; i < n; i++) {
        if (uset_node.find(i) != uset_node.end() &&
            ans_fa.find(ufs[i]) != ans_fa.end()) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    // 0
    cout << minMalwareSpread({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, {0, 1}) << endl;
    // 0
    cout << minMalwareSpread({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {0, 2}) << endl;
    // 1
    cout << minMalwareSpread({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 2}) << endl;
    // 1
    cout << minMalwareSpread(
                {{1, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}, {0, 0, 0, 1}}, {1})
         << endl;

    // 1
    cout << minMalwareSpread(
                {{1, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}},
                {1, 3})
         << endl;

    // 3
    cout << minMalwareSpread(
                {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}},
                {3, 1})
         << endl;

    // 2
    cout << minMalwareSpread({{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                              {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}},
                             {7, 8, 6, 2, 3})
         << endl;
    // 1
    cout << minMalwareSpread({{1, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 1, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 1}},
                             {1, 2, 5})
         << endl;

    return 0;
}
