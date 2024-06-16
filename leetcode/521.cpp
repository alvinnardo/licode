#include "../template/head.h"
#include <bits/stdc++.h>

int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.length(), b.length());
}

int main(int argc, char *argv[]) {
    // 3
    cout << findLUSlength("aba", "cdc") << endl;
    // 3
    cout << findLUSlength("aaa", "bbb") << endl;
    // -1
    cout << findLUSlength("aaa", "aaa") << endl;
    return 0;
}
