#include "../template/head.h"
#include <bits/stdc++.h>

int waysToSplitArray(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    long long sum = 0; // 1e10 小心超了 INT_MAX
    for (int num : nums) {
        sum += num;
    }

    long long pre = 0, cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        pre += nums[i];
        sum -= nums[i];
        if (pre >= sum) {
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << waysToSplitArray({10, 4, -8, 7}) << endl;
    // 2
    cout << waysToSplitArray({2, 3, 1, 0}) << endl;

    return 0;
}
