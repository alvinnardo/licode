#include "../template/head.h"
#include <bits/stdc++.h>

int matchPlayersAndTrainers(vector<int> &&players, vector<int> &&trainers) {
    // 思路：贪心 + 排序
    // 时间 O(mlogn + nlogn)，空间 O(logm + logn)
    sort(players.begin(), players.end(), std::greater<int>());
    sort(trainers.begin(), trainers.end(), std::greater<int>());
    int i = 0, j = 0, cnt = 0;
    while (i < players.size() && j < trainers.size()) {
        if (players[i] <= trainers[j]) {
            ++i;
            ++j;
            ++cnt;
        } else {
            ++i;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << matchPlayersAndTrainers({4, 7, 9}, {8, 2, 5, 8}) << endl;
    // 1
    cout << matchPlayersAndTrainers({1, 1, 1}, {10}) << endl;

    return 0;
}
