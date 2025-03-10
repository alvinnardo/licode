#include "../template/head.h"
#include <bits/stdc++.h>

int divisorSubstrings(int num, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)，n 是 num 十进制位数
    if (k == 10) { // 超 int32 了
        return 1;
    }

    int cpy = num;
    int cnt = 0, tmp = 1;
    while (k--) {
        tmp *= 10;
    }

    int pre = tmp / 10;
    while (cpy >= pre) {
        if (cpy % tmp) { // 不能等于 0
            cnt += num % (cpy % tmp) == 0;
        }
        cpy /= 10;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << divisorSubstrings(43000043, 2) << endl;
    // 3
    cout << divisorSubstrings(24000024, 2) << endl;
    // 2
    cout << divisorSubstrings(240, 2) << endl;
    cout << divisorSubstrings(1000000000, 10) << endl;

    return 0;
}
