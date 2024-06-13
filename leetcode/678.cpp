#include "../template/head.h"
#include <bits/stdc++.h>

bool checkValidString(string s) {
    // 思路：贪心，正向和逆向都判断一遍
    // 时间 O(n)，空间 O(1)

    int len = s.length();
    int left = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '*') {
            left++;
        } else {
            if (left <= 0) {
                return false;
            }
            left--;
        }
    }
    int right = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ')' || s[i] == '*') {
            right++;
        } else {
            if (right <= 0) {
                return false;
            }
            right--;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {

    // 1
    cout << checkValidString("()") << endl;
    // 1
    cout << checkValidString("(*)") << endl;
    // 1
    cout << checkValidString("(*))") << endl;
    cout << checkValidString("*))") << endl;
    cout << checkValidString(")") << endl;

    return 0;
}
