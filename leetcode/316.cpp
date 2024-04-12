#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {

    // 没想到解法
    // 题解：单调栈
    // 如果之后碰到更小的，则要弹出栈中大的元素
    // 注意，出现一次的就不能被弹出了
    string res;
    int cur[26]{};
    int has[26]{};

    for (auto c : s) {
        cur[c - 'a']++;
    }

    for (auto c : s) {
        int t = c - 'a';
        if (res.empty()) {
            res += c;
            has[t]++;
        } else {
            if (has[t] == 0) {
                while (!res.empty() && c < res.back() &&
                       cur[res.back() - 'a'] != 0) {
                    auto p = res.back();
                    res.pop_back();
                    has[p - 'a']--;
                }
                res += c;
                has[t]++;
            }
        }
        cur[t]--;
    }

    return res;
}

int main(void) {
    cout << removeDuplicateLetters("bcabc") << endl;
    cout << removeDuplicateLetters("cbacdcbc") << endl;

    return 0;
}
