#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> advantageCount(vector<int> nums1, vector<int> nums2) {
    // 思路：贪心 + 双指针
    // 时间 O(nlogn)，空间 O(n)

    int sz = nums1.size();
    vector<int> pos_vec(sz);
    iota(pos_vec.begin(), pos_vec.end(), 0);
    sort(pos_vec.begin(), pos_vec.end(),
         [&](int a, int b) { return nums2[a] < nums2[b]; });

    sort(nums1.begin(), nums1.end());

    queue<int> qu;

    vector<int> res(sz);

    // nums2 从小到大找，nums1 也从小到大找
    // 如果 nums1 有大于 nums2 的，就保存结果，否则加入候选队列
    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (nums1[i] > nums2[pos_vec[j]]) {
            res[pos_vec[j++]] = nums1[i];
        } else {
            qu.push(nums1[i]);
        }
    }

    // 候选队列中的顺序随便放
    while (j < sz) {
        res[pos_vec[j++]] = qu.front();
        qu.pop();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2,11,7,15}
    printVector(advantageCount({2, 7, 11, 15}, {1, 10, 4, 11}));
    // {24,32,8,12}
    printVector(advantageCount({12, 24, 8, 32}, {13, 25, 32, 11}));

    return 0;
}
