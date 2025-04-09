#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums, int k) {
    // 思路：哈希表
    // 时间 O(n)，最差空间 O(n)
    unordered_set<int> uset;
    for (auto &num : nums) {
        if (num < k) {
            return -1;
        } else if (num > k) {
            uset.insert(num);
        }
    }

    return uset.size();
}

int main(int argc, char *argv[]) {
    // 2
    cout << minOperations({5, 2, 5, 4, 5}, 2) << endl;
    // -1
    cout << minOperations({2, 1, 2}, 2) << endl;
    // 4
    cout << minOperations({9, 7, 5, 3}, 1) << endl;

    return 0;
}
