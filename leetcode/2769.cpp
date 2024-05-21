#include "../template/head.h"
#include <bits/stdc++.h>

int theMaximumAchievableX(int num, int t) {
    // 思路：同时增加和减少
    return num + (t << 1);
}

int main(int argc, char *argv[]) {
    // 6
    cout << theMaximumAchievableX(4, 1) << endl;
    // 7
    cout << theMaximumAchievableX(3, 2) << endl;

    return 0;
}
