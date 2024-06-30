#include "../template/head.h"
#include <bits/stdc++.h>

bool escapeGhosts(vector<vector<int>> ghosts, vector<int> target) {
    // 思路：脑筋急转弯，使用曼哈顿距离 dis = |xa - xa| + |ya - yb|
    // 时间 O(n)，空间 O(1)
    // 所有人都往终点走，如果幽灵先到，则可以等在原地；如果人先到就能胜利

    int minv = INT_MAX;
    for (auto &it : ghosts) {
        minv = min(minv, abs(it[0] - target[0]) + abs(it[1] - target[1]));
    }

    int dis = abs(target[0]) + abs(target[1]);

    return dis < minv;
}

int main(int argc, char *argv[]) {
    // 1
    cout << escapeGhosts({{1, 0}, {0, 3}}, {0, 1}) << endl;
    // 0
    cout << escapeGhosts({{1, 0}}, {2, 0}) << endl;
    // 0
    cout << escapeGhosts({{2, 0}}, {1, 0}) << endl;

    return 0;
}
