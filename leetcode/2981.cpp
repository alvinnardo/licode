#include "../template/head.h"
#include <bits/stdc++.h>

int maximumLength(string s) {
    // 思路：哈希表
    // "aaaaa" 和 "aaaa" 的结果是 4
    // 把字符串所有可能进行统计
    // 时间 O(n2)，空间 O(k * alpha)
    int res = -1;
    vector<vector<int>> alpha(26, vector<int>(51));
    int len = 0;
    char head;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            len = 1;
            head = s[i];
        } else {
            if (s[i] == head) {
                len++;
            } else {
                len = 1;
                head = s[i];
            }
        }
        int a = head - 'a';
        for (int j = 1; j <= len; j++) {
            if (++alpha[a][j] == 3) {
                res = max(res, j);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maximumLength("aaaa") << endl;
    // -1
    cout << maximumLength("abcdef") << endl;
    // 1
    cout << maximumLength("abcaba") << endl;
    // 48
    cout << maximumLength("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
         << endl;
    // 3
    cout << maximumLength("aaaabaaacaaa") << endl;
    // 1
    cout << maximumLength("eccdnmcnkl") << endl;
    // 4
    cout << maximumLength("lkwwdddddnnnnnynnnnl") << endl;

    return 0;
}
