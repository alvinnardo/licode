#include "../template/head.h"
#include <bits/stdc++.h>

int semiOrderedPermutation(vector<int> nums) {
    // 思路：模拟
    // 找到各自的位置，如果有交叉结果减一
    // 时间 O(n)，空间 O(1)
    int a_pos = -1, b_pos = -1, flag = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            a_pos = i;
        } else if (nums[i] == nums.size()) {
            b_pos = i;
        }
    }

    if (a_pos > b_pos) {
        flag--;
    }

    return a_pos + nums.size() - 1 - b_pos + flag;
}

int main(int argc, char *argv[]) {
    // 2
    cout << semiOrderedPermutation({2, 1, 4, 3}) << endl;

    // 3
    cout << semiOrderedPermutation({2, 4, 1, 3}) << endl;
    // 0
    cout << semiOrderedPermutation({1, 3, 4, 2, 5}) << endl;

    return 0;
}
