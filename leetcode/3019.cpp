#include "../template/head.h"
#include <bits/stdc++.h>

int countKeyChanges(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    unordered_set<int> uset{0, 'A' - 'a', 'a' - 'A'};

    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        if (!uset.count(s[i] - s[i - 1])) {
            res++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countKeyChanges("aAbBcC") << endl;
    // 0
    cout << countKeyChanges("AaAaAaaA") << endl;

    return 0;
}
