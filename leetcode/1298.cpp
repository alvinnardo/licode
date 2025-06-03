#include "../template/head.h"
#include <bits/stdc++.h>

int maxCandies(vector<int> status, vector<int> candies,
               vector<vector<int>> keys, vector<vector<int>> containedBoxes,
               vector<int> initialBoxes) {
    // 思路：BFS
    // 时间 O(n + k)，空间 O(n)，n 是盒子个数，k 是总钥匙个数
    int res = 0;

    // 已经拿走糖果的
    // 有盒子但是没有钥匙的
    unordered_set<int> has_taken, no_key_boxes, no_box_keys;
    queue<int> qu;
    for (int i = 0; i < initialBoxes.size(); i++) {
        if (status[initialBoxes[i]]) {
            qu.push(initialBoxes[i]);
        } else {
            no_key_boxes.insert(initialBoxes[i]);
        }
    }

    // 打开有钥匙的盒子
    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();

        // 已经拿走了
        if (has_taken.count(t)) {
            continue;
        }

        has_taken.insert(t);
        res += candies[t];

        // 把盒子取走
        for (int h : containedBoxes[t]) {
            if (status[h]) { // 盒子是打开着的
                qu.push(h);
            } else {
                no_key_boxes.insert(h);
            }
        }

        for (auto it = no_box_keys.begin(); it != no_box_keys.end();) {
            // 已经开过了，钥匙没用了
            if (has_taken.count(*it)) {
                it = no_box_keys.erase(it);
            } else {
                // 拿钥匙开盒子
                if (no_key_boxes.count(*it)) {
                    // 钥匙能打开
                    qu.push(*it); // 先 push，再 erase 迭代器
                    no_key_boxes.erase(*it);
                    it = no_box_keys.erase(it); // 删除迭代器要返回下一个有效的
                } else {
                    // 打不开尝试下一把
                    it++;
                }
            }
        }

        // 把钥匙取走，检查是否能开盒子
        for (int k : keys[t]) {
            if (has_taken.count(k)) {
                continue;
            }

            if (no_key_boxes.count(k)) {
                // 能打开盒子，就把无钥匙的盒子删掉
                no_key_boxes.erase(k);
                qu.push(k);
            } else {
                // 打不开盒子，就把钥匙加入闲置中
                no_box_keys.insert(k);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 16
    cout << maxCandies({1, 0, 1, 0}, {7, 5, 4, 100}, {{}, {}, {1}, {}},
                       {{1, 2}, {3}, {}, {}}, {0})
         << endl;
    // 6
    cout << maxCandies({1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1},
                       {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}},
                       {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}}, {0})
         << endl;
    // 1
    cout << maxCandies({1, 1, 1}, {100, 1, 100}, {{}, {0, 2}, {}}, {{}, {}, {}},
                       {1})
         << endl;
    // 0
    cout << maxCandies({1}, {100}, {{}}, {{}}, {}) << endl;
    // 7
    cout << maxCandies({1, 1, 1}, {2, 3, 2}, {{}, {}, {}}, {{}, {}, {}},
                       {2, 1, 0})
         << endl;

    // 10
    cout << maxCandies({1, 0, 0, 0}, {1, 2, 3, 4}, {{1, 2}, {3}, {}, {}},
                       {{2}, {3}, {1}, {}}, {0})
         << endl;

    return 0;
}
