#include "../template/head.h"
#include <bits/stdc++.h>

int maxDifference(string s) {
    // 思路：统计
    // 时间 O(n + k)，空间 O(k)
    vector<int> alpha(26);

    for (int i = 0; i < s.length(); i++) {
        alpha[s[i] - 'a']++;
    }

    int maxv = INT_MIN, minv = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            continue;
        }
        if (alpha[i] & 1) {
            maxv = max(maxv, alpha[i]);
        } else {
            minv = min(minv, alpha[i]);
        }
    }

    return maxv - minv;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxDifference("aaaaabbc") << endl;
    // 1
    cout << maxDifference("abcabcab") << endl;

    return 0;
}
