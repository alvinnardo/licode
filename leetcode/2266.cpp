#include "../template/head.h"
#include <bits/stdc++.h>

int countTexts(string pressedKeys) {
    // 思路：dp
    // 时间 O(kn)，空间 O(k), k = 4

    constexpr int mod = 1e9 + 7;
    char pre = '0';
    vector<int> tmp;
    int cur = 0;
    long long res = 1;
    for (char c : pressedKeys) {
        if (c != pre) {
            if (pre != '0') {
                res = (res * tmp[cur]) % mod;
            }
            tmp.clear();
            cur = 0;
            if (c == '7' || c == '9') {
                tmp.assign(5, 0);
            } else {
                tmp.assign(4, 0);
            }
            tmp[0] = 1;
            pre = c;
        }

        long long sum = 0;
        if (cur == tmp.size() - 1) {
            for (int i = 1; i < tmp.size(); i++) {
                sum = (sum + tmp[i]) % mod;
                tmp[i - 1] = tmp[i];
            }
        } else {
            for (int i = 0; i <= cur; i++) {
                sum = (sum + tmp[i]) % mod;
            }
            cur++;
        }
        tmp[cur] = sum;
    }

    res = (res * tmp[cur]) % mod;
    return res;
}

int main(int argc, char *argv[]) {

    // 8
    cout << countTexts("22233") << endl;
    // 82876089
    cout << countTexts("222222222222222222222222222222222222") << endl;
    // 8
    cout << countTexts("7777") << endl;

    return 0;
}
