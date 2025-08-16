#include "../template/head.h"
#include <bits/stdc++.h>

int maximum69Number(int num) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)

    int p = 1000;
    while (p) {
        if (num > p) {
            if (num / p % 10 == 6) {
                num += 3 * p;
                break;
            }
        }
        p /= 10;
    }

    return num;
}

int main(int argc, char *argv[]) {
    // 9969
    cout << maximum69Number(9669) << endl;
    // 9999
    cout << maximum69Number(9996) << endl;
    // 9999
    cout << maximum69Number(9999) << endl;

    return 0;
}
