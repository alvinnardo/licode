#include "../template/head.h"
#include <bits/stdc++.h>

// 催的紧，每次着急改完就提交了，错误次数比较多
// 我先把别的事解决完了，回来踏实做出来了
int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    // 思路：分类讨论
    // 时间 O(1)，空间 O(1)
    // 对于车，两步肯定能到达棋盘上任意位置
    // 对于象，只能到达斜线的位置
    // 注意题目中给出不能跳过棋子
    int num1 = INT_MAX, num2 = INT_MAX;
    if (a == e) { // 同一行
        if (c == e && d > min(b, f) && d < max(b, f)) {
            num1 = 2;
        } else {
            num1 = 1;
        }
    } else if (b == f) { // 同一列
        if (d == f && c > min(a, e) && c < max(a, e)) {
            num1 = 2;
        } else {
            num1 = 1;
        }
    } else {
        num1 = 2;
    }

    if (c - e == d - f) { // 正对角线
        if (a - e == b - f && a > min(c, e) && a < max(c, e)) {
            num2 = 2;
        } else {
            num2 = 1;
        }
    } else if (c - e == f - d) { // 斜对角线
        if (c - a == b - d && a > min(c, e) && a < max(c, e)) {
            num2 = 2;
        } else {
            num2 = 1;
        }
    } // 其它情况不用考虑，因为车最多两次就能吃到，只要把象走一步的分析正确即可

    return min(num1, num2);
}

// 看到一个评论，如果车或象挡着了，则先移开挡着的，再移动另一个就行了
// 所以最多就是两步
int main(int argc, char *argv[]) {

    // 2
    cout << minMovesToCaptureTheQueen(1, 1, 8, 8, 2, 3) << endl;
    // 1
    cout << minMovesToCaptureTheQueen(5, 3, 3, 4, 5, 2) << endl;
    // 2
    cout << minMovesToCaptureTheQueen(4, 3, 3, 4, 5, 2) << endl;
    // 1
    cout << minMovesToCaptureTheQueen(8, 4, 8, 8, 7, 7) << endl;
    // 1
    cout << minMovesToCaptureTheQueen(4, 3, 3, 4, 2, 5) << endl;
    // 1
    cout << minMovesToCaptureTheQueen(5, 8, 8, 8, 1, 8) << endl;

    return 0;
}
