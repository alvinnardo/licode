#include "../template/head.h"
#include <bits/stdc++.h>

int maximumLength(string s) {
    // 思路：差分数组 + 哈希表
    // 时间 O(kn)，空间 O(kn)
    vector<vector<int>> alpha(26);

    int sz = s.length();
    int len = 0;
    char c;
    for (int i = 0; i < sz; i++) {
        if (len == 0 || s[i] != c) {
            c = s[i];
            len = 1;
        } else {
            len++;
        }

        int t = c - 'a';
        while (alpha[t].size() < len + 2) {
            alpha[t].push_back(0);
        }
        alpha[t][1]++;
        alpha[t][len + 1]--;
    }

    int maxv = -1;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < alpha[i].size(); j++) {
            alpha[i][j] += alpha[i][j - 1];
            if (alpha[i][j] >= 3) {
                maxv = max(maxv, j);
            }
        }
    }
    // printVectorVector(alpha);
    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maximumLength("aaaa") << endl;
    // -1
    cout << maximumLength("abcdef") << endl;
    // 1
    cout << maximumLength("abcaba") << endl;
    // 4
    cout << maximumLength("nnnnnbnnnn") << endl;

    return 0;
}
