#include "../template/head.h"
#include <bits/stdc++.h>

double nthPersonGetsNthSeat(int n) {
    // 思路：数学 概率
    // 找对的概率是 1/n，找错后最后一个成功的概率都是 1/n * 1/2
    // 最后加起来看到结果都是 1/2
    // 当 n >= 2 时，递归公式是
    // f(n) = 1/n + 1/n * (f(n - 1) + f(n - 2) + ... + f(2)) = 1/2
    // 时间 O(1)，空间 O(1)

    return n == 1 ? 1 : 0.5;
}

int main(int argc, char *argv[]) {
    // 1
    cout << nthPersonGetsNthSeat(1) << endl;
    // 0.5
    cout << nthPersonGetsNthSeat(2) << endl;

    return 0;
}
