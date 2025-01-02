#include "../template/head.h"
#include <bits/stdc++.h>

string convertDateToBinary(string date) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    string tmp;
    std::stringstream ss;

    auto getBinary = [](int t) {
        string res;
        while (t) {
            res += '0' + (t & 1);
            t >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    };

    for (char c : date) {
        if (c == '-') {
            ss << getBinary(atoi(tmp.c_str())) << "-";
            tmp.clear();
            continue;
        }
        tmp += c;
    }
    ss << getBinary(atoi(tmp.c_str()));
    return ss.str();
}

int main(int argc, char *argv[]) {
    // "100000100000-10-11101"
    cout << convertDateToBinary("2080-02-29") << endl;
    cout << convertDateToBinary("2200-02-29") << endl;
    // "11101101100-1-1"
    cout << convertDateToBinary("1900-01-01") << endl;

    return 0;
}
