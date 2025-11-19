#include "../template/head.h"
#include <bits/stdc++.h>

int findFinalValue(vector<int> &&nums, int original) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    unordered_set<int> uset(nums.begin(), nums.end());
    while (uset.count(original)) {
        original <<= 1;
    }

    return original;
}

int main(int argc, char *argv[]) {
    // 24
    cout << findFinalValue({5, 3, 6, 1, 12}, 3) << endl;
    // 4
    cout << findFinalValue({2, 7, 9}, 4) << endl;

    return 0;
}
