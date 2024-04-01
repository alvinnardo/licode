#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board) {
    // 从边界 BFS 遍历，遍历到的一定是没有包围的
    // 然后把没有遍历到的修改为 "O"

    unordered_set<int> visited; // 判断是否访问过
    queue<pair<int, int>> qu;   // BFS

    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) { // 左右边界
        if (board[i][0] == 'O') {
            qu.emplace(i, 0);
        }
        if (board[i][col - 1] == 'O') {
            qu.emplace(i, col - 1);
        }
    }

    for (int i = 0; i < col; i++) { // 上下边界
        if (board[0][i] == 'O') {
            qu.emplace(0, i);
        }
        if (board[row - 1][i] == 'O') {
            qu.emplace(row - 1, i);
        }
    }

    auto getAf = [](int a, int b) { return a * 1000 + b; };

    while (!qu.empty()) {
        auto t = qu.front();
        qu.pop();
        visited.insert(getAf(t.first, t.second));

        // 上，是 O，且没有被访问过
        if (t.first - 1 >= 0 && board[t.first - 1][t.second] == 'O' &&
            visited.find(getAf(t.first - 1, t.second)) == visited.end()) {
            qu.emplace(t.first - 1, t.second);
        }

        // 下
        if (t.first + 1 <= row - 1 && board[t.first + 1][t.second] == 'O' &&
            visited.find(getAf(t.first + 1, t.second)) == visited.end()) {
            qu.emplace(t.first + 1, t.second);
        }

        // 左
        if (t.second - 1 >= 0 && board[t.first][t.second - 1] == 'O' &&
            visited.find(getAf(t.first, t.second - 1)) == visited.end()) {
            qu.emplace(t.first, t.second - 1);
        }

        // 右
        if (t.second + 1 <= col - 1 && board[t.first][t.second + 1] == 'O' &&
            visited.find(getAf(t.first, t.second + 1)) == visited.end()) {
            qu.emplace(t.first, t.second + 1);
        }
    }

    // 替换
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O' &&
                visited.find(getAf(i, j)) == visited.end()) {
                board[i][j] = 'X';
            }
        }
    }
}

int main(void) {
    vector<vector<char>> vec{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};
    solve(vec);
    printVectorVector(vec);
    vec = {{'X'}};
    solve(vec);
    printVectorVector(vec);
    vec = {{'O', 'O', 'O'}};
    solve(vec);
    printVectorVector(vec);

    return 0;
}
