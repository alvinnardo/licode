#include "../template/head.h"
#include <bits/stdc++.h>

int snakesAndLadders(vector<vector<int>> board) {
    // 思路：BFS
    // 时间 O(n2k)，空间 O(n2)
    int n = board.size();

    // 主要是找对应关系
    auto getReal = [](int num, int n) -> pair<int, int> {
        int row = (num - 1) / n; // 从下到上第几行，从 0 计数
        return {(n - 1) - row,
                (row & 1) ? (n - 1) - (num - 1) % n : (num - 1) % n};
    };

    auto getNum = [](int a, int b, int n) -> int {
        int row = (n - 1) - a;
        return (row & 1) ? row * n + (n - 1) - b + 1 : row * n + b + 1;
    };

    // for test
    // for (int i = 1; i < 100; i++) {
    //     auto t = getReal(i, n);
    //     cout << i << ": " << getNum(t.first, t.second, n) << " " << t.first
    //          << " " << t.second << endl;
    // }

    const int target = n * n;
    queue<int> qu;
    qu.push(1);

    vector<int> visited(target);
    int dis = 0;
    while (!qu.empty()) { // 不一定能到，所以不能是 true
        int cnt = qu.size();
        dis++;
        while (cnt--) {
            int t = qu.front();
            qu.pop();
            if (visited[t]) {
                continue;
            }
            visited[t] = 1;

            for (int i = 1; i <= 6; i++) {
                int num = t + i;
                if (num < target) {
                    auto real = getReal(num, n);
                    if (board[real.first][real.second] == -1) {
                        if (!visited[num]) {
                            qu.push(num);
                        }
                    } else {
                        if (board[real.first][real.second] == target) {
                            return dis;
                        }
                        // 直接传送一次
                        if (!visited[board[real.first][real.second]]) {
                            qu.push(board[real.first][real.second]);
                        }
                    }
                } else if (num == target) {
                    return dis;
                } else {
                    break;
                }
            }
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 4
    cout << snakesAndLadders({{-1, -1, -1, -1, -1, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, 35, -1, -1, 13, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, 15, -1, -1, -1, -1}})
         << endl;
    // 1
    cout << snakesAndLadders({{-1, -1}, {-1, 3}}) << endl;
    // -1
    cout << snakesAndLadders({{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}}) << endl;

    return 0;
}
