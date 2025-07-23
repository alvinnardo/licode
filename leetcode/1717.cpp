#include "../template/head.h"
#include <bits/stdc++.h>

int maximumGain(string s, int x, int y) {
    // 思路：贪心 + 栈
    // 时间 O(n)，空间 O(n)
    // 先把大的都去掉，再处理小的
    int len = s.length();
    string st;
    int res = 0;
    bool left = x > y;
    for (int i = 0; i < len; i++) {
        if (st.empty()) {
            st += s[i];
            continue;
        }

        if (s[i] == 'b') {
            if (left && st.back() == 'a') {
                res += x;
                st.pop_back();
            } else {
                st += s[i];
            }
        } else if (s[i] == 'a') {
            if (!left && st.back() == 'b') {
                res += y;
                st.pop_back();
            } else {
                st += s[i];
            }
        } else {
            st += s[i];
        }
    }

    s.clear();
    for (int i = st.length() - 1; i >= 0; i--) {
        if (s.empty()) {
            s += st[i];
            continue;
        }

        if (st[i] == 'b') {
            if (s.back() == 'a') {
                res += y;
                s.pop_back();
            } else {
                s += st[i];
            }
        } else if (st[i] == 'a') {
            if (s.back() == 'b') {
                res += x;
                s.pop_back();
            } else {
                s += st[i];
            }
        } else {
            s += st[i];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 19
    cout << maximumGain("cdbcbbaaabab", 4, 5) << endl;
    // 20
    cout << maximumGain("aabbaaxybbaabb", 5, 4) << endl;

    return 0;
}
