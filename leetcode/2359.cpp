#include "../template/head.h"
#include <bits/stdc++.h>

int closestMeetingNode(vector<int> edges, int node1, int node2) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    int sz = edges.size();
    vector<int> dist1(sz, -1), dist2(sz, -1);

    // 较大值最小化就是只经历一次
    // node1 走一遍，记录到过的点
    // node2 走一遍，记录同时到过的点的最小值
    auto gen = [](const auto &edges, int node, auto &dist) {
        int path = 0;
        dist[node] = 0;
        while (true) {
            // 到不了或者到过了
            if (edges[node] < 0 || dist[edges[node]] >= 0) {
                break;
            }

            dist[edges[node]] = ++path;
            node = edges[node];
        }
    };

    gen(edges, node1, dist1);
    gen(edges, node2, dist2);
    int res = -1, minv = INT_MAX;
    for (int i = 0; i < sz; i++) {
        if (dist1[i] >= 0 && dist2[i] >= 0) {
            int t = max(dist1[i], dist2[i]);
            if (t < minv) {
                minv = t;
                res = i;
            } else if (t == minv) {
                res = min(res, i);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << closestMeetingNode({2, 2, 3, -1}, 0, 1) << endl;
    // 2
    cout << closestMeetingNode({1, 2, -1}, 0, 2) << endl;

    return 0;
}
