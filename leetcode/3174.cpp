#include "../template/head.h"
#include <bits/stdc++.h>

string clearDigits(string s) {
    // 思路：栈
    // 时间 O(n)，空间 O(n)

    auto isDigit = [](char c) -> bool { return c >= '0' && c <= '9'; };

    string st;
    for (char c : s) {
        if (isDigit(c)) {
            if (!st.empty() && !isDigit(st.back())) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        } else {
            st.push_back(c);
        }
    }

    return st;
}

int main(int argc, char *argv[]) {
    // "abc"
    cout << clearDigits("abc") << endl;
    // ""
    cout << clearDigits("cb34") << endl;

    return 0;
}
