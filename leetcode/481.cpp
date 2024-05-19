#include "../template/head.h"
#include <bits/stdc++.h>

int magicalString(int n) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    if (n <= 3) {
        return 1;
    }

    string s = "122";
    char next = '1';
    int pos = 2, res = 1;

    while (true) {
        int cnt = s[pos] - '0';
        while (cnt--) {
            s += next;
            if (next == '1') {
                res++;
            }

            // 及时停止添加，如 n = 4 时
            if (s.length() >= n) {
                break;
            }
        }

        if (s.length() >= n) {
            break;
        }

        pos++;
        next = next == '1' ? '2' : '1';
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << magicalString(1) << endl;
    // 1
    cout << magicalString(2) << endl;
    // 1
    cout << magicalString(3) << endl;
    // 2
    cout << magicalString(4) << endl;
    // 3
    cout << magicalString(6) << endl;
    // 49972
    cout << magicalString(100000) << endl;
    return 0;
}
