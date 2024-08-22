#include "../template/head.h"
#include <bits/stdc++.h>

long long minEnd(int n, int x) {
    // 思路：位运算 + 贪心，把 x 所在的位移走
    // 时间 O(logn)，空间 O(1)
    long long res = x, mask = 1, t = n - 1;

    int cnt = 0;
    while (t) {
        if (!(res & mask)) {
            res ^= ((t & 1) << cnt);
            t >>= 1;
        }
        mask <<= 1;
        cnt++;
    }
    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << minEnd(3, 4) << endl;
    // 15
    cout << minEnd(2, 7) << endl;
    // 3004661281
    cout << minEnd(23472674, 423424) << endl;

    return 0;
}
