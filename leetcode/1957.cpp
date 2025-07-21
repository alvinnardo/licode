#include "../template/head.h"
#include <bits/stdc++.h>

string makeFancyString(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (i < 2) {
            res += s[i];
            continue;
        }

        if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            continue;
        }
        res += s[i];
    }
    return res;
}

int main(int argc, char *argv[]) {
    // "leetcode"
    cout << makeFancyString("leeetcode") << endl;
    // "aabaa"
    cout << makeFancyString("aaabaaaa") << endl;
    // "aab"
    cout << makeFancyString("aab") << endl;

    return 0;
}
