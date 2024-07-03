#include "../template/head.h"
#include <bits/stdc++.h>

bool validTicTacToe(vector<string> board) {
    // 思路：模拟，检测不成立的情况
    // 时间 O(n2)，空间 O(1)
    auto canWin = [&](char c) {
        return board[0][0] == c && board[0][1] == c && board[0][2] == c ||
               board[1][0] == c && board[1][1] == c && board[1][2] == c ||
               board[2][0] == c && board[2][1] == c && board[2][2] == c ||
               board[0][0] == c && board[1][0] == c && board[2][0] == c ||
               board[0][1] == c && board[1][1] == c && board[2][1] == c ||
               board[0][2] == c && board[1][2] == c && board[2][2] == c ||
               board[0][0] == c && board[1][1] == c && board[2][2] == c ||
               board[0][2] == c && board[1][1] == c && board[2][0] == c;
    };

    int x_num = 0, o_num = 0;
    for (auto &b : board) {
        for (char c : b) {
            x_num += c == 'X';
            o_num += c == 'O';
        }
    }

    if (o_num > x_num || x_num - o_num > 1) {
        return 0;
    }

    if (canWin('X') && canWin('O')) {
        return 0;
    }

    if (canWin('X') && o_num == x_num || canWin('O') && o_num != x_num) {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    // 1
    cout << validTicTacToe({"XO ", "XO ", " OX"}) << endl;
    // 1
    cout << validTicTacToe({"XOX", "O O", "XOX"}) << endl;
    // 0
    cout << validTicTacToe({"XOX", " X ", "   "}) << endl;
    // 0
    cout << validTicTacToe({"O  ", "   ", "   "}) << endl;

    return 0;
}
