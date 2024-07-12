#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> numberGame(vector<int> nums) {
    // 思路：模拟
    // 时间 O(nlogn)，空间 O(logn)，排序用的栈空间
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for (int i = 0; i < sz; i += 2) {
        if (i + 1 < sz) {
            swap(nums[i], nums[i + 1]);
        }
    }

    return nums;
}

int main(int argc, char *argv[]) {
    // {3,2,5,4}
    printVector(numberGame({5, 4, 2, 3}));
    // {5,2}
    printVector(numberGame({2, 5}));

    return 0;
}
