#include "../template/head.h"
#include <bits/stdc++.h>

int repeatedStringMatch(string a, string b) {
    // 思路：分类讨论
    int alen = a.length(), blen = b.length();
    string t;
    int cnt = 0;
    if (alen >= blen) {
        t = a;
        cnt = 1;
    } else {
        while (t.length() < blen) {
            t += a;
            cnt++;
        }
    }

    if (t.find(b) != string::npos) {
        return cnt;
    }
    t += a;
    if (t.find(b) != string::npos) {
        return cnt + 1;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 3
    cout << repeatedStringMatch("abcd", "cdabcdab") << endl;
    // 2
    cout << repeatedStringMatch("a", "aa") << endl;
    // 1
    cout << repeatedStringMatch("a", "a") << endl;
    // -1
    cout << repeatedStringMatch("abc", "wxyz") << endl;
    // 4
    cout << repeatedStringMatch("abc", "cabcabca") << endl;

    return 0;
}
