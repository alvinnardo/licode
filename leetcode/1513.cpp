#include "../template/head.h"
#include <bits/stdc++.h>

int numSub(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int cnt{}, sz = s.length(), res{};
    const int mod = 1e9 + 7;
    for (int i = 0; i < sz; ++i) {
        if (s[i] == '0') {
            cnt = 0;
        } else {
            ++cnt;

            res = (res + cnt) % mod;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 9
    cout << numSub("0110111") << endl;
    // 2
    cout << numSub("101") << endl;
    // 21
    cout << numSub("111111") << endl;
    // 0
    cout << numSub("000") << endl;

    return 0;
}
