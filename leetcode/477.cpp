#include "../template/head.h"
#include <bits/stdc++.h>

int totalHammingDistance(vector<int> nums) {
    // 思路：统计每一位上的不同
    // 时间 O(nlogk)，空间 O(1)
    int sum = 0, mask = 1;

    for (int i = 0; i < 31; i++) {
        int p0 = 0, p1 = 0;
        for (auto num : nums) {
            if (num & mask) {
                p0++;
            } else {
                p1++;
            }
        }

        sum += p0 * p1;
        mask <<= 1;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 6
    cout << totalHammingDistance({4, 14, 2}) << endl;
    // 4
    cout << totalHammingDistance({4, 14, 4}) << endl;
    // 10
    cout << totalHammingDistance({1, 1, 1, 1, 1, 0, 0}) << endl;

    return 0;
}
