#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> missingRolls(vector<int> rolls, int mean, int n) {
    // 思路：模拟，先看能否成立，再求平均值
    // 时间 O(n), 空间 O(1)
    // 先判断
    int sum = accumulate(rolls.begin(), rolls.end(), 0);
    int hope = mean * (rolls.size() + n) - sum;
    if (hope < n || hope > n * 6) {
        return {};
    }

    int num = hope / n, duo = hope % n;
    vector<int> res(n, num);
    for (int i = 0; i < duo; i++) {
        res[i]++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {6, 6}
    printVector(missingRolls({3, 2, 4, 3}, 4, 2));
    // {2, 3, 2, 2}
    printVector(missingRolls({1, 5, 6}, 3, 4));
    // {}
    printVector(missingRolls({1, 2, 3, 4}, 6, 4));
    // {5}
    printVector(missingRolls({1}, 3, 1));

    return 0;
}
