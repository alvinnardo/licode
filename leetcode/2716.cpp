#include "../template/head.h"
#include <bits/stdc++.h>

int minimizedStringLength(string s) {
    // 思路：位运算
    // 时间 O(n)，空间 O(1)
    // 统计不同字符个数

    int bit = 0;
    for (char c : s) {
        bit |= (1 << (int)(c - 'a'));
    }

    return __builtin_popcount(bit);
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimizedStringLength("aaabc") << endl;
    // 3
    cout << minimizedStringLength("cbbd") << endl;
    // 2
    cout << minimizedStringLength("dddaaa") << endl;

    return 0;
}
