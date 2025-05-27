#include "../template/head.h"
#include <bits/stdc++.h>

int differenceOfSums(int n, int m) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % m == 0) {
            num2 += i;
        } else {
            num1 += i;
        }
    }

    return num1 - num2;
}

int main(int argc, char *argv[]) {
    // 19
    cout << differenceOfSums(10, 3) << endl;
    // 15
    cout << differenceOfSums(5, 6) << endl;
    // -15
    cout << differenceOfSums(5, 1) << endl;

    return 0;
}
