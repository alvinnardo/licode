#include "../template/head.h"
#include <bits/stdc++.h>
int duplicateNumbersXOR(vector<int> nums) {
    // 题解：哈希表
    // 题目中给定 1<= nums[i] <= 50，可以用 uint64_t 替代哈希表
    // 时间 O(n)，空间 O(1)
    int res = 0;
    uint64_t uset = 0, mask = 1;
    for (int i : nums) {
        if (!(uset & (mask << i))) {
            uset ^= (mask << i);
        } else { // 出现第二次再处理
            res ^= i;
        }
    }

    return res;
}

int duplicateNumbersXOR_my(vector<int> nums) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    int res = 0;
    unordered_set<int> uset;
    for (int i : nums) {
        // 每个一遍
        res ^= i;
        // 出现一次的异或两次
        // 出现两次的异或三次
        if (!uset.count(i)) {
            uset.insert(i);
            res ^= i;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << duplicateNumbersXOR({1, 2, 1, 3}) << endl;
    // 0
    cout << duplicateNumbersXOR({1, 2, 3}) << endl;
    // 3
    cout << duplicateNumbersXOR({1, 2, 2, 1}) << endl;

    return 0;
}
