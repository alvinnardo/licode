#include "../template/head.h"
#include <bits/stdc++.h>

int numOfMinutes(int n, int headID, vector<int> manager,
                 vector<int> informTime) {
    // 思路：BFS
    // 时间 O(n)，空间 O(n)

    // 只是一棵树
    vector<vector<int>> edges(n);
    for (int i = 0; i < manager.size(); i++) {
        if (manager[i] != -1) {
            edges[manager[i]].push_back(i);
        }
    }

    queue<int> qu;
    qu.push(headID);

    vector<int> vec(n, -1);
    vec[headID] = 0;
    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();

        for (int n : edges[t]) {
            vec[n] = vec[t] + informTime[t];
            qu.push(n);
        }
    }

    // 取最大时间
    return *max_element(vec.begin(), vec.end());
}

int main(int argc, char *argv[]) {
    // 0
    cout << numOfMinutes(1, 0, {-1}, {0}) << endl;
    // 1
    cout << numOfMinutes(6, 2, {2, 2, -1, 2, 2, 2}, {0, 0, 1, 0, 0, 0}) << endl;

    return 0;
}
