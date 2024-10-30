#include "../template/head.h"
#include <bits/stdc++.h>

string getSmallestString(string s) {
    // 思路：模拟
    // 字典序最小，肯定修改越靠前的越好
    // 时间 O(n)，空间 O(1)
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] > s[i + 1] &&
            (((s[i] - '0') & 1) ^ ((s[i + 1] - '0') & 1)) == 0) {
            swap(s[i], s[i + 1]);
            break;
        }
    }

    return s;
}

int main(int argc, char *argv[]) {
    // "43520"
    cout << getSmallestString("45320") << endl;
    // "001"
    cout << getSmallestString("001") << endl;
    // "10"
    cout << getSmallestString("10") << endl;

    return 0;
}
