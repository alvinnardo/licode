#include "../template/head.h"
#include <bits/stdc++.h>

long long getDescentPeriods(vector<int> &&prices) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int sz = prices.size();
    long long res{1}, tmp{1};
    for (int i = 1; i < sz; ++i) {
        tmp = prices[i - 1] - prices[i] == 1 ? tmp + 1 : 1;
        res += tmp;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << getDescentPeriods({3, 2, 1, 4}) << endl;
    // 4
    cout << getDescentPeriods({8, 6, 7, 7}) << endl;
    // 1
    cout << getDescentPeriods({1}) << endl;

    return 0;
}
