#include "../template/head.h"
#include <bits/stdc++.h>

bool possibleBipartition(int n, vector<vector<int>> dislikes) {
    // 思路：二分图 + bfs
    // 时间 O(e)，空间 O(n)

    // 把不喜欢的分成两个组，其他的可以随便分

    vector<vector<int>> dis_edges(n + 1);
    vector<int> group(n + 1, -1);
    // a 和 b 不能在一个组里，需要互相抵制
    // bfs 时如果 a -> c -> b, d -> b，只一边抵制，d 分到 0, b 结果不对
    for (auto &edge : dislikes) {
        dis_edges[edge[0]].push_back(edge[1]);
        dis_edges[edge[1]].push_back(edge[0]);
    }

    vector<int> visited(n + 1);
    queue<int> qu;

    auto bfs = [&]() {
        while (!qu.empty()) {
            int t = qu.front();
            qu.pop();

            if (visited[t]) {
                continue;
            }

            visited[t] = 1;

            for (int p : dis_edges[t]) {
                if (group[p] == group[t]) {
                    return false;
                } else {
                    group[p] = (group[t] + 1) % 2;
                    qu.push(p);
                }
            }
        }

        return true;
    };

    for (int i = 1; i < n + 1; i++) {

        if (!dis_edges[i].empty() && visited[i] == 0) {
            qu.push(i);
            group[i] = 0;
            if (!bfs()) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // true
    cout << possibleBipartition(4, {{1, 2}, {1, 3}, {2, 4}}) << endl;
    // false
    cout << possibleBipartition(3, {{1, 2}, {1, 3}, {2, 3}}) << endl;
    // false
    cout << possibleBipartition(5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}})
         << endl;

    return 0;
}
