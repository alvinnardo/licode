#include "../template/head.h"
#include <bits/stdc++.h>

// 正则太慢
int canBeTypedWords1(string text, string brokenLetters) {
    // 思路：正则
    // 时间 O(mn)，空间 O(1)
    std::regex re("[a-z]+");
    auto bng = std::sregex_iterator(text.begin(), text.end(), re);
    auto end = std::sregex_iterator();

    int cnt{};
    for (auto i = bng; i != end; i++) {
        std::smatch m = *i;
        if (m.str().find_first_of(brokenLetters) == std::string::npos) {
            cnt++;
        }
    }

    return cnt;
}

int canBeTypedWords(string text, string brokenLetters) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    auto len{text.size()};
    string tmp;
    int cnt{};
    for (int i = 0; i <= len; i++) {
        if (i == len || text[i] == ' ') {
            if (tmp.find_first_of(brokenLetters) == std::string::npos) {
                cnt++;
            }
            tmp.clear();
        } else {
            tmp += text[i];
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << canBeTypedWords("hello world", "ad") << endl;
    // 1
    cout << canBeTypedWords("leet code", "lt") << endl;
    // 0
    cout << canBeTypedWords("leet code", "e") << endl;

    return 0;
}
