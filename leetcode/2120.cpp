#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> executeInstructions(int n, vector<int> startPos, string s) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)
    int m = s.length();
    vector<int> res;

    for (int i = 0; i < m; i++) {
        int row = startPos[0], col = startPos[1];
        int cnt = 0;
        for (int j = i; j < m; j++) {
            if (s[j] == 'L') {
                col--;
            } else if (s[j] == 'R') {
                col++;
            } else if (s[j] == 'U') {
                row--;
            } else {
                row++;
            }

            if (row >= 0 && row < n && col >= 0 && col < n) {
                cnt++;
            } else {
                break;
            }
        }

        res.push_back(cnt);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,5,4,3,1,0}
    printVector(executeInstructions(3, {0, 1}, "RRDDLU"));
    // {4,1,0,0}
    printVector(executeInstructions(2, {1, 1}, "LURD"));

    return 0;
}
