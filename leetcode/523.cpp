#include "../template/head.h"
#include <bits/stdc++.h>

bool checkSubarraySum(vector<int> nums, int k) {
    /* clang-format off */
    // 思路：前缀和 + 哈希表
    // 这道题我想了三天，终于想出解法了
    // 首先，这道题是区间和，肯定用前缀和来做，那么后面怎么做呢？
    // 然后，我想如果把所有 k 的倍数都求出来，然后遍历的时候尝试用二分，时间还是高
    // 最后，灵光一现，整倍数用取余操作，那么根据 (b - a) % k = b % k - a % k = 0
    // 再用前缀和求区间和的方法，就可以求了，前面的哈希表存储，如果有相同的，就成立
    // 时间 O(n)，空间 O(n)
    /* clang-format on */

    // 真巧妙的一道题
    unordered_map<int, int> umap; // 值 和 该值第一次出现的位置
    umap[0] = 0;                  // 0 个元素的前缀和

    // 这里前缀和数组要比 原数组 多 1
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0) {
            nums[i] += nums[i - 1];
        }

        // 根据题目所示，0 也是 k 的倍数，那么如果出现连续两个小于 k 的也成立
        /* if (nums[i] < k) { // 小于的不用判断
            continue;
        } */
        int t = nums[i] % k;
        if (umap.count(t)) { // 这里保留第一次出现的位置
            if (i + 1 - umap[t] >= 2) {
                return true;
            }
        } else {
            umap[t] = i + 1;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkSubarraySum({23, 2, 4, 6, 7}, 6) << endl;
    // 1
    cout << checkSubarraySum({23, 2, 6, 4, 7}, 6) << endl;
    // 0
    cout << checkSubarraySum({23, 2, 6, 4, 7}, 13) << endl;

    // 0
    cout << checkSubarraySum({0, 1, 3, 5}, 5) << endl;
    // 1
    cout << checkSubarraySum({0, 5}, 5) << endl;
    // 0
    cout << checkSubarraySum({5}, 5) << endl;
    // 1
    cout << checkSubarraySum({1, 1}, 1) << endl;
    return 0;
}
