#include "../template/head.h"
#include <bits/stdc++.h>

string reverseWords(string s) {
    // 思路：双指针 + 模拟
    // 时间 O(n)，空间 O(1)

    // 先原地整理
    // 再原地翻转
    int sz = s.length();
    int pos{};
    for (int i = 0; i < sz; i++) {
        if (s[i] == ' ') {
            if (pos != 0 && s[pos - 1] != ' ') {
                s[pos++] = ' ';
            }
        } else {
            s[pos++] = s[i];
        }
    }

    while (s.length() > pos || s.back() == ' ') {
        s.pop_back();
    }

    reverse(s.begin(), s.end());
    pos = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            reverse(s.begin() + pos, s.begin() + i);
            pos = i + 1;
        }
    }

    return s;
}

int main(int argc, char *argv[]) {
    // "blue is sky the"
    cout << reverseWords("the sky is blue") << endl;
    // "world hello"
    cout << reverseWords("  hello world  ") << endl;
    // "example good a"
    cout << reverseWords("a good   example") << endl;

    return 0;
}
