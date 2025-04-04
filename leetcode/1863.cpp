#include "../template/head.h"
#include <bits/stdc++.h>

int subsetXORSum(vector<int> nums) {
    // 思路：DFS
    // 时间 O(2^n)，空间 O(n)
    // 选或不选

    int res = 0;
    function<void(int, int)> dfs = [&](int pos, int tot) {
        if (pos == nums.size()) {
            res += tot;
            return;
        }

        dfs(pos + 1, tot);
        dfs(pos + 1, tot ^ nums[pos]);
    };

    dfs(0, 0);
    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << subsetXORSum({1, 3}) << endl;
    // 28
    cout << subsetXORSum({5, 1, 6}) << endl;
    // 480
    cout << subsetXORSum({3, 4, 5, 6, 7, 8}) << endl;

    return 0;
}
