#include "../template/head.h"
#include <bits/stdc++.h>

bool doesValidArrayExist(vector<int> &&derived) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 选 0 和 选 1 原理都相同
    // 选 0 之后绕一圈能返回来就成立
    // a^b = c <=> a = b^c

    int a = 0;
    std::for_each(derived.begin(), derived.end(), [&](int t) { a ^= t; });
    return a == 0;
}

int main(int argc, char *argv[]) {
    // 1
    cout << doesValidArrayExist({1, 1, 0}) << endl;
    // 1
    cout << doesValidArrayExist({1, 1}) << endl;
    // 0
    cout << doesValidArrayExist({1, 0}) << endl;

    return 0;
}
