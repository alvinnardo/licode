#include "../template/head.h"
#include <bits/stdc++.h>

int countOdds(int low, int high) {
    // 思路：数学
    // 时间 O(1)，空间 O(1)
    int cnt = high - low + 1;
    return ((cnt & 1) ? (low & 1) : 0) + (cnt >> 1);
}

int main(int argc, char *argv[]) {
    // 3
    cout << countOdds(3, 7) << endl;
    // 1
    cout << countOdds(8, 10) << endl;

    return 0;
}
