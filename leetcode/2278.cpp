#include "../template/head.h"
#include <bits/stdc++.h>

int percentageLetter(string s, char letter) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    int cnt = 0;
    for (auto &c : s) {
        cnt += (c == letter);
    }

    return cnt * 100 / s.length();
}

int main(int argc, char *argv[]) {
    // 33
    cout << percentageLetter("foobar", 'o') << endl;
    // 0
    cout << percentageLetter("jjjj", 'k') << endl;

    return 0;
}
