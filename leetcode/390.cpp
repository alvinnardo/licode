#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

int lastRemaining(int n) {
    // 思路：想了挺久的，最后给出的算法是利用公差，起始和终止位置
    // 从前或从后判断结束元素是否被删除，直到最后剩一个数
    // 时间 O(logn)

    int d = 1, left = 1, right = n;
    bool flag = true;

    while (left + d < right) {
        if (flag) {
            if ((right - left) % (d << 1) == 0) {
                right -= d;
            }
            left += d;
        } else {
            if ((right - left) % (d << 1) == 0) {
                left += d;
            }
            right -= d;
        }
        d <<= 1;
        flag = flag ? false : true;
    }

    if (left == right) {
        return left;
    }

    return flag ? right : left;
}

int main(void) {
    // 1
    cout << lastRemaining(1) << endl;
    // 6
    cout << lastRemaining(9) << endl;
    // 86
    cout << lastRemaining(144) << endl;
    // 510
    cout << lastRemaining(1000) << endl;
    // 25130880
    cout << lastRemaining(37642863) << endl;
    // 534765398
    cout << lastRemaining(1000000000) << endl;

    return 0;
}
