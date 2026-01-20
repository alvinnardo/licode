#include "../template/head.h"
#include <bits/stdc++.h>

string convert(string s, int numRows) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    if (numRows == 1) {
        return s;
    }

    vector<string> vv(numRows);
    int len = s.length();
    int pos{}, flag = 1;
    for (int i = 0; i < len; ++i) {
        if (numRows == 2) {
            flag = 1;
        }
        vv[pos].push_back(s[i]);
        if (flag > 0) {
            pos++;
            if (pos == numRows) {
                flag = -flag;
                pos = numRows - 2;
            }
        } else {
            pos--;
            if (pos < 0) {
                flag = -flag;
                pos = 1;
            }
        }
    }

    string res;
    for (auto &s : vv) {
        res += s;
    }
    return res;
}

int main(int argc, char *argv[]) {
    // "PAHNAPLSIIGYIR"
    cout << convert("PAYPALISHIRING", 3) << endl;
    // "PINALSIGYAHRPI"
    cout << convert("PAYPALISHIRING", 4) << endl;
    // "A"
    cout << convert("A", 1) << endl;

    return 0;
}
