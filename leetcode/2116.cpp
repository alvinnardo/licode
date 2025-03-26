#include "../template/head.h"
#include <bits/stdc++.h>

bool canBeValid(string s, string locked) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    // 首先判断个数，不能为奇数
    // 满足 锁定的 ')' 前有能转换的即可
    // 满足 锁定的 '(' 后有能转换的即可
    int len = s.length();
    if (len & 1) {
        return false;
    }

    int cnt = 0, lcnt = 0;
    int cnt2 = 0, rcnt = 0;
    for (int i = 0; i < len; i++) {
        int j = len - i - 1;
        if (locked[i] == '0') {
            cnt++;
        } else {
            if (s[i] == '(') {
                lcnt++;
            } else if (s[i] == ')') {
                if (cnt == 0 && lcnt == 0) {
                    return false;
                }
                if (lcnt > 0) {
                    lcnt--;
                } else {
                    cnt--;
                }
            }
        }

        if (locked[j] == '0') {
            cnt2++;
        } else {
            if (s[j] == ')') {
                rcnt++;
            } else if (s[j] == '(') {
                if (cnt2 == 0 && rcnt == 0) {
                    return false;
                }
                if (rcnt > 0) {
                    rcnt--;
                } else {
                    cnt2--;
                }
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // true
    cout << canBeValid("))()))", "010100") << endl;
    // true
    cout << canBeValid("()()", "0000") << endl;
    // false
    cout << canBeValid(")", "0") << endl;
    // true
    cout << canBeValid("(((())(((())", "111111010111") << endl;

    return 0;
}
