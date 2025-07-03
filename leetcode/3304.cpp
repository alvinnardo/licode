#include "../template/head.h"
#include <bits/stdc++.h>

char kthCharacter(int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    string s = "abbcbccdbccdcddebccdcddecddedeefbccdcddecddedeefcddedeefdeefeff"
               "gbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfg"
               "ghbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgf"
               "gghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfggh"
               "ghhibccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeff"
               "gfgghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfg"
               "ghghhicddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghf"
               "gghghhideefeffgeffgfggheffgfgghfgghghhieffgfgghfgghghhifgghg";

    return s[k - 1];
}

int main(int argc, char *argv[]) {
    // string s = "a";
    // while (s.length() < 501) {
    //     string t = s;
    //     for (int i = 0; i < t.size(); i++) {
    //         s.push_back(t[i] + 1);
    //     }
    // }
    // s.resize(501);
    // cout << s << endl;

    // "b"
    cout << kthCharacter(5) << endl;
    // "c"
    cout << kthCharacter(10) << endl;

    return 0;
}
