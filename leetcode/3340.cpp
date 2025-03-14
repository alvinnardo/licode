#include "../template/head.h"
#include <bits/stdc++.h>

bool isBalanced(string num) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int even = 0, odd = 0;
    for (int i = 0; i < num.length(); i++) {
        if (i & 1) {
            odd += (num[i] - '0');
        } else {
            even += (num[i] - '0');
        }
    }

    return even == odd;
}

int main(int argc, char *argv[]) {
    // false
    cout << isBalanced("1234") << endl;
    // true
    cout << isBalanced("24123") << endl;

    return 0;
}
