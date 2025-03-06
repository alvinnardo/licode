#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> rearrangeArray(vector<int> nums) {
    // 思路：模拟
    // 时间: O(n)，空间 O(n)

    int sz = nums.size();
    int pos0 = 0, pos1 = 1;
    vector<int> res(sz);

    for (int i = 0; i < sz; i++) {
        if (nums[i] > 0) {
            res[pos0] = nums[i];
            pos0 += 2;
        } else {
            res[pos1] = nums[i];
            pos1 += 2;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,-2,1,-5,2,-4}
    printVector(rearrangeArray({3, 1, -2, -5, 2, -4}));
    // {1,-1}
    printVector(rearrangeArray({-1, 1}));

    return 0;
}
