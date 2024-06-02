#include "../template/head.h"
#include <bits/stdc++.h>
bool validSquare(vector<int> p1, vector<int> p2, vector<int> p3,
                 vector<int> p4) {
    // 思路：判断是否是正方形，但不一定是横平竖直的
    // 判断是否有重合点，对于每个点，找到两个点积为 0, 并看边长是否相等
    // 时间 O(n3)，空间 O(n)

    // 正方形判定定理，
    // 如果两条斜边中点相同（平行四边形）
    // 如果斜边长度相同（矩形）
    // 如果斜边垂直（正方形）

    // 看题解有几个算法：任意三个点都是等腰直角三角形，和我的思路一样
    // 有人没有判断直角，比如一个等腰三角形和一个圆的圆点，满足任意等腰三角形，但不是正方形
    // 所以必须要判断直角
    vector<vector<int>> vec{p1, p2, p3, p4};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                continue;
            }
            // 重合
            if (vec[i][0] == vec[j][0] && vec[i][1] == vec[j][1]) {
                return 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j)
                    continue;

                pair<int, int> a = {vec[j][0] - vec[i][0],
                                    vec[j][1] - vec[i][1]};
                pair<int, int> b = {vec[k][0] - vec[i][0],
                                    vec[k][1] - vec[i][1]};
                if (a.first * b.first + a.second * b.second == 0 &&
                    a.first * a.first + a.second * a.second ==
                        b.first * b.first + b.second * b.second) {
                    cnt++;
                }
            }
        }

        // 有一个重复的
        if (cnt != 2) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    // 1
    cout << validSquare({0, 0}, {1, 1}, {1, 0}, {0, 1}) << endl;
    // 0
    cout << validSquare({0, 0}, {1, 1}, {1, 0}, {0, 12}) << endl;
    // 1
    cout << validSquare({1, 0}, {-1, 0}, {0, 1}, {0, -1}) << endl;

    return 0;
}
