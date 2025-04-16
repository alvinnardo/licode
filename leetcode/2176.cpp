#include "../template/head.h"
#include <bits/stdc++.h>

int countPairs(vector<int> nums, int k) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(1)
    int sz = nums.size(), res = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < i; j++) {
            res += ((nums[i] == nums[j]) && (i * j) % k == 0);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countPairs({3, 1, 2, 2, 2, 1, 3}, 2) << endl;
    // 0
    cout << countPairs({1, 2, 3, 4}, 1) << endl;

    return 0;
}
