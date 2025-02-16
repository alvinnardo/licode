#include "../template/head.h"
#include <bits/stdc++.h>

int maximumXOR(vector<int> nums) {
    // 思路：遍历 + 模拟
    // 因为每个数可以与任意数相与，可以变小
    // 最后的结果是异或，则只要有一个数有 1 即可
    // 时间 O(n)，空间 O(1)
    int res = 0;
    for (int num : nums) {
        res |= num;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << maximumXOR({3, 2, 4, 6}) << endl;
    // 11
    cout << maximumXOR({1, 2, 3, 9, 2}) << endl;

    return 0;
}
