#include "../template/head.h"
#include <bits/stdc++.h>

bool isPowerOfTwo1(int n) {
    // 思路：stl
    // 时间 O(1)，空间 O(1)
    if (n < 0) {
        return false;
    }
    return std::has_single_bit((uint)n);
}

bool isPowerOfTwo(int n) {
    // 思路：bit
    // 时间 O(1)，空间 O(1)

    // 把 stl 展开
    // x & (x - 1) 去掉最后一位
    if (n < 0) {
        return false;
    }
    // 之前不是 0，去掉一个 1 后是 0
    return n && !(n & (n - 1));
}

int main(int argc, char *argv[]) {
    // 1
    cout << isPowerOfTwo(1) << endl;
    // 1
    cout << isPowerOfTwo(16) << endl;
    // 0
    cout << isPowerOfTwo(3) << endl;

    return 0;
}
