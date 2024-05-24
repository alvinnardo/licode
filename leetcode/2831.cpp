#include "../template/head.h"
#include <bits/stdc++.h>

int longestEqualSubarray(vector<int> nums, int k) {
    // 题解：分组 + 双指针，统计每个数字的下标，然后对每个数字做双指针
    // 时间 O(n), 空间 O(n)
    int sz = nums.size();
    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < sz; i++) {
        umap[nums[i]].push_back(i);
    }

    int res = 0;
    for (auto &mm : umap) {
        auto &mmv = mm.second;
        int j = 0;
        for (int i = 0; i < mmv.size(); i++) {
            // 窗口大小 - 数字个数
            while (mmv[i] - mmv[j] + 1 - (i - j + 1) > k) {
                j++;
            }

            res = max(res, i - j + 1);
        }
    }

    return res;
}

int longestEqualSubarray_my(vector<int> nums, int k) {
    // 思路：双指针 + 哈希表, 保存区间中次数最多的数字
    // 当新纳入一个数字后，要进行判断，如果不成立，需要弹出一个数字
    // 时间 O(nlogn)，空间 O(n)
    int sz = nums.size();
    map<int, int> mm; // 保存区间中次数和数字个数的关系
    unordered_map<int, int> umap; // 保存区间中数字和次数的关系
    int j = 0, res = 0;           // 左开右闭

    for (int i = 0; i < sz; i++) {
        // 纳入一个新元素
        if (umap[nums[i]]) {
            mm[umap[nums[i]]]--;
        }
        umap[nums[i]]++;
        mm[umap[nums[i]]]++;

        // 不成立，则需要弹出一个元素
        // 判断长度和区间中最大的次数
        if (i - j + 1 - mm.rbegin()->first > k) {
            if (--mm[umap[nums[j]]] == 0) {
                mm.erase(umap[nums[j]]);
            }
            umap[nums[j]]--;
            if (mm[umap[nums[j]]]) {
                mm[umap[nums[j]]]++;
            }
            j++;
        }

        // 获取每一次合法区间的数字次数的最大值
        res = max(res, mm.rbegin()->first);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << longestEqualSubarray({1, 3, 1, 2, 1, 3}, 0) << endl;
    // 2
    cout << longestEqualSubarray({1, 3, 1, 2, 3, 3}, 0) << endl;
    // 3
    cout << longestEqualSubarray({1, 3, 1, 3, 1, 3}, 2) << endl;
    // 3
    cout << longestEqualSubarray({1, 3, 2, 3, 1, 3}, 3) << endl;
    // 4
    cout << longestEqualSubarray({1, 1, 2, 2, 1, 1}, 2) << endl;

    return 0;
}
