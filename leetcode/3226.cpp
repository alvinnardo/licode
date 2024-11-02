#include "../template/head.h"
#include <bits/stdc++.h>

int minChanges(int n, int k) {
    // 题解：位运算
    // 时间 O(1)，空间 O(1)
    // 比我的思路更好，因为 k 的零更多，判断 n & k == k 即可
    return (n & k) == k ? __builtin_popcount(n ^ k) : -1;
}

int minChanges_my(int n, int k) {
    // 思路：位运算
    // 时间 O(1)，空间 O(1)
    // 获取不同的个数，再分别计算各自 1 的个数

    auto getOneNum = [](int num) { return __builtin_popcount(num); };

    int diff = getOneNum(n) - getOneNum(k);
    return diff == getOneNum(n ^ k) ? diff : -1;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minChanges(13, 4) << endl;
    // 0
    cout << minChanges(21, 21) << endl;
    // -1
    cout << minChanges(14, 13) << endl;

    return 0;
}
