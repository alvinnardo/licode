#include "../template/head.h"
#include <bits/stdc++.h>

int robotSim(vector<int> commands, vector<vector<int>> obstacles) {
    // 思路：模拟 + 二分 + 哈希表
    // 时间 O(nlogm + mlogm)，空间 O(m)

    // 主要的算法是二分找障碍物
    unordered_map<int, set<int>> row_map, col_map;
    bool isOri = false;
    for (const auto &ob : obstacles) {
        // 题目中给出 (0, 0) 可能有障碍物
        // 如果在 (0, 0) 出发就无视该障碍物，
        // 不能直接删除，对后面再经过 (0, 0) 有影响
        if (ob[0] == 0 && ob[1] == 0) {
            isOri = true;
            continue;
        }
        row_map[ob[1]].insert(ob[0]); // 行上 y 不变
        col_map[ob[0]].insert(ob[1]); // 列上 x 不变
    }

    int res = 0;                  // 记录中间最远点的位置
    int x = 0, y = 0, direct = 0; // 0 上，1 右，2 下，3 左
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == -1) { // 向右转
            direct = (direct + 1) % 4;
            continue;
        } else if (commands[i] == -2) { // 向左转
            direct = (direct + 3) % 4;  // + 4 - 1
            continue;
        }

        if (direct == 0) { // 往上走，x 不变, y 增加
            // 当前列没有障碍物，或者最后一个障碍物在当前位置的前面
            if (!col_map.count(x) || *col_map[x].rbegin() < y) {
                y += commands[i];
            } else { // 找大于的
                int y_ob = *col_map[x].upper_bound(y);
                y = min(y + commands[i], y_ob - 1);
            }
        } else if (direct == 1) { // 往右走，y 不变，x 增加
            if (!row_map.count(y) || *row_map[y].rbegin() < x) {
                x += commands[i];
            } else {
                int x_ob = *row_map[y].upper_bound(x);
                x = min(x + commands[i], x_ob - 1);
            }
        } else if (direct == 2) { // 往下走，x 不变，y 减少
            if (!col_map.count(x) || *col_map[x].begin() > y) {
                y -= commands[i];
            } else { // 找小于的
                int y_ob = *std::prev(col_map[x].lower_bound(y));
                y = max(y - commands[i], y_ob + 1);
            }
        } else { // 往左走，y 不变, x 减少
            if (!row_map.count(y) || *row_map[y].begin() > x) {
                x -= commands[i];
            } else {
                int x_ob = *std::prev(row_map[y].lower_bound(x));
                x = max(x - commands[i], x_ob + 1);
            }
        }

        // 走出了原点，则可以把原点的障碍物加回来
        if (isOri && (x != 0 || y != 0)) {
            row_map[0].insert(0);
            col_map[0].insert(0);
            isOri = false;
        }

        res = max(res, x * x + y * y);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 25
    cout << robotSim({4, -1, 3}, {}) << endl;
    // 65
    cout << robotSim({4, -1, 4, -2, 4}, {{2, 4}}) << endl;
    // 36
    cout << robotSim({6, -1, -1, 6}, {}) << endl;
    // 36
    cout << robotSim({6, -1, -1, 6}, {{0, 0}}) << endl;

    return 0;
}
