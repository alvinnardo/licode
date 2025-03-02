#include "../template/head.h"
#include <bits/stdc++.h>

double new21Game(int n, int k, int maxPts) {
    // 思路：暴力模拟
    // 超时

    double res = 0, level = 1.0 / maxPts;
    function<void(int, double)> dfs = [&](int tot, double p) {
        if (tot >= k) {
            if (tot <= n) {
                res += p;
            }
            return;
        }

        for (int i = 1; i <= maxPts; i++) {
            dfs(tot + i, p * level);
        }
    };

    dfs(0, 1.0);

    return res;
}

int main(int argc, char *argv[]) {
    // 1.00000
    cout << new21Game(10, 1, 10) << endl;
    // 0.60000
    cout << new21Game(6, 1, 10) << endl;
    // 0.73278
    cout << new21Game(21, 17, 10) << endl;
    cout << new21Game(1, 1000, 1000) << endl;

    return 0;
}
