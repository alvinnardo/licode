#include "../template/head.h"
#include <bits/stdc++.h>

long long validSubstringCount(string word1, string word2) {
    // 思路：双指针
    // 时间 O(nk)，空间 O(k)
    // 由于 word1 的子字符串可以乱序，所以只需要满足个数都相等即可
    // 双指针内的都不满足，外部的都满足
    vector<int> wa1(26), wa2(26);
    for (auto &c : word2) {
        wa2[c - 'a']++;
    }

    auto same = [&]() {
        for (int i = 0; i < 26; i++) {
            if (wa1[i] < wa2[i]) {
                return false;
            }
        }
        return true;
    };

    // 左闭右闭
    int j = 0, sz = word1.length();
    long long res = 0; // 马虎了
    for (int i = 0; i < sz; i++) {
        wa1[word1[i] - 'a']++;
        while (same()) { // 如果右侧一旦满足，左侧减少也可能满足
            res += sz - i;
            wa1[word1[j] - 'a']--;
            j++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << validSubstringCount("bcca", "abc") << endl;
    // 10
    cout << validSubstringCount("abcabc", "abc") << endl;
    // 0
    cout << validSubstringCount("abcabc", "aaabc") << endl;
    // 18
    cout << validSubstringCount("dcbdcdccb", "cdd") << endl;

    return 0;
}
