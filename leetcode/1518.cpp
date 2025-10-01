#include "../template/head.h"
#include <bits/stdc++.h>

int numWaterBottles(int numBottles, int numExchange) {
    // 思路：模拟
    // 时间 O(n/m)，空间 O(1)

    int res{}, empty{};
    while (numBottles > 0) {
        res += numBottles;
        empty += numBottles;
        numBottles = 0;

        int t = empty / numExchange;
        empty -= t * numExchange;
        numBottles += t;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 13
    cout << numWaterBottles(9, 3) << endl;
    // 19
    cout << numWaterBottles(15, 4) << endl;

    return 0;
}
