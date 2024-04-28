#include "../template/head.h"
#include <bits/stdc++.h>

string baseNeg2(int n) {
    // 思路：短除法，主要是要考虑负数对负数的求商和求余
    // 如果是正数，对 2 的商 和 对 2 的余，再还原负号
    // 如果是负数，绝对值是偶数，则直接对 2 商，余数是 0；
    // 绝对值是奇数，则取 绝对值 + 1 对 2 商，余数是 1
    if (!n) {
        return "0";
    }

    string ans;
    while (n) {
        if (n > 0) {
            ans += '0' + (n % 2);
            n = -(n / 2);
        } else if ((-n) & 1) {
            ans += '1';
            n = ((-n) + 1) / 2;
        } else {
            ans += '0';
            n = (-n) / 2;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char *argv[]) {
    // 0
    cout << baseNeg2(0) << endl;
    // 110
    cout << baseNeg2(2) << endl;
    // 111
    cout << baseNeg2(3) << endl;
    // 100
    cout << baseNeg2(4) << endl;
    // 11000000000000011
    cout << baseNeg2(32767) << endl;
    // 10000000000000011
    cout << baseNeg2(65535) << endl;
    // 11010000010100010000100000011
    cout << baseNeg2(99999999) << endl;
    // 1001100111011111101111000000000
    cout << baseNeg2(1000000000) << endl;

    return 0;
}
