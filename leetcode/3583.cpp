#include "../template/head.h"
#include <bits/stdc++.h>

int specialTriplets(vector<int> &&nums) {
    // 思路：哈希表 + 模拟
    // 时间 O(n)，空间 O(n)

    unordered_map<int, int> umap1, umap2;
    for (int i = 0; i < nums.size(); i++) {
        ++umap2[nums[i]];
    }

    long long res{};
    int mod = 1e9 + 7, t{};
    for (int i = 0; i < nums.size(); i++) {
        --umap2[nums[i]];

        t = nums[i] << 1;
        auto it1 = umap1.find(t);
        auto it2 = umap2.find(t);
        if (it1 != umap1.end() && it2 != umap2.end()) {
            res = (res + (long long)(it1->second) * (it2->second)) % mod;
        }

        ++umap1[nums[i]];
    }
    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << specialTriplets({6, 3, 6}) << endl;
    // 1
    cout << specialTriplets({0, 1, 0, 0}) << endl;
    // 2
    cout << specialTriplets({8, 4, 2, 8, 4}) << endl;

    return 0;
}
