#include "../template/head.h"
#include <bits/stdc++.h>

bool checkInclusion(string s1, string s2) {
    // 思路：滑动窗口
    // 时间：O(kmn), 空间 O(k)
    if (s2.length() < s1.length()) {
        return 0;
    }

    vector<int> alpha(26), window(26);
    auto check = [&]() {
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != window[i]) {
                return 0;
            }
        }

        return 1;
    };

    for (int i = 0; i < s1.length(); i++) {
        alpha[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.length(); i++) {
        window[s2[i] - 'a']++;
        int j = i - s1.length();
        if (j >= 0) {
            window[s2[j] - 'a']--;
        }

        if (check()) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkInclusion("ab", "eidbaooo") << endl;

    // 0
    cout << checkInclusion("ab", "eidboaoo") << endl;

    return 0;
}
