#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n <= 2)
        return 0;

    // 素筛
    vector<int> vec(n);
    for (int i = 2; i <= sqrt(n); i++) {
        if (vec[i] == 1) {
            continue;
        }
        int j = 2;
        while (true) {
            int pos = i * j;
            if (pos > n - 1)
                break;
            vec[pos] = 1;
            j++;
        }
    }
    // printVector(vec);
    int cnt = 2; // 0 和 1
    for (int i = 2; i < n; i++) {
        if (vec[i] == 1) {
            cnt++;
        }
    }
    return n - cnt;
}

int main(void) {
    cout << countPrimes(0) << endl;
    cout << countPrimes(1) << endl;
    cout << countPrimes(2) << endl;
    cout << countPrimes(3) << endl;
    cout << countPrimes(5) << endl;
    cout << countPrimes(10) << endl;
    cout << countPrimes(100) << endl;
    cout << countPrimes(5000000) << endl;
    return 0;
}
