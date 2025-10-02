#include "../template/head.h"
#include <bits/stdc++.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
    // 思路：模拟
    // 时间 O(m/n)，空间 O(1)

    int drunk{}, empty{};
    while (numBottles > 0) {
        drunk += numBottles;
        empty += numBottles;
        numBottles = 0;

        if (empty >= numExchange) {
            empty -= numExchange;
            numExchange++;
            numBottles++;
        }
    }

    return drunk;
}

int main(int argc, char *argv[]) {
    // 15
    cout << maxBottlesDrunk(13, 6) << endl;
    // 13
    cout << maxBottlesDrunk(10, 3) << endl;

    return 0;
}
