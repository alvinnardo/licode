#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 1. 活的 少于 2 个死亡
// 2. 活的 2 个或 3 个活
// 3. 活的 3 个以上死亡
// 4. 死的 3 个复活
void gameOfLife(vector<vector<int>> board) {
    // 保留一行
    int m = board.size(), n = board[0].size();
    vector<int> line1, line2;
    for (int i = 0; i < m; i++) {
        line1 = line2;
        line2.clear();
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            line2.push_back(board[i][j]);
            if (i - 1 >= 0) { // 上
                if (j - 1 >= 0 && line1[j - 1] == 1) {
                    cnt++;
                }
                if (line1[j] == 1) {
                    cnt++;
                }
                if (j + 1 < n && line1[j + 1] == 1) {
                    cnt++;
                }
            }
            if (i + 1 < m) { // 下
                if (j - 1 >= 0 && board[i + 1][j - 1] == 1) {
                    cnt++;
                }
                if (board[i + 1][j] == 1) {
                    cnt++;
                }
                if (j + 1 < n && board[i + 1][j + 1] == 1) {
                    cnt++;
                }
            }
            // 左
            if (j - 1 >= 0 && line2[j - 1] == 1) {
                cnt++;
            }
            // 右
            if (j + 1 < n && board[i][j + 1] == 1) {
                cnt++;
            }

            // 更改状态
            if (board[i][j] == 0) {
                if (cnt == 3) {
                    board[i][j] = 1;
                }
            } else {
                if (cnt < 2 || cnt > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }

    printVectorVector(board);
}

int main(void) {
    gameOfLife({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}});
    gameOfLife({{0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0},
                {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                {1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0},
                {0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0}});
    gameOfLife({{1, 1}, {1, 0}});
    gameOfLife({{1}});
    gameOfLife({{0, 1}});

    return 0;
}
