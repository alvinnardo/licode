#include "../template/head.h"
#include <bits/stdc++.h>

string reverseStr(string s, int k) {
    // 思路：模拟
    // 每隔 k 个翻转一次
    // 时间 O(n)，空间 O(1)
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        cnt++;
        if (cnt % k == 0 && (cnt / k) & 1) {
            reverse(s.begin() + cnt - k, s.begin() + cnt);
        }
    }

    if (((cnt / k) & 1) == 0) {
        reverse(s.begin() + (cnt / k) * k, s.begin() + cnt);
    }

    return s;
}

int main(int argc, char *argv[]) {
    // "bacdfeg"
    cout << reverseStr("abcdefg", 2) << endl;
    // "bacd"
    cout << reverseStr("abcd", 2) << endl;
    // "cbadefhg"
    cout << reverseStr("abcdefgh", 3) << endl;

    return 0;
}
