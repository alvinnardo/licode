#include "../template/head.h"
#include <bits/stdc++.h>

int maxFreqSum(string s) {
    // 思路：模拟 + 哈希表
    // 时间 O(n)，空间 O(k)
    int maxa = 0, maxb = 0;

    vector<int> alpha(26);
    auto len(s.length());
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            maxa = max(maxa, ++alpha[s[i] - 'a']);
        } else {
            maxb = max(maxb, ++alpha[s[i] - 'a']);
        }
    }

    return maxa + maxb;
}

int main(int argc, char *argv[]) {
    // 6
    cout << maxFreqSum("successes") << endl;
    // 3
    cout << maxFreqSum("aeiaeia") << endl;

    return 0;
}
