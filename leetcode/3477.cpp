#include "../template/head.h"
#include <bits/stdc++.h>

int numOfUnplacedFruits(vector<int> &&fruits, vector<int> &&baskets) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int cnt = 0;
    for (int i = 0; i < fruits.size(); i++) {
        for (int j = 0; j < baskets.size(); j++) {
            if (baskets[j] != -1 && baskets[j] >= fruits[i]) {
                cnt++;
                baskets[j] = -1;
                break;
            }
        }
    }

    return fruits.size() - cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << numOfUnplacedFruits({4, 2, 5}, {3, 5, 4}) << endl;
    // 0
    cout << numOfUnplacedFruits({3, 6, 1}, {6, 4, 7}) << endl;

    return 0;
}
