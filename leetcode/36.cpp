#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(const vector<vector<char>> &board) {

    unordered_set<char> row_set, col_set;
    vector<vector<vector<int>>> vvv(3, vector<vector<int>>(3, vector<int>(10)));

    for (int i = 0; i < 9; i++) {
        row_set.clear();
        col_set.clear();
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') { // 行
                char t = board[i][j];
                if (row_set.find(t) == row_set.end()) {
                    row_set.insert(t);
                } else {
                    return 0;
                }

                int num = t - '0';
                int row_num = i / 3, col_num = j / 3;
                if (vvv[row_num][col_num][num] == 1) { // 方形
                    return 0;
                } else {
                    vvv[row_num][col_num][num] = 1;
                }
            }

            if (board[j][i] != '.') { // 列
                char t = board[j][i];
                if (col_set.find(t) == col_set.end()) {
                    col_set.insert(t);
                } else {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(void) {
    printBool(isValidSudoku({{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}));
    printBool(isValidSudoku({{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}));
    return 0;
}
