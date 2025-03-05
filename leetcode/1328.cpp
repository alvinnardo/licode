#include "../template/head.h"
#include <bits/stdc++.h>

string breakPalindrome(string palindrome) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)
    // 找到第一个非 a 的字符
    // 如果长度是奇数则需要跳过最中间的字符，因为无论怎么改都不会影响回文性 (坑)

    // 题解中给出，只需要遍历一半即可，直接就跳过奇数最中间的字符了
    if (palindrome.length() <= 1) {
        return "";
    }

    int len = palindrome.length(), pos = 0;
    int mid = (len & 1) ? (len >> 1) : -1;
    for (; pos < palindrome.length(); pos++) {
        if (pos == mid) {
            continue;
        }
        if (palindrome[pos] != 'a') {
            break;
        }
    }

    // 全是 a，改最后的 a
    if (pos == palindrome.length()) {
        palindrome[pos - 1] = 'b';
    } else {
        palindrome[pos] = 'a';
    }
    return palindrome;
}

int main(int argc, char *argv[]) {
    // "aaccba"
    cout << breakPalindrome("abccba") << endl;
    // ""
    cout << breakPalindrome("a") << endl;
    // "ab"
    cout << breakPalindrome("aa") << endl;
    cout << breakPalindrome("aba") << endl;

    return 0;
}
