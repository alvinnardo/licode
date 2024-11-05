#include "../template/head.h"
#include <bits/stdc++.h>

string losingPlayer(int x, int y) {
    // 思路：模拟
    // 达到 115，肯定需要一个 75 和 4 个 10
    // 时间 O(1)，空间 O(1)

    return min(x, y / 4) & 1 ? "Alice" : "Bob";
}

int main(int argc, char *argv[]) {
    // Alice
    cout << losingPlayer(2, 7) << endl;
    // Bob
    cout << losingPlayer(4, 11) << endl;

    return 0;
}
