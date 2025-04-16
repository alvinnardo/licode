#include "../template/head.h"
#include <bits/stdc++.h>

long long countGood(vector<int> nums, int k) {
    // 思路：双指针 + 哈希表
    // 时间 O(n)，空间 O(n)

    // 如果成立则外面全成立
    // 一个哈希表保存个数和对数
    int j = 0, sz = nums.size();
    unordered_map<int, int> umap; // 保存

    // cnt 保存子数组的对数
    long long cnt = 0, res = 0;
    for (int i = 0; i < sz; i++) {
        cnt += umap[nums[i]];
        umap[nums[i]]++;

        while (cnt >= k) {
            res += (sz - i);

            umap[nums[j]]--;
            cnt -= umap[nums[j]];
            j++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << countGood({1, 1, 1, 1, 1}, 10) << endl;
    // 4
    cout << countGood({3, 1, 4, 3, 2, 2, 4}, 2) << endl;

    return 0;
}
