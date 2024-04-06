#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                int by2) {
    // 重叠区域的投影线段为
    // x 轴 [max(ax1, bx1), min(ax2, bx2)]
    // y 轴 [max(ay1, by1), min(ay2, by2)]
    // 取左边的最大值，右边的最小值

    int x_left = max(ax1, bx1), x_right = min(ax2, bx2);
    int y_left = max(ay1, by1), y_right = min(ay2, by2);
    int overlap = x_left < x_right && y_left < y_right
                      ? (x_right - x_left) * (y_right - y_left)
                      : 0;
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - overlap;
}

// a(x1, y1) (x2, y2)
// b(x1, y1) (x2, y2)
int computeArea_my(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                   int bx2, int by2) {

    int a_chang = abs(ax1 - ax2);
    int a_kuan = abs(ay1 - ay2);
    int b_chang = abs(bx1 - bx2);
    int b_kuan = abs(by1 - by2);

    // 六种情况: 4 种角重叠，2 种方重叠
    int chang = 0, kuan = 0;
    if (ax1 <= bx1 && bx1 <= ax2 && ay1 <= by1 && by1 <= ay2) {
        chang = min(ax2 - bx1, bx2 - bx1);
        kuan = min(ay2 - by1, by2 - by1);
    } else if (bx1 <= ax1 && ax1 <= bx2 && by1 <= ay1 && ay1 <= by2) {
        chang = min(bx2 - ax1, ax2 - ax1);
        kuan = min(by2 - ay1, ay2 - ay1);
    } else if (bx1 <= ax2 && ax2 <= bx2 && by1 <= ay1 && ay1 <= by2) {
        chang = min(ax2 - bx1, ax2 - ax1);
        kuan = min(by2 - ay1, ay2 - ay1);
    } else if (ax1 <= bx2 && bx2 <= ax2 && ay1 <= by1 && by1 <= ay2) {
        chang = min(bx2 - ax1, bx2 - bx1);
        kuan = min(ay2 - by1, by2 - by1);
    } else if (ax1 <= bx1 && bx2 <= ax2) {
        chang = bx2 - bx1;
        if (ay2 >= by2) {
            if (ay1 <= by2 && ay1 >= by1) {
                kuan = by2 - ay1;
            } else if (ay1 < by1) {
                kuan = by2 - by1;
            }
        } else if (ay2 < by2 && ay2 >= by1) {
            if (ay1 >= by1) {
                kuan = ay2 - ay1;
            } else if (ay1 < by1) {
                kuan = ay2 - by1;
            }
        }
    } else if (bx1 <= ax1 && ax2 <= bx2) {
        chang = ax2 - ax1;
        if (by2 >= ay2) {
            if (by1 <= ay2 && by1 >= ay1) {
                kuan = ay2 - by1;
            } else if (by1 < ay1) {
                kuan = ay2 - ay1;
            }
        } else if (by2 < ay2 && by2 >= ay1) {
            if (by1 >= ay1) {
                kuan = by2 - by1;
            } else if (by1 < ay1) {
                kuan = by2 - ay1;
            }
        }
    }

    return a_chang * a_kuan + b_chang * b_kuan - chang * kuan;
}

int main(void) {
    // cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    // cout << computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
    // cout << computeArea(0, 0, 0, 0, 0, 0, 0, 0) << endl;
    // cout << computeArea(-8, -4, -1, -2, 3, 2, 9, 10) << endl;
    // cout << computeArea(-2, -2, 2, 2, 1, -3, 3, -1) << endl;
    // cout << computeArea(1, -3, 3, -1, -2, -2, 2, 2) << endl;
    // cout << computeArea(-2, -2, 2, 2, -3, 1, 3, 3) << endl;
    // cout << computeArea(-2, -2, 2, 2, -1, 4, 1, 6) << endl;
    cout << computeArea(-5, 4, 3, 5, -3, -3, 3, 3) << endl;
    return 0;
}
