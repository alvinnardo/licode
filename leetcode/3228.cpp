#include "../template/head.h"
#include <bits/stdc++.h>

int maxOperations(string s) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    // 贪心：先移动前面的 1，再移动后面的 1
    // 两个 1 之间要有 0，才加 1
    while (!s.empty() && s.back() == '1') { // 去除结尾无用的 1
        s.pop_back();
    }

    // 从后往前找 1
    int res{}, add{};
    bool zero = false;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zero = true;
        } else {
            if (zero) {
                res += (++add);
                zero = false;
            } else {
                res += add;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxOperations("1001101") << endl;
    // 0
    cout << maxOperations("00111") << endl;

    return 0;
}
