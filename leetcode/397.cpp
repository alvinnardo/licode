#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(int n) {

    // 思路：记忆化搜索
    // 1. 如果是偶数直接除以 2
    // 2. 如果是奇数判断是否有捷径，没有捷径就 dfs

    // 时间 O(logn)，每一层最多计算 2 个值
    int base = 1, cnt = 30;
    unordered_set<int> uset;
    while (cnt--) {
        base <<= 1;
        uset.insert(base);
    }

    unordered_map<int, int> umap;
    function<int(int)> dfs = [&](int t) {
        if (t == INT_MAX) { // 单独算
            return 32;
        }

        if (t == 1) {
            return 0;
        }

        if (umap.find(t) != umap.end()) {
            return umap[t];
        }

        int res = 0;
        if (t & 1) {
            if (uset.find(t - 1) != uset.end()) {
                res = dfs(t - 1) + 1;
            } else if (uset.find(t + 1) != uset.end()) {
                res = dfs(t + 1) + 1;
            } else {
                res = min(dfs(t - 1), dfs(t + 1)) + 1;
            }
        } else {
            res = dfs(t >> 1) + 1;
        }

        umap[t] = res;
        return res;
    };

    return dfs(n);
}

int main(void) {

    // for (int i = 1; i <= 1000; i++) {
    //     cout << i << ": " << maxRotateFunction(i) << endl;
    // }
    // 0
    cout << maxRotateFunction(1) << endl;
    // 3
    cout << maxRotateFunction(8) << endl;
    // 4
    cout << maxRotateFunction(7) << endl;
    // 2
    cout << maxRotateFunction(4) << endl;
    // 6
    cout << maxRotateFunction(19) << endl;
    // 27
    cout << maxRotateFunction(857496) << endl;
    // 26
    cout << maxRotateFunction(1038002) << endl;
    // 32
    cout << maxRotateFunction(INT_MAX - 1) << endl;
    // 32
    cout << maxRotateFunction(INT_MAX) << endl;

    return 0;
}
