#include "../template/head.h"
#include <bits/stdc++.h>

int totalMoney(int n) {
    // 思路：数学
    // 时间 O(1)，空间 O(1)

    // div 是满的层，mod 是不满的层余下的个数
    int div = n / 7, mod = n % 7;
    return div * 28 + 7 * (((1 + div - 1) * (div - 1)) >> 1) +
           (((div + 1 + div + mod) * mod) >> 1);
}

int main(int argc, char *argv[]) {
    // 10
    cout << totalMoney(4) << endl;
    // 37
    cout << totalMoney(10) << endl;
    // 96
    cout << totalMoney(20) << endl;

    return 0;
}
