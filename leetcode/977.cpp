#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> sortedSquares(vector<int> nums) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)
    int sz = nums.size();
    vector<int> res(sz);
    int i = 0, j = sz - 1, k = sz - 1;

    while (k >= 0) {
        int i2 = nums[i] * nums[i], j2 = nums[j] * nums[j];
        if (i2 > j2) {
            res[k--] = i2;
            i++;
        } else {
            res[k--] = j2;
            j--;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {0,1,9,16,100}
    printVector(sortedSquares({-4, -1, 0, 3, 10}));
    // {4,9,9,49,121}
    printVector(sortedSquares({-7, -3, 2, 3, 11}));

    return 0;
}
