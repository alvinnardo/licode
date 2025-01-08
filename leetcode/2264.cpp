#include "../template/head.h"
#include <bits/stdc++.h>

string largestGoodInteger(string num) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    string res;
    for (int i = 2; i < num.size(); i++) {
        if (num[i] == num[i - 1] && num[i] == num[i - 2] &&
            (res.empty() || num[i] > res[0])) {
            res = string(3, num[i]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "777"
    cout << largestGoodInteger("6777133339") << endl;
    // "000"
    cout << largestGoodInteger("2300019") << endl;
    // ""
    cout << largestGoodInteger("42352338") << endl;

    return 0;
}
