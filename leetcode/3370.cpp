#include "../template/head.h"
#include <bits/stdc++.h>

int smallestNumber(int n) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)

    int t = 1;
    while (t < n) {
        t = (t << 1) + 1;
    }

    return t;
}

int main(int argc, char *argv[]) {
    // 7
    cout << smallestNumber(5) << endl;
    // 15
    cout << smallestNumber(10) << endl;
    // 3
    cout << smallestNumber(3) << endl;

    return 0;
}
