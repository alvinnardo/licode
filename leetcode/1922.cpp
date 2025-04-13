#include "../template/head.h"
#include <bits/stdc++.h>

int countGoodNumbers(long long n) {
    // 思路：快速幂
    // 时间 O(logn)，空间 O(1)

    // 偶数有 5 个，质数有 4 个，1 除去
    const int mod = 1e9 + 7;
    auto quickExp = [](long long a, long long n) -> long long {
        long long res = 1;

        while (n) {
            if (n & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            n >>= 1;
        }

        return res;
    };

    return (quickExp(5, ((n + 1) >> 1)) * quickExp(4, (n >> 1))) % mod;
}

int main(int argc, char *argv[]) {
    // 5
    cout << countGoodNumbers(1) << endl;
    // 400
    cout << countGoodNumbers(4) << endl;
    // 564908303
    cout << countGoodNumbers(50) << endl;
    cout << countGoodNumbers(100000090000000) << endl;

    return 0;
}
