#include "../template/head.h"
#include <bits/stdc++.h>

int temperatureTrend(vector<int> temperatureA, vector<int> temperatureB) {
    // 思路：遍历
    // 时间：O(n)，空间 O(1)
    auto getSign = [&](int t) { return t > 0 ? 1 : (t == 0 ? 0 : -1); };

    int sz = temperatureA.size();
    int cnt = 0, maxv = 0;
    for (int i = 1; i < sz; i++) {
        int diffa = temperatureA[i] - temperatureA[i - 1],
            diffb = temperatureB[i] - temperatureB[i - 1];

        int trenda = getSign(diffa), trendb = getSign(diffb);
        if (trenda == trendb) {
            cnt++;
        } else {
            cnt = 0;
        }

        maxv = max(maxv, cnt);
    }
    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << temperatureTrend({21, 18, 18, 18, 31}, {34, 32, 16, 16, 17})
         << endl;
    // 3
    cout << temperatureTrend({5, 10, 16, -6, 15, 11, 3},
                             {16, 22, 23, 23, 25, 3, -16})
         << endl;

    return 0;
}
