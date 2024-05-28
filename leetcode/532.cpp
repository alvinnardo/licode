#include "../template/head.h"
#include <bits/stdc++.h>

int findPairs(vector<int> nums, int k) {
    // 思路：哈希表
    // 如果 k 是 0，可以出现两次
    // 其它先判断是否出现过，如果没出现过，判断两端的值
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    int res = 0, sz = nums.size();

    for (int i = 0; i < sz; i++) {
        if (k == 0) {
            if (!umap.count(nums[i])) {
                umap[nums[i]]++;
            } else if (umap[nums[i]] == 1) {
                umap[nums[i]]++;
                res++;
            }
        } else {
            if (!umap.count(nums[i])) {
                umap[nums[i]]++;
                if (umap.count(nums[i] - k)) {
                    res++;
                }
                if (umap.count(nums[i] + k)) {
                    res++;
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 2
    cout << findPairs({3, 1, 4, 1, 5}, 2) << endl;
    // 4
    cout << findPairs({1, 2, 3, 4, 5}, 1) << endl;
    // 4
    cout << findPairs({3, 2, 1, 5, 4}, 1) << endl;
    // 1
    cout << findPairs({1, 3, 1, 5, 4}, 0) << endl;
    // 2
    cout << findPairs({5, -1, 1, 3, 1, -1, 1, 4}, 0) << endl;

    return 0;
}
