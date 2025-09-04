#include "../template/head.h"
#include <bits/stdc++.h>

int findClosest(int x, int y, int z) {
    // 思路：模拟
    // 时间 O(1)，空间 O(1)

    // 比较绝对值
    auto cmp = std::abs(x - z) <=> std::abs(y - z);
    return cmp == 0 ? 0 : (cmp < 0 ? 1 : 2);
}

int main(int argc, char *argv[]) {
    // 1
    cout << findClosest(2, 7, 4) << endl;
    // 2
    cout << findClosest(2, 5, 6) << endl;
    // 0
    cout << findClosest(1, 5, 3) << endl;

    return 0;
}
