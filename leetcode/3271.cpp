#include "../template/head.h"
#include <bits/stdc++.h>

string stringHash(string s, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    string res;
    int cnt = 0, sum = 0;
    for (char c : s) {
        sum += (int)(c - 'a');
        ++cnt;
        if (cnt % k == 0) {
            res += 'a' + (int)(sum % 26);
            sum = 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "bf"
    cout << stringHash("abcd", 2) << endl;
    // "i"
    cout << stringHash("mxz", 3) << endl;

    return 0;
}
