#include "../template/head.h"
#include <bits/stdc++.h>

string removeTrailingZeros(string num) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    while (num.back() == '0') {
        num.pop_back();
    }
    return num;
}

int main(int argc, char *argv[]) {
    // "512301"
    cout << removeTrailingZeros("51230100") << endl;
    // "123"
    cout << removeTrailingZeros("123") << endl;

    return 0;
}
