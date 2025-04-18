#include "../template/head.h"
#include <bits/stdc++.h>

long long countBadPairs(vector<int> nums) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)

    // j - i != nums[j] - nums[i]
    // 转化为 j - nums[j] != i - nums[i]
    // 求 j - nums[j] = i - nums[i]
    // 再用总和减去好对数

    int sz = nums.size();
    if (sz == 1) {
        return 0;
    }

    unordered_map<int, int> umap;
    long long res = 0;
    for (int i = 0; i < sz; i++) {
        int t = nums[i] - i;
        auto it = umap.find(t);
        if (it != umap.end()) {
            res += it->second;
        }

        umap[nums[i] - i]++;
    }

    // 总对数 - 好对数
    // sz 会超 int
    return (((long long)sz * (sz - 1)) >> 1) - res;
}

int main(int argc, char *argv[]) {

    // 5
    cout << countBadPairs({4, 1, 3, 3}) << endl;
    // 0
    cout << countBadPairs({1, 2, 3, 4, 5}) << endl;

    return 0;
}
