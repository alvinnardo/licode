#include "../template/head.h"
#include <bits/stdc++.h>

int numTilings(int n) {
    // 思路：DP + 找规律
    // 时间 O(n)，空间 O(1)

    // 从 4 开始就多了两个特殊的，两个角是 三个块 的，中间插入 两个块 的
    int mod = 1e9 + 7;
    long long a = 0, b = 0, c = 0, d = 0;
    long long cnt = 0; // 统计之前的，用于后面计算特殊的
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            a = d = 1;
        } else if (i == 2) {
            b = d = 2;
        } else if (i == 3) {
            c = d = 5;
        } else if (i == 4) {
            d = ((a << 1) % mod + b + c + 2) % mod;
        } else {
            cnt += a;
            a = b;
            b = c;
            c = d;
            // dp[i] = dp[i-1] + dp[i-2] + dp[i-3] * 2 + 之前特殊的 + 自己特殊的
            d = ((a << 1) % mod + b + c + 2 + (cnt << 1)) % mod;
        }
    }

    return d;
}

int main(int argc, char *argv[]) {
    // 5
    cout << numTilings(3) << endl;
    // 1
    cout << numTilings(1) << endl;
    // 3418626
    cout << numTilings(20) << endl;
    // 2
    cout << numTilings(2) << endl;
    // 11
    cout << numTilings(4) << endl;
    // 24
    cout << numTilings(5) << endl;
    // 53
    cout << numTilings(6) << endl;
    // 1255
    cout << numTilings(10) << endl;
    // 979232805
    cout << numTilings(1000) << endl;

    return 0;
}
