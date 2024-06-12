#include "../template/head.h"
#include <bits/stdc++.h>

int accountBalanceAfterPurchase(int purchaseAmount) {
    // 思路：四舍五入
    // 时间 O(1)，空间 O(1)
    return 100 - (purchaseAmount / 10 * 10 + purchaseAmount % 10 / 5 * 10);
}

int main(int argc, char *argv[]) {
    // 100
    cout << accountBalanceAfterPurchase(0) << endl;
    // 90
    cout << accountBalanceAfterPurchase(13) << endl;
    // 80
    cout << accountBalanceAfterPurchase(15) << endl;
    // 0
    cout << accountBalanceAfterPurchase(95) << endl;
    // 0
    cout << accountBalanceAfterPurchase(100) << endl;
    return 0;
}
