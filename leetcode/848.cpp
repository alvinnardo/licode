#include "../template/head.h"
#include <bits/stdc++.h>

string shiftingLetters(string s, vector<int> shifts) {
    // 思路: 前缀和
    // 时间 O(n)，空间 O(1)

    // 每次都是从 0 加到最后，不需要用差分数组
    int sz = shifts.size();
    int cnt = 0;
    string res(sz, ' ');
    for (int i = sz - 1; i >= 0; i--) {
        cnt = (cnt + shifts[i]) % 26;
        res[i] = 'a' + (((int)(s[i] - 'a') + cnt) % 26);
    }

    return res;
}

string shiftingLetters1(string s, vector<int> shifts) {
    // 思路：差分数组
    // 时间 O(n)，空间 O(n)

    // shifts[i] 最大到 1e9，所以做差分数组可能会超 int
    // 这里用余数解决，比 long long 更省时间
    int sz = shifts.size();
    vector<int> vec(sz);
    for (int i = 0; i < sz; i++) {
        shifts[i] %= 26;

        vec[0] += shifts[i]; // 从 0 到 i
        if (i + 1 < sz) {
            vec[i + 1] -= shifts[i];
        }
    }

    string res;
    for (int i = 0; i < sz; i++) {
        if (i > 0) {
            vec[i] += vec[i - 1];
        }

        res += 'a' + (((int)(s[i] - 'a') + vec[i]) % 26);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "rpl"
    cout << shiftingLetters("abc", {3, 5, 9}) << endl;
    // "gfd"
    cout << shiftingLetters("aaa", {1, 2, 3}) << endl;

    return 0;
}
