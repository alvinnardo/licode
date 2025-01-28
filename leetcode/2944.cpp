#include "../template/head.h"
#include <bits/stdc++.h>

int minimumCoins(vector<int> prices) {
    // 思路：模拟
    // 这道题的下标范围感觉没说清楚，不算好题
    // 时间 O(n2)，空间 O(n)
    int sz = prices.size();
    vector<int> res(sz, INT_MAX);

    for (int i = 0; i < prices.size(); i++) {
        int t = i == 0 ? 0 : res[i - 1];
        t += prices[i];
        // 买完之后，后面几个免费
        for (int j = i; j <= i + i + 1 && j < sz; j++) {
            res[j] = min(res[j], t);
        }
    }

    return res.back();
}

int main(int argc, char *argv[]) {
    // 4
    cout << minimumCoins({3, 1, 2}) << endl;
    // 2
    cout << minimumCoins({1, 10, 1, 1}) << endl;
    // 39
    cout << minimumCoins({26, 18, 6, 12, 49, 7, 45, 45}) << endl;

    return 0;
}
