#include "../template/head.h"
#include <bits/stdc++.h>

string smallestString(string s) {
    // 思路：贪心，分三段，第一段从不为 a 的地方开始，第二段 -1，第三段恢复
    // 恰好一次，所以如果没有变化的话，需要手动 - 1
    // 时间 O(n)，空间 O(1)
    string res;
    int len = s.length(), pos = 0;
    while (pos < len && s[pos] == 'a') {
        res += s[pos];
        pos++;
    }

    while (pos < len && s[pos] != 'a') {
        res += s[pos] - 1;
        pos++;
    }

    while (pos < len) {
        res += s[pos];
        pos++;
    }

    if (res == s) {
        res.pop_back();
        res += 'z';
    }
    return res;
}

int main(int argc, char *argv[]) {
    // "baabc"
    cout << smallestString("cbabc") << endl;
    // "abaab"
    cout << smallestString("acbbc") << endl;
    // "kddsbncd"
    cout << smallestString("leetcode") << endl;
    cout << smallestString("aaaaaa") << endl;
    cout << smallestString("aaaaaafljslkdjf") << endl;
    cout << smallestString("aaaaaafljslkdjfaaaa") << endl;
    cout << smallestString("aa") << endl;

    return 0;
}
