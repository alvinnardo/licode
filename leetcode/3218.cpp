#include "../template/head.h"
#include <bits/stdc++.h>

int minimumCost(int m, int n, vector<int> horizontalCut,
                vector<int> verticalCut) {
    // 思路：记忆化搜索
    // 时间 O(m2n2)，空间 O(m2n2)

    auto getPos = [](int ax, int ay, int bx, int by) {
        // 用位来保存，0-19 最多 5 位，4 个数最多 20 位
        return (ax << 15) + (ay << 10) + (bx << 5) + by;
    };

    unordered_map<int, int> umap;

    function<int(int, int, int, int)> dfs = [&](int ax, int ay, int bx,
                                                int by) -> int {
        if (bx - ax == 1 && by - ay == 1) {
            return 0;
        }
        int pos = getPos(ax, ay, bx, by);
        if (umap[pos] != 0) {
            return umap[pos];
        }

        int res = INT_MAX;
        // 横着切
        for (int i = ax + 1; i < bx; i++) {
            res = min(res, horizontalCut[i - 1] + dfs(ax, ay, i, by) +
                               dfs(i, ay, bx, by));
        }

        // 竖着切
        for (int i = ay + 1; i < by; i++) {
            res = min(res, verticalCut[i - 1] + dfs(ax, ay, bx, i) +
                               dfs(ax, i, bx, by));
        }

        umap[pos] = res;
        return res;
    };

    return dfs(0, 0, m, n);
}

int main(int argc, char *argv[]) {
    // 13
    cout << minimumCost(3, 2, {1, 3}, {5}) << endl;
    // 15
    cout << minimumCost(2, 2, {7}, {4}) << endl;
    // 116564
    cout << minimumCost(20, 20,
                        {165, 410, 44,  905, 634, 42,  194, 258, 460, 80,
                         572, 754, 215, 748, 591, 687, 123, 886, 501, 315},
                        {266, 537, 139, 218, 444, 101, 811, 345, 117, 548,
                         796, 281, 957, 191, 537, 942, 232, 731, 200, 44});

    return 0;
}
