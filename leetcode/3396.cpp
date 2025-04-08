#include "../template/head.h"
#include <bits/stdc++.h>

int minimumOperations(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(k)，k = 101

    vector<int> vec(101);

    int sz = nums.size();
    int i = sz - 1;
    for (; i >= 0; i--) {
        if (vec[nums[i]] == 1) {
            break;
        }

        vec[nums[i]] = 1;
    }

    return (i + 3) / 3; // i 可能为 -1，(i + 1 + 2) / 3;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minimumOperations({1, 2, 3, 4, 2, 3, 3, 5, 7}) << endl;
    // 2
    cout << minimumOperations({4, 5, 6, 4, 4}) << endl;
    // 0
    cout << minimumOperations({6, 7, 8, 9}) << endl;

    return 0;
}
