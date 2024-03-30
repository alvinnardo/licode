#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> res;

    string tmp;
    function<void(int, int)> dfs = [&](int pos, int cnt) {
        if (pos != s.length() && cnt == 0 || cnt < 0) {
            return;
        }
        if (pos == s.length()) {
            if (cnt == 0) {
                res.emplace_back(tmp.begin(), tmp.end() - 1);
            }
            return;
        }

        // 1 位
        tmp += string(1, s[pos]) + '.';
        dfs(pos + 1, cnt - 1);
        tmp.resize(tmp.size() - 2);

        // 2 位
        if (pos + 1 < s.length() && s[pos] > '0') {
            tmp += string(1, s[pos]) + s[pos + 1] + '.';
            dfs(pos + 2, cnt - 1);
            tmp.resize(tmp.size() - 3);
        }

        // 3 位
        if (pos + 2 < s.length()) {
            if (s[pos] == '1' ||
                s[pos] == '2' && (s[pos + 1] <= '4' ||
                                  s[pos + 1] == '5' && s[pos + 2] <= '5')) {
                tmp += string(1, s[pos]) + s[pos + 1] + s[pos + 2] + '.';
                dfs(pos + 3, cnt - 1);
                tmp.resize(tmp.size() - 4);
            }
        }
    };

    dfs(0, 4);
    return res;
}

int main(void) {
    printVector(restoreIpAddresses("25525511135"));
    printVector(restoreIpAddresses("0000"));
    printVector(restoreIpAddresses("00000"));
    printVector(restoreIpAddresses("101023"));
    printVector(restoreIpAddresses("100100100100"));
    printVector(restoreIpAddresses("2562411"));
    printVector(restoreIpAddresses("172162541"));

    return 0;
}
