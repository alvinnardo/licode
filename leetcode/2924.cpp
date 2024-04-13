#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int findChampion(int n, vector<vector<int>> edges) {
    // 题解：因为没有环，可直接遍历，得到入度为 0 的点是冠军
    // 如果有多个入度为 0 的点，那就没有唯一冠军
    vector<int> rec(n);
    for (auto &edge : edges) {
        rec[edge[1]]++;
    }

    int champion = -1;
    for (int i = 0; i < n; i++) {
        if (rec[i] == 0) {
            if (champion == -1) {
                champion = i;
            } else {
                return -1;
            }
        }
    }

    return champion;
}

int findChampion_my(int n, vector<vector<int>> edges) {
    // 对每个点做 dfs
    vector<vector<int>> nedges(n);

    for (auto &edge : edges) {
        nedges[edge[0]].push_back(edge[1]);
    }

    vector<vector<int>> vset(n, vector<int>(n));
    unordered_set<int> uset;
    function<void(int)> dfs = [&](int pos) {
        uset.insert(pos);
        if (nedges[pos].empty()) {
            return;
        }

        for (auto e : nedges[pos]) {
            if (uset.find(e) == uset.end()) {
                dfs(e);
            }

            // 如果已经能打败了，就不管了
            if (vset[pos][e] == 1) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (vset[e][i] == 1) {
                    vset[pos][i] = 1;
                }
            }
            vset[pos][e] = 1;
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(i);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (vset[i][j] == 1) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    cout << findChampion(3, {{0, 1}, {1, 2}}) << endl;
    cout << findChampion(4, {{0, 2}, {1, 3}, {1, 2}}) << endl;
    cout << findChampion(4, {{2, 0}, {1, 3}, {1, 2}}) << endl;
    cout << findChampion(3, {{0, 1}, {1, 2}, {0, 2}}) << endl;
    cout << findChampion(3, {{0, 2}, {1, 2}, {1, 0}}) << endl;

    return 0;
}
