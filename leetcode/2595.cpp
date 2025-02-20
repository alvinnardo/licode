#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> evenOddBit(int n) {
    // 题解：位运算，优化了空间
    // 时间 O(logn)，空间 O(1)
    vector<int> res(2);

    // 0 和 1 取反
    int i = 0;
    while (n) {
        res[i] += (n & 1);
        n >>= 1;
        i ^= 1;
    }
    return res;
}

vector<int> evenOddBit1(int n) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)
    int even = 0, odd = 0, pos = 0;
    while (n) {
        if (pos & 1) {
            odd += (n & 1);
        } else {
            even += (n & 1);
        }
        pos++;
        n >>= 1;
    }

    return {even, odd};
}

int main(int argc, char *argv[]) {

    // {1, 2}
    printVector(evenOddBit(50));
    // {0, 1}
    printVector(evenOddBit(2));

    return 0;
}
