#include "../template/head.h"
#include <bits/stdc++.h>

string reorganizeString(string s) {
    // 思路：贪心，插空法，最多出现次数的字符个数要小于等于其它字符的个数
    // 时间 O(n)，空间 O(k)
    vector<int> alpha(26);
    int maxv = INT_MIN, pos = -1;
    for (auto &c : s) {
        int t = (int)(c - 'a');
        alpha[t]++;
        if (alpha[t] > maxv) {
            maxv = alpha[t];
            pos = t;
        }
    }

    if (maxv > s.length() - maxv + 1) {
        return "";
    }

    string res;
    while (res.length() != s.length()) {
        if (res.empty()) {
            res += (char)('a' + pos);
            alpha[pos]--;
        } else {
            int maxv = INT_MIN;
            int pos = -1;
            for (int i = 0; i < 26; i++) {
                if (i == (int)(res.back() - 'a')) {
                    continue;
                }
                if (alpha[i] > maxv) {
                    maxv = alpha[i];
                    pos = i;
                }
            }

            res += (char)('a' + pos);
            alpha[pos]--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // "aba"
    cout << reorganizeString("aab") << endl;
    // ""
    cout << reorganizeString("aaab") << endl;

    return 0;
}
