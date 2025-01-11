#include "../template/head.h"
#include <bits/stdc++.h>

int generateKey(int num1, int num2, int num3) {
    // 思路：模拟
    // 时间 O(1)，空间 O(1)
    // t 每次取最高位
    int t = 1000, res = 0;
    while (t) {
        res = res * 10 + min(num1 / t, min(num2 / t, num3 / t));
        num1 %= t;
        num2 %= t;
        num3 %= t;
        t /= 10;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 0
    cout << generateKey(1, 10, 1000) << endl;
    // 777
    cout << generateKey(987, 879, 798) << endl;
    // 1
    cout << generateKey(1, 2, 3) << endl;

    return 0;
}
