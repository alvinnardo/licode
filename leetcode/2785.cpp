#include "../template/head.h"
#include <bits/stdc++.h>

string sortVowels(string s) {
    // 思路：计数排序 + 红黑树
    // 时间 O(nlogk)，空间 O(k)
    map<int, int> mm{{'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0},
                     {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

    std::ranges::for_each(s, [&mm](char c) {
        if (mm.count(c)) {
            mm[c]++;
        }
    });

    auto it = mm.begin();
    for (int i = 0; i < s.length(); i++) {
        while (it != mm.end() && it->second == 0) {
            it++;
        }

        if (it == mm.end()) {
            break;
        }

        if (mm.count(s[i])) {
            s[i] = it->first;
            it->second--;
        }
    }

    return s;
}

int main(int argc, char *argv[]) {
    // "lEOtcede"
    cout << sortVowels("lEetcOde") << endl;
    // "lYmpH"
    cout << sortVowels("lYmpH") << endl;

    return 0;
}
