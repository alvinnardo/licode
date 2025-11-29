#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> &&nums, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    return accumulate(nums.begin(), nums.end(), 0) % k;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minOperations({3, 9, 7}, 5) << endl;
    // 0
    cout << minOperations({4, 1, 3}, 4) << endl;
    // 5
    cout << minOperations({3, 2}, 6) << endl;

    return 0;
}
