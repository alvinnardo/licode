#include "../template/head.h"
#include <bits/stdc++.h>

int countPalindromicSubsequence(string s) {
    // 思路：统计 + 哈希表 + 位运算
    // 时间 O(kn)，空间 O(k)

    // 固定中间的字符，左边和右边相同即可
    vector<int> left(26), right(26);
    vector<int> vv(26); // 优化：用位标记
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        right[s[i] - 'a']++;
    }

    int res{};
    right[s[0] - 'a']--;
    int a{}, b{};
    for (int i = 1; i < sz - 1; i++) {
        a = s[i - 1] - 'a';
        b = s[i] - 'a';

        left[a]++;
        right[b]--;

        for (int j = 0; j < 26; j++) {
            if (left[j] && right[j] && (vv[b] & (1 << j)) == 0) {
                res++;
                vv[b] |= (1 << j);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countPalindromicSubsequence("aabca") << endl;
    // 0
    cout << countPalindromicSubsequence("adc") << endl;
    // 4
    cout << countPalindromicSubsequence("bbcbaba") << endl;

    return 0;
}
