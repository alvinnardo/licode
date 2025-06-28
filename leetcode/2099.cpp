#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> maxSubsequence(vector<int> &&nums, int k) {
    // 思路：排序
    // 时间 O(nlogn)，空间 O(logn)
    // 先把位置排序，然后取 k 个，然后按位置大小排序得到序列

    int n = nums.size();
    vector<int> pos_vec(n);
    iota(pos_vec.begin(), pos_vec.end(), 0);
    sort(pos_vec.begin(), pos_vec.end(), [&](int a, int b) {
        return nums[a] == nums[b] ? a < b : nums[a] > nums[b];
    });

    pos_vec.resize(k);
    sort(pos_vec.begin(), pos_vec.end());
    for (int i = 0; i < pos_vec.size(); i++) {
        pos_vec[i] = nums[pos_vec[i]];
    }

    return pos_vec;
}

int main(int argc, char *argv[]) {
    // {3,3}
    printVector(maxSubsequence({2, 1, 3, 3}, 2));
    // {-1,3,4}
    printVector(maxSubsequence({-1, -2, 3, 4}, 3));
    // {3,4}
    printVector(maxSubsequence({3, 4, 3, 3}, 2));

    return 0;
}
