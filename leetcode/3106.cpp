#include "../template/head.h"
#include <bits/stdc++.h>

string getSmallestString(string s, int k) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    vector<int> vec(26);
    for (int i = 0; i < 13; i++) {
        vec[i] = i;
    }
    for (int i = 25; i >= 13; i--) {
        vec[i] = 26 - i;
    }

    int i = 0;
    while (k && i < s.length()) {
        int pos = s[i] - 'a';
        if (vec[pos] <= k) {
            s[i] = 'a';
            k -= vec[pos];
        } else {
            s[i] -= k;
            k = 0;
        }
        i++;
    }

    return s;
}

int main(int argc, char *argv[]) {
    // "aaaz"
    cout << getSmallestString("zbbz", 3) << endl;
    // "aawcd"
    cout << getSmallestString("xaxcd", 4) << endl;
    // "lol"
    cout << getSmallestString("lol", 0) << endl;
    // "a"
    cout << getSmallestString("a", 26) << endl;

    return 0;
}
