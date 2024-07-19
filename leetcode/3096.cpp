#include "../template/head.h"
#include <bits/stdc++.h>

int minimumLevels(vector<int> possible) {
    // 思路：前缀和
    // 时间：O(n)，空间 O(1)
    int sz = possible.size();

    if (possible[0] == 0) {
        possible[0] = -1;
    }

    for (int i = 1; i < sz; i++) {
        if (possible[i] == 0) {
            possible[i] = possible[i - 1] - 1;
        } else {
            possible[i] = possible[i - 1] + 1;
        }
    }
    // printVector(possible);

    int res = -1;
    // 每个人都至少完成一个，所以给玩家 2 留出最后一种可能
    for (int i = 0; i < sz - 1; i++) {
        if (possible[i] > possible.back() - possible[i]) {
            res = i + 1;
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 1
    cout << minimumLevels({1, 0, 1, 0}) << endl;
    // 3
    cout << minimumLevels({1, 1, 1, 1, 1}) << endl;
    // -1
    cout << minimumLevels({0, 0}) << endl;
    // -1
    cout << minimumLevels({1, 1}) << endl;

    return 0;
}
