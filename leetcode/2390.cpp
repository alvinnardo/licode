#include "../template/head.h"
#include <bits/stdc++.h>

string removeStars(string s) {
    // 思路：栈
    // 时间 O(n)，空间 O(n)
    string res = "";
    for (char c : s) {
        if (c == '*') {
            if (!res.empty()) {
                res.pop_back();
            }
        } else {
            res.push_back(c);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "lecoe"
    cout << removeStars("leet**cod*e") << endl;
    // ""
    cout << removeStars("erase*****") << endl;

    return 0;
}
