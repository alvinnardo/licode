#include "../template/head.h"
#include <bits/stdc++.h>

long long flowerGame(int n, int m) {
    // 思路：数学
    // 时间 O(1)，空间 O(1)

    // 相加是奇数
    // n 奇 m 偶 或 n 偶 m 奇
    using ll = long long;
    ll na = (n >> 1), nb = (n >> 1) + (n & 1);
    ll ma = (m >> 1), mb = (m >> 1) + (m & 1);

    return na * mb + nb * ma;
}

int main(int argc, char *argv[]) {
    // 3
    cout << flowerGame(3, 2) << endl;
    // 0
    cout << flowerGame(1, 1) << endl;

    return 0;
}
