#include "../template/head.h"
#include <bits/stdc++.h>

int countPrefixes(vector<string> words, string s) {
    // 思路：模拟
    // 时间 O(nk)，k 是平均长度，空间 O(1)

    int res = 0;

    for (const auto &word : words) {
        if (word.length() > s.length()) {
            continue;
        }

        bool match = true;
        for (int i = 0; i < word.length(); i++) {
            if (s[i] != word[i]) {
                match = false;
                break;
            }
        }

        res += match;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countPrefixes({"a", "b", "c", "ab", "bc", "abc"}, "abc") << endl;
    // 2
    cout << countPrefixes({"a", "a"}, "aa") << endl;

    return 0;
}
