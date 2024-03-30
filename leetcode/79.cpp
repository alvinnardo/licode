#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>> board, string word) {

    int row = board.size(), col = board[0].size();
    vector<vector<int>> record(row, vector<int>(col));
    function<bool(int, int, vector<vector<int>> &, int)> dfs =
        [&](int i, int j, vector<vector<int>> &record, int pos) {
            if (pos == word.length())
                return true;

            if (i < 0 || i >= row || j < 0 || j >= col || record[i][j] == 1) {
                return false;
            }

            if (board[i][j] == word[pos]) {
                record[i][j] = 1;

                bool t = dfs(i - 1, j, record, pos + 1) ||
                         dfs(i + 1, j, record, pos + 1) ||
                         dfs(i, j - 1, record, pos + 1) ||
                         dfs(i, j + 1, record, pos + 1);
                record[i][j] = 0;
                return t;
            }

            return false;
        };

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(i, j, record, 0)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    printBool(exist(
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
        "ABCCED"));
    printBool(exist(
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
        "SEE"));
    printBool(exist(
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
        "ABCB"));
    printBool(exist(
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
        "B"));

    return 0;
}
