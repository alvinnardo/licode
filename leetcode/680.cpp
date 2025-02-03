#include "../template/head.h"
#include <bits/stdc++.h>

bool validPalindrome(string s) {
    // 思路：模拟 + 贪心
    // 翻转字符串费时间，则不翻转
    // 时间 O(n)，空间 O(1)
    auto check = [&](bool rev) {
        int i = 0, j = s.length() - 1;
        bool is_skip = false;
        while (i < j) {
            if (s[i] != s[j]) {
                if (!is_skip) {
                    is_skip = true;
                } else {
                    return false;
                }
                // 从前往后跳过 或者 从后往前跳过
                if (rev) {
                    i++;
                } else {
                    j--;
                }
            } else {
                i++;
                j--;
            }
        }
        return true;
    };

    return check(false) || check(true);
}

bool validPalindrome1(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    // 一个从前往后，一个从后往前
    // 可以删除一个，可以从后往前删除一个，也可以从前往后删除一个
    // 如果跳过一个后还有不同的则失败
    auto check = [](const auto &s) {
        int i = 0, j = s.length() - 1;
        bool is_skip = false;
        while (i < j) {
            if (s[i] != s[j]) {
                if (!is_skip) {
                    is_skip = true;
                } else {
                    return false;
                }
                i++;
            } else {
                i++;
                j--;
            }
        }
        return true;
    };

    if (check(s)) {
        return true;
    }

    reverse(s.begin(), s.end());
    return check(s);
}

int main(int argc, char *argv[]) {
    // 1
    cout << validPalindrome("aba") << endl;
    // 1
    cout << validPalindrome("abca") << endl;
    // 0
    cout << validPalindrome("abc") << endl;
    // 1
    cout << validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxj"
                            "jxqncffvmhvgsymdjgpf"
                            "dhooxfuupuculmgmqfvnbgtapekouga")
         << endl;

    return 0;
}
