#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int findNthDigit(int n) {

    // 思路：根据规律找到长度所在区间，然后在该区间中再找
    long long nn = n, i = 1, begin = 1;
    long long t = i * begin * 9;
    while (nn > t) {
        nn -= t;
        i++;
        begin *= 10;
        t = i * begin * 9;
    }

    // 找到该位所在的数字
    int num = (nn - 1) / i + begin;
    int pos = i - (nn - 1) % i - 1; // 除 10 几次
    while (pos--) {
        num /= 10;
    }

    return num % 10;
}

int main(void) {
    cout << findNthDigit(1) << endl;
    cout << findNthDigit(3) << endl;
    cout << findNthDigit(11) << endl;
    cout << findNthDigit(189) << endl;
    cout << findNthDigit(1000000000) << endl;
    cout << findNthDigit(INT_MAX) << endl;

    return 0;
}
