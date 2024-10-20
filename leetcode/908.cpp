#include "../template/head.h"
#include <bits/stdc++.h>

int smallestRangeI(vector<int> nums, int k) {
    // 思路：模拟
    // 获取最大最小值，再和浮动区间进行比较
    // 时间 O(n)，空间 O(1)
    int minv = INT_MAX, maxv = INT_MIN;
    k <<= 1;
    for (int num : nums) {
        minv = min(minv, num);
        maxv = max(maxv, num);
    }

    return maxv - minv <= k ? 0 : maxv - minv - k;
}

int main(int argc, char *argv[]) {
    // 0
    cout << smallestRangeI({1}, 0) << endl;
    // 6
    cout << smallestRangeI({0, 10}, 2) << endl;
    // 0
    cout << smallestRangeI({1, 3, 6}, 3) << endl;

    return 0;
}
