#include "../template/head.h"
#include <bits/stdc++.h>

int scoreOfParentheses(string s) {
    // 思路: 栈 + 模拟
    // 时间 O(n)，空间 O(n)

    // 数字
    list<char> s1;
    list<pair<int, int>> s2; // 记录层数和分数

    for (const char &c : s) {
        if (c == '(') {
            s1.emplace_back(c);
        } else {
            s1.pop_back();

            int level = s1.size();
            if (s2.empty()) {
                s2.emplace_back(level, 1);
            } else {
                auto &t = s2.back();
                if (level > t.first) { // 层级更高
                    s2.emplace_back(level, 1);
                } else if (level == t.first) { // 在同一层，如 ()()
                    t.second++;
                } else { // 减层，如果 ()(())
                    t.first--;
                    t.second <<= 1;
                    if (s2.size() > 1 &&
                        (std::next(s2.rbegin()))->first == t.first) {
                        int p = t.second;
                        s2.pop_back();
                        s2.back().second += p;
                    }
                }
            }
        }
    }

    return s2.back().second;
}

int main(int argc, char *argv[]) {
    // 1
    cout << scoreOfParentheses("()") << endl;
    // 2
    cout << scoreOfParentheses("(())") << endl;
    // 2
    cout << scoreOfParentheses("()()") << endl;
    // 6
    cout << scoreOfParentheses("(()(()))") << endl;

    return 0;
}
