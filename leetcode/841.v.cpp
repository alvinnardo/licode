#include "../template/head.h"
#include <bits/stdc++.h>

bool canVisitAllRooms(vector<vector<int>> rooms) {
    // 思路：bfs
    // 时间 O(n)，空间 O(n)
    int n = rooms.size(), cnt = 0;
    vector<int> visited(n); // 用数组优化时间

    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();
        if (visited[t]) { // 如果被打开过则跳过
            continue;
        }

        // 打开房间，把有用的钥匙拿走
        for (int k : rooms[t]) {
            if (!visited[k]) {
                qu.push(k);
            }
        }

        // 标记这间房间已经被打开过
        visited[t] = 1;
        cnt++;
    }

    // 是否所有房间都被打开了
    return cnt == n;
}

int main(int argc, char *argv[]) {
    // true
    cout << canVisitAllRooms({{1}, {2}, {3}, {}}) << endl;
    // false
    cout << canVisitAllRooms({{1, 3}, {3, 0, 1}, {2}, {0}}) << endl;

    return 0;
}
