#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> ambiguousCoordinates(string s) {
    // 思路：模拟
    // 先按逗号分隔，再枚举点的位置
    // 时间 O(n)，空间 O(n)

    auto check_left = [](const auto &str, int bng, int end) {
        int zero_cnt = count_if(str.begin() + bng, str.begin() + end,
                                [](const char &c) { return c == '0'; });
        if (str[bng] == '0' && end - bng + 1 != 1) {
            return false;
        }
        return true;
    };

    auto check_right = [](const auto &str, int bng, int end) {
        if (bng > end) { // 小数点后为空
            return true;
        }

        if (str[end] == '0') {
            return false;
        }
        return true;
    };

    auto handle = [&](const auto &str) {
        vector<string> res;

        for (int i = 0; i < str.length(); i++) {
            // all pos
            if (check_left(str, 0, i) &&
                check_right(str, i + 1, str.length() - 1)) {
                if (i + 1 == str.length()) {
                    res.emplace_back(str);
                } else {
                    res.emplace_back(str.substr(0, i + 1) + "." +
                                     str.substr(i + 1));
                }
            }
        }

        return res;
    };

    vector<string> res;
    for (int i = 1; i < s.length() - 2; i++) {
        auto left = handle(s.substr(1, i));
        auto right = handle(s.substr(1 + i, s.length() - i - 2));
        if (left.empty() || right.empty()) {
            continue;
        }
        for (auto &l : left) {
            for (auto &r : right) {
                res.emplace_back("(" + l + ", " + r + ")");
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"}
    printVector(ambiguousCoordinates("(123)"));
    // {"(0.001, 1)", "(0, 0.011)"}
    printVector(ambiguousCoordinates("(00011)"));
    // {"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12,
    // 3)"}
    printVector(ambiguousCoordinates("(0123)"));
    // {(10, 0)}
    printVector(ambiguousCoordinates("(100)"));

    return 0;
}
