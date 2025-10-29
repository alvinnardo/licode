#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfBeams(vector<string> &&bank) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int a{}, res{};
    for (auto &str : bank) {
        int t{};
        std::ranges::for_each(str.begin(), str.end(),
                              [&t](char c) { t += c == '1'; });

        if (t != 0) {
            res += t * a;
            a = t;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 8
    cout << numberOfBeams({"011001", "000000", "010100", "001000"}) << endl;
    // 0
    cout << numberOfBeams({"000", "111", "000"}) << endl;

    return 0;
}
