#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> buildArray(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 进阶要求使用 O(1) 空间，数字上限为 999，
    // 则可以用原数组表示，最后处理一下
    // 最后三位保存原来的数字，高位保存结果
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        nums[i] = nums[nums[i] % 1000] % 1000 * 1000 + nums[i] % 1000;
    }

    for (int i = 0; i < sz; i++) {
        nums[i] = nums[i] / 1000;
    }

    return nums;
}

int main(int argc, char *argv[]) {
    // {0,1,2,4,5,3}
    printVector(buildArray({0, 2, 1, 5, 3, 4}));
    // {4,5,0,1,2,3}
    printVector(buildArray({5, 0, 1, 2, 3, 4}));

    return 0;
}
