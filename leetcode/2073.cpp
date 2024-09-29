#include "../template/head.h"
#include <bits/stdc++.h>

int timeRequiredToBuy(vector<int> tickets, int k) {
    // 思路：模拟
    // 前面小于等于的应该先拿完，后面少一轮小于的应该先拿完
    // 时间 O(n)，空间 O(1)
    int sum = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k) {
            sum += tickets[i] <= tickets[k] ? tickets[i] : tickets[k];
        } else {
            sum += tickets[i] <= tickets[k] - 1 ? tickets[i] : tickets[k] - 1;
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {

    // 6
    cout << timeRequiredToBuy({2, 3, 2}, 2) << endl;
    // 8
    cout << timeRequiredToBuy({5, 1, 1, 1}, 0) << endl;

    return 0;
}
