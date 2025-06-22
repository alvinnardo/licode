#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> divideString(string s, int k, char fill) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    vector<string> res((s.length() + (k - 1)) / k);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        cnt = i / k;
        res[cnt] += s[i];
    }

    while (res.back().length() < k) {
        res.back() += fill;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"abc","def","ghi"}
    printVector(divideString("abcdefghi", 3, 'x'));
    // {"abc","def","ghi","jxx"}
    printVector(divideString("abcdefghij", 3, 'x'));

    return 0;
}
