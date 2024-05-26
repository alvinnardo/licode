#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<char>> updateBoard(vector<vector<char>> board,
                                 vector<int> click) {
    // 思路：模拟
    // 'M' 未挖出的地雷，'E' 未挖出的空方块
    // 'B' 没有相邻地雷的已挖出空方块
    // '1' - '8' 相邻地雷已挖出的空方块
    // 'X' 已挖出的地雷
    // 时间 O(mn)，空间 O(mn)
    // 注：这里的相邻是八个方向的相邻
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }

    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> qu;
    qu.emplace(click[0], click[1]);

    while (!qu.empty()) {
        auto t = qu.front();
        qu.pop();
        // 之前已经处理过了
        if (board[t.first][t.second] != 'E') {
            continue;
        }

        // 判断周围是否有雷
        int cnt = 0;
        if (t.first - 1 >= 0) {
            cnt += t.second - 1 >= 0 && board[t.first - 1][t.second - 1] == 'M';
            cnt += board[t.first - 1][t.second] == 'M';
            cnt += t.second + 1 < n && board[t.first - 1][t.second + 1] == 'M';
        }
        if (t.first + 1 < m) {
            cnt += t.second - 1 >= 0 && board[t.first + 1][t.second - 1] == 'M';
            cnt += board[t.first + 1][t.second] == 'M';
            cnt += t.second + 1 < n && board[t.first + 1][t.second + 1] == 'M';
        }
        cnt += t.second - 1 >= 0 && board[t.first][t.second - 1] == 'M';
        cnt += t.second + 1 < n && board[t.first][t.second + 1] == 'M';

        // 周围有雷
        if (cnt) {
            board[t.first][t.second] = (char)('0' + cnt);
        } else {
            board[t.first][t.second] = 'B';

            // 上
            if (t.first - 1 >= 0) {
                if (t.second - 1 >= 0 &&
                    board[t.first - 1][t.second - 1] == 'E') {
                    qu.emplace(t.first - 1, t.second - 1);
                }
                if (board[t.first - 1][t.second] == 'E') {
                    qu.emplace(t.first - 1, t.second);
                }
                if (t.second + 1 < n &&
                    board[t.first - 1][t.second + 1] == 'E') {
                    qu.emplace(t.first - 1, t.second + 1);
                }
            }
            // 下
            if (t.first + 1 < m) {
                if (t.second - 1 >= 0 &&
                    board[t.first + 1][t.second - 1] == 'E') {
                    qu.emplace(t.first + 1, t.second - 1);
                }
                if (board[t.first + 1][t.second] == 'E') {
                    qu.emplace(t.first + 1, t.second);
                }
                if (t.second + 1 < n &&
                    board[t.first + 1][t.second + 1] == 'E') {
                    qu.emplace(t.first + 1, t.second + 1);
                }
            }
            // 左
            if (t.second - 1 >= 0 && board[t.first][t.second - 1] == 'E') {
                qu.emplace(t.first, t.second - 1);
            }
            // 右
            if (t.second + 1 < n && board[t.first][t.second + 1] == 'E') {
                qu.emplace(t.first, t.second + 1);
            }
        }
    }

    return board;
}

int main(int argc, char *argv[]) {
    printVectorVector(updateBoard({{'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'M', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E'}},
                                  {3, 0}));
    printVectorVector(updateBoard({{'B', '1', 'E', '1', 'B'},
                                   {'B', '1', 'M', '1', 'B'},
                                   {'B', '1', '1', '1', 'B'},
                                   {'B', 'B', 'B', 'B', 'B'}},
                                  {1, 2}));
    printVectorVector(updateBoard({{'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'M', 'E', 'M'},
                                   {'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'M'}},
                                  {3, 0}));

    return 0;
}
