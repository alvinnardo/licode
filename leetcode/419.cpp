#include "../template/head.h"
#include <bits/stdc++.h>

int countBattleships(vector<vector<char>> board) {
    // 该题的意思是给了甲板，甲板上有战舰，找战舰的个数
    // 思路：直接进阶，一次遍历，O(1) 的空间复杂度
    // 左上右是空，或者左上下是空，即可判断是否是战舰的开始位置
    // 只要左和上成立，一定成立
    int sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') &&
                (j == 0 || board[i][j - 1] == '.')) {
                sum++;
            }
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {

    // 2
    cout << countBattleships({{'X', '.', '.', 'X'},
                              {'.', '.', '.', 'X'},
                              {'.', '.', '.', 'X'}})
         << endl;

    // 0
    cout << countBattleships({{'.'}}) << endl;
    // 1
    cout << countBattleships({{'X'}}) << endl;
    // 1
    cout << countBattleships({{'X', 'X', 'X'}}) << endl;

    return 0;
}
