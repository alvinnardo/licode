#include "../template/head.h"
#include <bits/stdc++.h>

// 解题时间 15 分钟
int countCompleteDayPairs(vector<int> hours) {
    // 思路：哈希
    // 时间 O(n + k)，空间 O(k)，k = 24
    vector<int> days(24);
    for (int hour : hours) {
        days[hour % 24]++;
    }

    int res = 0;
    for (int i = 1; i < 12; i++) {
        res += days[i] * days[24 - i]; // 组合
    }

    // 0 和 12 单独处理，C{n, 2} 个
    if (days[0] > 1) {
        res += (days[0] * (days[0] - 1)) >> 1;
    }
    if (days[12] > 1) {
        res += (days[12] * (days[12] - 1)) >> 1;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countCompleteDayPairs({12, 12, 30, 24, 24}) << endl;
    // 3
    cout << countCompleteDayPairs({72, 48, 24, 3}) << endl;

    return 0;
}
