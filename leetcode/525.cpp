#include "../template/head.h"
#include <bits/stdc++.h>

int findMaxLength(vector<int> nums) {
    // 思路：前缀和 + 哈希表
    // 存放每个位置 0 的个数和 1 的个数的差，哈希表中存放第一次出现的位置
    // 如果有相同，那么中间肯定有 0 1 交叉的变化
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    umap[0] = -1;
    int cnt0 = 0, cnt1 = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            cnt0++;
        } else {
            cnt1++;
        }

        int diff = cnt0 - cnt1;
        if (umap.count(diff)) {
            res = max(res, i - umap[diff]);
        } else {
            umap[diff] = i;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findMaxLength({0, 1}) << endl;
    // 2
    cout << findMaxLength({0, 1, 0}) << endl;
    // 6
    cout << findMaxLength({0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1})
         << endl;
    // 0
    cout << findMaxLength({0, 0, 0, 0, 0, 0}) << endl;
    // 0
    cout << findMaxLength({1, 1, 1, 1, 1, 1, 1, 1}) << endl;
    // 14
    cout << findMaxLength({0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1}) << endl;

    return 0;
}
