#include "../template/head.h"
#include <bits/stdc++.h>

int flipLights(int n, int presses) {
    // 思路：找规律，1 和 2 单独讨论，因为不满足奇偶和 大于等于 3 个的讨论范围
    // 其他，如果操作 1 次，那么 4 种情况；操作 2 次，化简完是 7；
    // 操作 3 次及以上，都是 8
    if (presses == 0) {
        return 1;
    }

    if (n == 1) {
        return 2;
    } else if (n == 2) {
        if (presses == 1) {
            return 3;
        } else {
            return 4;
        }
    }

    if (presses == 1) {
        return 4;
    } else if (presses == 2) {
        return 7;
    }

    return 8;
}

int main(int argc, char *argv[]) {
    // 2
    cout << flipLights(1, 1) << endl;
    // 3
    cout << flipLights(2, 1) << endl;
    // 4
    cout << flipLights(3, 1) << endl;

    return 0;
}
