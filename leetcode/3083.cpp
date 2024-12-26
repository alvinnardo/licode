#include "../template/head.h"
#include <bits/stdc++.h>

bool isSubstringPresent(string s) {
    // 思路：模拟
    // 字符串不变，查找倒转的两个长度的字符串
    // 时间 O(n2)，空间 O(1)
    string tmp = "11";
    for (int i = 0; i < s.length() - 1; i++) {
        tmp[0] = s[i + 1];
        tmp[1] = s[i];
        if (s.find(tmp, 0) != std::string::npos) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << isSubstringPresent("leetcode") << endl;
    // 1
    cout << isSubstringPresent("abcba") << endl;
    // 0
    cout << isSubstringPresent("abcd") << endl;

    return 0;
}
