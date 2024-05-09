#include "../template/head.h"
#include <bits/stdc++.h>

int findSubstringInWraproundString(string s) {
    // 思路：找连续递增的字符串，并使用哈希表来存放字符串
    // 哈希表中存放尾字符和最长长度，因为长的长度包含短的长度的字符串
    // 存放尾字符和长度要优于存放首字母和长度，如果是首字符，
    // 还需要计算如 "abc" 和 "bc" 重复子串
    // 时间 O(n + 26)，空间 O(26)
    int len = s.length(), tlen = 1;
    vector<int> alpha(26);

    for (int i = 0; i < len; i++) {
        int t = s[i] - 'a';
        if (i && (s[i] == 'a' && s[i - 1] == 'z' || s[i] - s[i - 1] == 1)) {
            tlen++;
        } else {
            tlen = 1;
        }
        alpha[t] = max(alpha[t], tlen);
    }

    return accumulate(alpha.begin(), alpha.end(), 0);
}

int main(int argc, char *argv[]) {
    // 1
    cout << findSubstringInWraproundString("a") << endl;
    // 2
    cout << findSubstringInWraproundString("cac") << endl;
    // 7
    cout << findSubstringInWraproundString("zabdab") << endl;

    return 0;
}
