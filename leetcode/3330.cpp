#include "../template/head.h"
#include <bits/stdc++.h>

int possibleStringCount(string word) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int res = 0;

    for (int i = 1; i < word.size(); i++) {
        res += word[i] == word[i - 1];
    }

    return res + 1;
}

int main(int argc, char *argv[]) {
    // 5
    cout << possibleStringCount("abbcccc") << endl;
    // 1
    cout << possibleStringCount("abcd") << endl;
    // 4
    cout << possibleStringCount("aaaa") << endl;

    return 0;
}
