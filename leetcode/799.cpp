#include "../template/head.h"
#include <bits/stdc++.h>
double champagneTower(int poured, int query_row, int query_glass) {
    // 题解：模拟，脑筋急转弯
    // 把所有水一起倒进去，然后模拟流动，而不是一杯一杯模拟
    // 时间 O(k2)，空间 O(k)，k 是每一层的平均数

    vector<double> up, down(100);
    down[0] = poured;

    // 处理每一层
    for (int l = 1; l <= 100; l++) {
        up = down;
        for (int i = 0; i < down.size(); i++) {
            down[i] = 0;
        }

        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (up[i] > 1) {
                double ret = (up[i] - 1) / 2;
                up[i] = 1;
                down[i] += ret;
                down[i + 1] += ret;
            } else {
                // 统计没有溢出的个数
                cnt++;
            }
        }

        // 处理完要查询的那行了
        if (l == query_row + 1) {
            break;
        }

        // 没有溢出了
        if (cnt == l) {
            return 0;
        }
    }

    return up[query_glass];
}

double champagneTower_wrong(int poured, int query_row, int query_glass) {
    // 思路：模拟
    // 时间 O(n)，空间 O(k2)
    // 肯定超时了
    vector<vector<double>> cup(100, vector<double>(100, 0));
    queue<pair<int, int>> qu;
    qu.emplace(0, 0);

    while (!qu.empty() && poured > 0) {
        int cnt = qu.size();
        double put = 1.0 / cnt;
        poured--;

        while (cnt--) {
            auto p = qu.front();
            qu.pop();
            if (p.first == 100) {
                qu.emplace(p.first, p.second);
                continue;
            }

            if (cup[p.first][p.second] == 1) {
                if (p.first + 1 < 100) {
                    cup[p.first + 1][p.second] += put / 2;
                    cup[p.first + 1][p.second + 1] += put / 2;
                }
                qu.emplace(p.first + 1, p.second);
                qu.emplace(p.first + 1, p.second + 1);
                continue;
            }

            double can = 1 - cup[p.first][p.second];
            if (put >= can) {
                cup[p.first][p.second] = 1;
                double duo = put - can;
                if (duo > 0 && p.first + 1 < 100) {
                    cup[p.first + 1][p.second] += duo / 2;
                    cup[p.first + 1][p.second + 1] += duo / 2;
                }
                qu.emplace(p.first + 1, p.second);
                qu.emplace(p.first + 1, p.second + 1);
            } else {
                cup[p.first][p.second] += put;
                qu.emplace(p.first, p.second);
            }
        }
    }

    return cup[query_row][query_glass];
}

int main(int argc, char *argv[]) {

    // 0
    cout << champagneTower(1, 1, 1) << endl;
    // 0.5
    cout << champagneTower(2, 1, 1) << endl;
    // 1
    cout << champagneTower(100000009, 33, 17) << endl;
    // for (int i = 0; i < 10; i++) {
    // cout <<champagneTower(6, 1, 1);
    // }

    return 0;
}
