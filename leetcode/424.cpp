#include "../template/head.h"
#include <bits/stdc++.h>
int characterReplacement(string s, int k) {
    // 题解给出的算法比较难理解
    // 1. 满足条件增大窗口，不满足条件向右滑动一次窗口
    // 2. 记录历史出现的最大出现次数，
    // 如果窗口中的最大次数超过历史中的最大次数，则可以增加窗口
    int len = s.length();
    int left = 0, right = 0, max_count = INT_MIN;
    int alpha[26]{};

    // 持续增大窗口
    for (right = 0; right < len; right++) {
        alpha[s[right] - 'A']++;
        max_count = max(max_count, alpha[s[right] - 'A']);

        // 窗口大小 - 出现最大的次数 就是其余不同的字母，和 k 比较
        // 如果不能替换，则缩小左边，相当于 left++, right++，即平移窗口
        // 这里的 right 还没有 + 1, 题解中是先加一再判断的
        if (right - left + 1 - max_count > k) {
            alpha[s[left] - 'A']--;
            left++;
        }
    }

    // 返回窗口的大小
    return right - left;
}

int characterReplacement_my(string s, int k) {
    // 思路：对每个字符做双指针滑动窗口

    // 第一次遍历，找到所有出现的字符
    // 时间 O(kn), k 的大小是 s 中不同字符的个数, 空间 O(1)
    int alpha[26]{};
    for (auto &c : s) {
        alpha[c - 'A'] = 1;
    }
    int max_len = 1, slen = s.length();

    auto getMaxLen = [&](char c, int k) {
        // i 指向上一次不是 c 字符的位置
        // j 指向最长串的末尾位置
        int i = -1, j = -1, t = k;
        while (j + 1 < slen) {
            j++;

            if (s[j] != c) {
                if (t > 0) { // 可以复活
                    t--;
                } else {
                    do {
                        i++;
                    } while (s[i] == c);
                }
            }

            max_len = max(max_len, j - i);
        }
    };

    for (int i = 0; i < 26; i++) {
        if (alpha[i] != 0) {
            getMaxLen('A' + i, k);
        }
    }

    return max_len;
}

int main(int argc, char *argv[]) {
    // 4
    cout << characterReplacement("ABAB", 2) << endl;
    // 4
    cout << characterReplacement("AABABBA", 1) << endl;
    // 10
    cout << characterReplacement("AAAAAAAAAA", 1) << endl;
    // 2
    cout << characterReplacement("ABCDEFGHIJK", 1) << endl;

    return 0;
}
