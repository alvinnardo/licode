#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int> nums) {
    // 思路：找规律
    // 1. 先求得 F(0)
    // 2. F(i) - F(i - 1) = (n - 1) * nums[i - 1] - (sum(tot) - nums[i - 1])

    // 时间 O(n), 空间 O(1)
    int maxv = 0, sz = nums.size();
    int tot = accumulate(nums.begin(), nums.end(), 0);
    // 求 F(0), 最大值先设置为 F(0)
    for (int i = 0; i < nums.size(); i++) {
        maxv += i * nums[i];
    }

    // 根据递推公式依次求值
    int pre = maxv;
    for (int i = 1; i < sz; i++) {
        pre += (sz - 1) * nums[i - 1] - (tot - nums[i - 1]);
        maxv = max(maxv, pre);
    }

    return maxv;
}

int main(void) {
    // 26
    cout << maxRotateFunction({4, 3, 2, 6}) << endl;
    // 0
    cout << maxRotateFunction({0}) << endl;

    return 0;
}
