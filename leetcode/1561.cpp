#include "../template/head.h"
#include <bits/stdc++.h>

int maxCoins(vector<int> piles) {
    // 思路：贪心
    // A 选最大的，B 选次大的，C 选最小的
    // 时间 O(nlogn)，空间 O(logn)
    // 题目中给出了范围 >= 3 且是 3 的倍数
    sort(piles.begin(), piles.end(), std::greater<int>());

    int sum = 0, cnt = piles.size() / 3;
    int pos = 1;
    for (int i = 0; i < cnt; i++) {
        sum += piles[pos];
        pos += 2;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 9
    cout << maxCoins({2, 4, 1, 2, 7, 8}) << endl;
    // 4
    cout << maxCoins({2, 4, 5}) << endl;
    // 18
    cout << maxCoins({9, 8, 7, 6, 5, 1, 2, 3, 4}) << endl;

    return 0;
}
