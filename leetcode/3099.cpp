#include "../template/head.h"
#include <bits/stdc++.h>

int sumOfTheDigitsOfHarshadNumber(int x) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)
    int o = x, sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }

    return o % sum == 0 ? sum : -1;
}

int main(int argc, char *argv[]) {
    // 9
    cout << sumOfTheDigitsOfHarshadNumber(18) << endl;
    // -1
    cout << sumOfTheDigitsOfHarshadNumber(23) << endl;

    return 0;
}
