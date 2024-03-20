#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int fastMul(int64_t a, int e) { // a^(2^e)

    int64_t res = 1;
    int64_t tmp = a;
    for (int i = 0; i < e; i++) {
        res = ((res % mod) * (tmp % mod)) % mod;
        tmp = ((tmp % mod) * (tmp % mod)) % mod;
    }

    return res;
}

int minNonZeroProduct(int p) {

    int64_t t = ((int64_t)1 << p); // 2^n
    int64_t res = fastMul(t - 2, p - 1);

    res = ((res % mod) * ((t - 1) % mod)) % mod;
    return res;
}

int main(void) {
    for (int i = 1; i <= 60; i++)
        cout << i << ": " << minNonZeroProduct(i) << std::endl;
    return 0;
}
