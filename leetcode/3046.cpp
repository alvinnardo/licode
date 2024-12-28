#include "../template/head.h"
#include <bits/stdc++.h>

bool isPossibleToSplit(vector<int> nums) {
    // 思路：容斥原理
    // 每个数最多出现 2 次
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    for (auto &num : nums) {
        if (++umap[num] > 2) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << isPossibleToSplit({1, 1, 2, 2, 3, 4}) << endl;
    // 0
    cout << isPossibleToSplit({1, 1, 1, 1}) << endl;

    return 0;
}
