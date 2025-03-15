#include "../template/head.h"
#include <bits/stdc++.h>

int scoreOfString(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        res += s[i] > s[i - 1] ? s[i] - s[i - 1] : s[i - 1] - s[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 13
    cout << scoreOfString("hello") << endl;
    // 50
    cout << scoreOfString("zaz") << endl;

    return 0;
}
