#include "../template/head.h"
#include <bits/stdc++.h>

bool checkMove(vector<vector<char>> board, int rMove, int cMove, char color) {
    // 思路：模拟，八个方向上测试
    // 时间 O(n)，空间 O(1)
    vector<int> xvv{1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> yvv{0, 0, 1, -1, 1, -1, 1, -1};

    auto one_check = [&](int pos) -> bool {
        int cnt = 0, close = 0;
        int trMove = rMove, tcMove = cMove;
        while (true) {
            int new_x = trMove + xvv[pos];
            int new_y = tcMove + yvv[pos];
            if (!(new_x >= 0 && new_x < board.size() && new_y >= 0 &&
                  new_y < board.size())) {
                break;
            }

            if (board[new_x][new_y] == color) {
                close = 1;
                break;
            } else if (board[new_x][new_y] == '.') {
                break;
            } else {
                cnt = 1;
            }

            trMove = new_x;
            tcMove = new_y;
        }

        return cnt > 0 && close > 0;
    };

    for (int i = 0; i < xvv.size(); i++) {
        if (one_check(i)) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkMove({{'.', '.', '.', 'B', '.', '.', '.', '.'},
                       {'.', '.', '.', 'W', '.', '.', '.', '.'},
                       {'.', '.', '.', 'W', '.', '.', '.', '.'},
                       {'.', '.', '.', 'W', '.', '.', '.', '.'},
                       {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
                       {'.', '.', '.', 'B', '.', '.', '.', '.'},
                       {'.', '.', '.', 'B', '.', '.', '.', '.'},
                       {'.', '.', '.', 'W', '.', '.', '.', '.'}},
                      4, 3, 'B')
         << endl;
    ;
    // 0
    cout << checkMove({{'.', '.', '.', '.', '.', '.', '.', '.'},
                       {'.', 'B', '.', '.', 'W', '.', '.', '.'},
                       {'.', '.', 'W', '.', '.', '.', '.', '.'},
                       {'.', '.', '.', 'W', 'B', '.', '.', '.'},
                       {'.', '.', '.', '.', '.', '.', '.', '.'},
                       {'.', '.', '.', '.', 'B', 'W', '.', '.'},
                       {'.', '.', '.', '.', '.', '.', 'W', '.'},
                       {'.', '.', '.', '.', '.', '.', '.', 'B'}},
                      4, 4, 'W')
         << endl;

    return 0;
}
