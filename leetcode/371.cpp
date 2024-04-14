#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    // 题解：分解为无符号求和 和 进位求和
    // 进位依次左移直至为 0
    // 进位右移一位再异或，表示所有位与进位做了一次加法
    // 如果还有 1，那么就是产生的第二次进位

    while (b != 0) {
        int c = (a & b) << 1;
        a = a ^ b;
        b = c;
    }

    return a;
}

int getSum_my(int a, int b) {
    // 模拟 ALU
    int c = 0, x = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        x |= (a ^ b ^ c) & mask;
        c = ((c & (a ^ b)) | (a & b)) & mask;
        c <<= 1;
        mask <<= 1;
    }

    return x;
}

int main(void) {
    cout << getSum(1, 2) << endl;
    cout << getSum(2, 3) << endl;
    cout << getSum(0, 0) << endl;
    cout << getSum(-100, 1000) << endl;
    cout << getSum(-1000, 1) << endl;
    cout << getSum(-1000, 1000) << endl;
    auto t = getNRandom(-1000, 1000, 2000);
    for (int i = 0; i < 1000; i++) {
        int a = t[i * 2], b = t[i * 2 + 1];
        cout << a << " " << b << " " << a + b << ": " << getSum(a, b) <<
        endl;
    }

    return 0;
}
