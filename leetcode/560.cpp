#include "../template/head.h"
#include <bits/stdc++.h>

int subarraySum(vector<int> nums, int k) {
    // 思路：前缀和 + 哈希表
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    umap[0] = 1;

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) {
            nums[i] += nums[i - 1];
        }

        int diff = nums[i] - k;
        if (umap.count(diff)) {
            cnt += umap[diff];
        }
        umap[nums[i]]++;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << subarraySum({1, 1, 1}, 2) << endl;
    // 2
    cout << subarraySum({1, 2, 3}, 3) << endl;
    //
    cout << subarraySum({1, -1, 1, -1, 1, -1, 1, -1}, 0) << endl;

    return 0;
}
