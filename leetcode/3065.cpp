#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums, int k) {
    // 思路：遍历
    // 时间 O(n)，空间 O(1)
    return count_if(nums.begin(), nums.end(), [&](int num) { return num < k; });
}

int main(int argc, char *argv[]) {
    // 3
    cout << minOperations({2, 11, 10, 1, 3}, 10) << endl;
    // 0
    cout << minOperations({1, 1, 2, 4, 9}, 1) << endl;
    // 4
    cout << minOperations({1, 1, 2, 4, 9}, 9) << endl;

    return 0;
}
