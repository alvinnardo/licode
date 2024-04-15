#include "head.h"
#include <bits/stdc++.h>
using namespace std;

// 标记 n 以内的质数
vector<int> getPrime(int n) {
    int sz = n + 1;
    vector<int> is_prime(sz, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i < sqrt(sz) + 1; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < sz; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < sz; i++) {
        if (is_prime[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

// int main(void) {
//     printVector(getPrime(1000));
//     return 0;
// }
