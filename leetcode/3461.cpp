#include "../template/head.h"
#include <bits/stdc++.h>

bool hasSameDigits(string s) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(n)
    int sz = s.length();
    string tmp;

    while (s.length() > 2) {
        tmp.clear();
        for (int i = 0; i < s.length() - 1; i++) {
            tmp += ('0' + ((s[i] - '0') + (s[i + 1] - '0')) % 10);
        }

        s = tmp;
    }

    return s[0] == s[1];
}

int main(int argc, char *argv[]) {
    // 1
    cout << hasSameDigits("3902") << endl;
    // 0
    cout << hasSameDigits("34789") << endl;

    return 0;
}
