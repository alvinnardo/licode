#include <bits/stdc++.h>
using namespace std;

/* 拓扑排序定义:
   对于图 G 中的任意一条有向边 (u,v)，u 在排列中都出现在 v 的前面,
   则称该排列是图 G 的拓扑排序。
*/

// BFS
// 思路：每次放入入度为 0 的节点
vector<int> topo_sort(int num, vector<vector<int>> pres) {
    vector<int> du(num);
    vector<vector<int>> edges;

    for (auto &pre : pres) {
        edges[pre[0]].push_back(pre[1]);
        du[pre[1]]++;
    }

    queue<int> qu;
    for (int i = 0; i < num; i++) {
        if (du[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> res;
    while (!qu.empty()) {
        auto t = qu.front();
        res.push_back(t);
        qu.pop();

        for (auto &c : edges[t]) {
            if (--du[c] == 0) {
                qu.push(c);
            }
        }
    }

    // 有环，不能得到排列
    if (res.size() != num) {
        res.clear();
    }
    return res;
}
