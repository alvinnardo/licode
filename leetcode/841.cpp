#include "../template/head.h"
#include <bits/stdc++.h>

bool canVisitAllRooms(vector<vector<int>> rooms) {
    // 思路：BFS
    // 时间 O(n)，空间 O(n)

    queue<int> qu;
    qu.push(0);
    unordered_set<int> visited;
    while (!qu.empty()) {
        auto key = qu.front();
        qu.pop();
        // 已经访问过
        if (visited.count(key)) {
            continue;
        }

        // 打开房间
        visited.insert(key);
        // 拿钥匙
        for (auto new_key : rooms[key]) {
            if (visited.count(new_key)) {
                continue;
            }
            qu.push(new_key);
        }
    }

    return visited.size() == rooms.size();
}

int main(int argc, char *argv[]) {
    // 1
    cout << canVisitAllRooms({{1}, {2}, {3}, {}}) << endl;
    // 0
    cout << canVisitAllRooms({{1, 3}, {3, 0, 1}, {2}, {0}}) << endl;

    return 0;
}
