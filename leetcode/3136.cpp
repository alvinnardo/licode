#include "../template/head.h"
#include <bits/stdc++.h>

bool isValid(string word) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    if (word.size() < 3) {
        return false;
    }

    unordered_set<char> uset_special{'@', '#', '$'};
    unordered_set<char> uset_yuan{'a', 'e', 'i', 'o', 'u'};
    bool has_yuan = false, has_fu = false;
    for (int i = 0; i < word.length(); i++) {
        if (uset_special.find(word[i]) != uset_special.end()) {
            return false;
        }

        if (isalpha(word[i])) {
            word[i] = tolower(word[i]);
            if (uset_yuan.count(word[i])) {
                has_yuan = true;
            } else {
                has_fu = true;
            }
        }
    }

    return has_yuan && has_fu;
}

int main(int argc, char *argv[]) {
    // 1
    cout << isValid("234Adas") << endl;
    // 0
    cout << isValid("b3") << endl;
    // 0
    cout << isValid("a3$e") << endl;

    return 0;
}
