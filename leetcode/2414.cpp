#include "../template/head.h"
#include <bits/stdc++.h>

int longestContinuousSubstring(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int cnt = 1, max_cnt = 1, len = s.length();
    for (int i = 1; i < len; i++) {
        if (s[i] - s[i - 1] == 1) {
            cnt++;
            max_cnt = max(cnt, max_cnt);
        } else {
            cnt = 1;
        }
    }

    return max_cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << longestContinuousSubstring("abacaba") << endl;
    // 5
    cout << longestContinuousSubstring("abcde") << endl;

    return 0;
}
