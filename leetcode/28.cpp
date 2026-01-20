#include "../template/head.h"
#include <bits/stdc++.h>

int strStr(string haystack, string needle) {
    // 思路：模拟
    // 时间 O(m + n)，空间 O(1)
    return haystack.find(needle);
}

int main(int argc, char *argv[]) {
    // 0
    cout << strStr("sadbutsad", "sad") << endl;
    // -1
    cout << strStr("leetcode", "leeto") << endl;

    return 0;
}
