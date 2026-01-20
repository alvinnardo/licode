#include "../template/head.h"
#include <bits/stdc++.h>

int lengthOfLastWord(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    while (s.back() == ' ') {
        s.pop_back();
    }

    int res{};
    while (s.length() > 0) {
        if (s.back() == ' ') {
            break;
        } else {
            ++res;
            s.pop_back();
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << lengthOfLastWord("Hello World") << endl;
    // 4
    cout << lengthOfLastWord("   fly me   to   the moon  ") << endl;
    // 6
    cout << lengthOfLastWord("luffy is still joyboy") << endl;

    return 0;
}
