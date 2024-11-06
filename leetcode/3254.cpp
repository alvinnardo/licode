#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> resultsArray(vector<int> nums, int k) {
    // 思路：滑动窗口 + 模拟
    // 时间 O(n)，空间 O(1)

    vector<int> res;
    int sz = nums.size(), cnt = 0, j = 0;
    for (int i = 0; i < sz; i++) {
        if (i == 0 || nums[i] - nums[i - 1] == 1) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (i >= k - 1) { // 小于 k 的不记录
            // 连续递增个数比窗口要大或等于，表示窗口框住的是连续递增的
            res.emplace_back(cnt >= k ? nums[i] : -1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,4,-1,-1,-1}
    printVector(resultsArray({1, 2, 3, 4, 3, 2, 5}, 3));
    // {1,2,3,4,3,2,5}
    printVector(resultsArray({1, 2, 3, 4, 3, 2, 5}, 1));
    // {-1,-1}
    printVector(resultsArray({2, 2, 2, 2, 2}, 4));
    // {-1,3,-1,3,-1}
    printVector(resultsArray({3, 2, 3, 2, 3, 2}, 2));

    return 0;
}
