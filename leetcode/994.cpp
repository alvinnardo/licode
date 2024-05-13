#include "../template/head.h"
#include <bits/stdc++.h>

int orangesRotting(vector<vector<int>> grid) {
    // 思路：层次遍历，最后检查是否全部遍历
    // 时间 O(mn), 空间 O(mn)

    queue<pair<int, int>> qu;
    int m = grid.size(), n = grid[0].size();
    int cnt = 0;             // 总数
    unordered_set<int> uset; // 保存坏的节点

    auto getNum = [&](int i, int j) { return i * 10 + j; };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            } else if (grid[i][j] == 2) {
                cnt++;
                qu.emplace(i, j);
                uset.insert(getNum(i, j));
            }
        }
    }

    if (uset.size() == cnt) {
        return 0;
    }

    int res = 0; // 时间
    while (!qu.empty()) {

        int cnt = qu.size();
        int begin_cnt = uset.size();

        while (cnt--) {
            int i = qu.front().first, j = qu.front().second;
            qu.pop();

            // 上
            if (i - 1 >= 0 && grid[i - 1][j] == 1 &&
                !uset.count(getNum(i - 1, j))) {
                grid[i - 1][j] = 2;
                qu.emplace(i - 1, j);
                uset.insert(getNum(i - 1, j));
            }
            // 下
            if (i + 1 < m && grid[i + 1][j] == 1 &&
                !uset.count(getNum(i + 1, j))) {
                grid[i + 1][j] = 2;
                qu.emplace(i + 1, j);
                uset.insert(getNum(i + 1, j));
            }
            // 左
            if (j - 1 >= 0 && grid[i][j - 1] == 1 &&
                !uset.count(getNum(i, j - 1))) {
                grid[i][j - 1] = 2;
                qu.emplace(i, j - 1);
                uset.insert(getNum(i, j - 1));
            }
            // 右
            if (j + 1 < n && grid[i][j + 1] == 1 &&
                !uset.count(getNum(i, j + 1))) {
                grid[i][j + 1] = 2;
                qu.emplace(i, j + 1);
                uset.insert(getNum(i, j + 1));
            }
        }

        // 今天有坏的产生
        if (uset.size() != begin_cnt) {
            res++;
        }
    }

    if (uset.size() != cnt) {
        return -1;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << orangesRotting({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) << endl;
    // -1
    cout << orangesRotting({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}) << endl;
    // 0
    cout << orangesRotting({{0, 2}}) << endl;

    return 0;
}
