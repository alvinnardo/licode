#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    // 双向遍历
    int sz = nums.size();
    vector<int> res(sz, 1);
    int left = 1, right = 1;
    for (int i = 1; i < sz; i++) {
        left *= nums[i - 1];
        right *= nums[sz - i];
        res[i] *= left;
        res[sz - i - 1] *= right;
    }

    return res;
}

int main(void) {
    printVector(productExceptSelf({1, 2, 3, 4}));
    printVector(productExceptSelf({-1, 1, 0, -3, 3}));

    return 0;
}
