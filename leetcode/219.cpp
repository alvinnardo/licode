#include "../template/head.h"
#include <bits/stdc++.h>

bool containsNearbyDuplicate(vector<int> nums, int k) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(m)，m 是数组中不同数字个数

    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        if (umap.count(nums[i])) {
            if (i - umap[nums[i]] <= k) {
                return true;
            }
        }
        umap[nums[i]] = i;
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << containsNearbyDuplicate({1, 2, 3, 1}, 3) << endl;
    // 1
    cout << containsNearbyDuplicate({1, 0, 1, 1}, 1) << endl;
    // 0
    cout << containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2) << endl;

    return 0;
}
