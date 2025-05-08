#include "../template/head.h"
#include <bits/stdc++.h>

int minTimeToReach(vector<vector<int>> moveTime) {
    // 思路：Dijkstra
    // 时间 O(mnlogmn)，空间 O(mn)

    // 一开始想用 DP, 最后想着可能会往上走
    // 没想出来，看了题解的 title，原来是用 Dijkstra
    // 恍然大悟
    int m = moveTime.size(), n = moveTime[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;

    pq.emplace(0, 0);
    vector<pair<int, int>> direct{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int new_dist = t.first;
        int pa = t.second / 100, pb = t.second % 100;

        if (new_dist < dist[pa][pb]) {
            dist[pa][pb] = new_dist;

            // 上、下、左、右
            for (int i = 0; i < direct.size(); i++) {
                int new_pa = pa + direct[i].first;
                int new_pb = pb + direct[i].second;
                int new_pos = new_pa * 100 + new_pb;
                // 判断到下一个位置的长度
                // 如果不能开始则等待
                if (new_pa >= 0 && new_pa < m && new_pb >= 0 && new_pb < n) {
                    // 如果点访问过，则可以跳过
                    // 因为算法保证访问过的都能保证是最先访问过的
                    if (dist[new_pa][new_pb] != INT_MAX) {
                        continue;
                    }

                    if (dist[pa][pb] >= moveTime[new_pa][new_pb]) {
                        pq.emplace(dist[pa][pb] + 1, new_pos);
                    } else {
                        pq.emplace(moveTime[new_pa][new_pb] + 1, new_pos);
                    }
                }
            }
        }
    }

    return dist[m - 1][n - 1];
}

int main(int argc, char *argv[]) {
    // 6
    cout << minTimeToReach({{0, 4}, {4, 4}}) << endl;
    // 3
    cout << minTimeToReach({{0, 0, 0}, {0, 0, 0}}) << endl;
    // 3
    cout << minTimeToReach({{0, 1}, {1, 2}}) << endl;

    return 0;
}
