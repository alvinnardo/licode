#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int findChampion(vector<vector<int>> grid) {
    // 能赢其他 n-1 支队伍
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    cout << findChampion({{0, 1}, {0, 0}}) << endl;
    cout << findChampion({{0, 0, 1}, {1, 0, 1}, {0, 0, 0}}) << endl;

    return 0;
}
