#include "../template/head.h"
#include <bits/stdc++.h>
bool isStrictlyPalindromic(int n) {
    // 思路：模拟
    // 没有一个能成立，有部分能过 2，只有 6643 能过 2 和 3
    // 题解给出： n 的式子为 n = bq + r，b 是进制，当 b = n - 2 时
    // n > 4，即 b > 2 时，q = 1，r = 2，12 不是回文
    // n = 4，即 b = 2 时，100 不是回文
    // 时间 O(1)，空间 O(1)

    return 0;
}

bool isStrictlyPalindromic1(int n) {
    // 思路：模拟
    // 时间 O(nlogn)，空间 O(1)

    auto isRe = [](int i, int j) {
        vector<int> res;
        while (i) {
            res.push_back(i % j);
            i /= j;
        }

        for (int i = 0; i < res.size() / 2; i++) {
            if (res[i] != res[res.size() - i - 1]) {
                return false;
            }
        }

        return true;
    };

    bool is = true;
    for (int i = 2; i <= n - 2; i++) {
        if (!isRe(n, i)) {
            return false;
        } else {
            cout << n << " " << i << endl;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 0
    cout << isStrictlyPalindromic(9) << endl;
    // 0
    cout << isStrictlyPalindromic(4) << endl;

    return 0;
}
