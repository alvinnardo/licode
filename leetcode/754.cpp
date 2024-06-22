#include "../template/head.h"
#include <bits/stdc++.h>

int reachNumber(int target) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)
    int left = 0, right = 0;
    int step = 0;
    while (true) {
        step++;
        left -= step;
        right += step;

        if (target >= left && target <= right && (target - left) % 2 == 0) {
            break;
        }
    }

    return step;
}

int main(int argc, char *argv[]) {
    // 3
    cout << reachNumber(2) << endl;
    // 2
    cout << reachNumber(3) << endl;

    return 0;
}
