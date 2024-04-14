#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int superPow(int a, vector<int> b) {
    // 思路：进位是 a^10
    if (a == 1) {
        return 1;
    }

    int sz = b.size();
    int sum = 1, mod = 1337;
    int carry = a % mod;

    auto quickMul = [&](int a, int b) {
        int sum = 1;
        while (b) {
            if (b & 1) {
                sum = (sum * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }

        return sum;
    };

    for (int i = sz - 1; i >= 0; i--) {
        sum = (sum * quickMul(carry, b[i]) % mod) % mod;
        carry = quickMul(carry, 10) % mod;
    }

    return sum % mod;
}

int main(void) {
    cout << superPow(1, {4, 3, 3, 8, 5, 2}) << endl;
    cout << superPow(2, {3}) << endl;
    cout << superPow(2, {1, 0}) << endl;
    cout << superPow(2, {4, 3, 3, 8, 5, 2}) << endl;
    cout << superPow(2147483647, {2, 0, 0}) << endl;
    cout << superPow(2147483647, {2, 0, 0}) << endl;

    return 0;
}
