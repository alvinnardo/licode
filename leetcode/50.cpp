#include <bits/stdc++.h>

using namespace std;

// x != 0 或 n > 0
// 快速幂
double myPow(double x, int n) {
    if (x == 0) {
        return 0;
    }

    if (n == 0 || x == 1) {
        return 1;
    }

    bool x_neg = false;
    if (x < 0) {
        x_neg = true;
        x = -x;
    }

    bool n_neg = false;
    long long n_after = n;
    if (n < 0) {
        n_neg = true;
        n_after = -n_after;
    }

    if (!(n & 1)) {
        x_neg = false;
    }

    double sum = 1, tmp = 1;

    while (n_after) {
        if (tmp == 1) {
            tmp = x;
        } else {
            tmp *= tmp;
        }

        if (n_after & 1) {
            sum *= tmp;
        }
        n_after >>= 1;
    }

    if (n_neg) {
        sum = 1.0 / sum;
    }
    if (x_neg) {
        sum = -sum;
    }

    return sum;
}

int main(void) {
    cout << myPow(2.0, 10) << endl;
    cout << myPow(2.1, 3) << endl;
    cout << myPow(2, -2) << endl;
    cout << myPow(-1.000001, 100) << endl;
    cout << myPow(-1.000001, -100) << endl;
    cout << myPow(-1.000000001, -2147483647) << endl;
    cout << myPow(-1.000000001, -2147483648) << endl;
    cout << myPow(-1.000000001, 2147483647) << endl;
    return 0;
}
