#include "../template/head.h"
#include <bits/stdc++.h>

int countKConstraintSubstrings(string s, int k) {
    // 思路：模拟
    // 枚举所有子串
    // 时间 O(n2)，空间 O(1)
    int len = s.length(), one = 0, zero = 0, res = 0;
    for (int i = 0; i < len; i++) {
        one = zero = 0;
        for (int j = i; j >= 0; j--) {
            one += s[j] == '1';
            zero += s[j] == '0';
            // 满足一个条件即可, 或的关系
            // 其余条件不成立
            if (one > k && zero > k) {
                break;
            }
            res++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 12
    cout << countKConstraintSubstrings("10101", 1) << endl;
    // 25
    cout << countKConstraintSubstrings("1010101", 2) << endl;
    // 15
    cout << countKConstraintSubstrings("11111", 1) << endl;

    return 0;
}
