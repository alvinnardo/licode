#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> findAnagrams(string s, string p) {
    // 题解：优化的滑动窗口，记录差值
    // 时间 O(m + n + 26)，空间 O(26)
    int m = s.length(), n = p.length();
    if (m < n) {
        return {};
    }
    int tmp_alpha[26]{};
    int diff = 0;

    for (int i = 0; i < n; i++) {
        tmp_alpha[s[i] - 'a']++;
        tmp_alpha[p[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (tmp_alpha[i] != 0) {
            diff++;
        }
    }

    vector<int> res;
    if (diff == 0) {
        res.push_back(0);
    }

    for (int i = n; i < m; i++) {
        int t = s[i] - 'a';
        if (tmp_alpha[t] == -1) { // 不同 -> 同
            diff -= 1;
        } else if (tmp_alpha[t] == 0) { // 同 -> 不同
            diff += 1;
        }
        tmp_alpha[t]++;

        t = s[i - n] - 'a';
        if (tmp_alpha[t] == 1) { // 不同 -> 同
            diff -= 1;
        } else if (tmp_alpha[t] == 0) { // 同 -> 不同
            diff += 1;
        }
        tmp_alpha[t]--;

        if (diff == 0) {
            res.push_back(i - n + 1);
        }
    }

    return res;
}

vector<int> findAnagrams1(string s, string p) {
    // 思路：滑动窗口 + 哈希表
    // 时间: O(26(m - n + 1) + m + n), 空间: O(26)
    int m = s.length(), n = p.length();
    if (m < n) {
        return {};
    }

    int tmp_alpha[26]{}, p_alpha[26]{};
    auto isMatch = [&]() { // 是否是异构词
        for (int i = 0; i < 26; i++) {
            if (tmp_alpha[i] != p_alpha[i]) {
                return false;
            }
        }
        return true;
    };

    for (auto &c : p) {
        p_alpha[c - 'a']++;
    }

    vector<int> res;
    int i = 0;
    for (int j = 0; j < m; j++) {
        tmp_alpha[s[j] - 'a']++;
        if (j - i + 1 > n) {
            tmp_alpha[s[i] - 'a']--;
            i++;
        }

        if (j - i + 1 == n && isMatch()) {
            res.push_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [0, 6]
    printVector(findAnagrams("cbaebabacd", "abc"));
    // [0, 1, 2]
    printVector(findAnagrams("abab", "ab"));
    // []
    printVector(findAnagrams("abab", "ababb"));

    return 0;
}
