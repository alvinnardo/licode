#include "../template/head.h"
#include <bits/stdc++.h>

int maximumEnergy(vector<int> &&energy, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    // 每个元素只遍历了一遍

    // 因为选取每个元素都会到末尾，所以从后往前遍历
    // 结果可能有负数
    int res{INT_MIN}, every{}, sz = energy.size();
    for (int i = 0; i < k; i++) {
        every = 0;
        for (int j = sz - 1 - i; j >= 0; j -= k) {
            every += energy[j];
            res = every > res ? every : res;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maximumEnergy({5, 2, -10, -5, 1}, 3) << endl;
    // -1
    cout << maximumEnergy({-2, -3, -1}, 2) << endl;

    return 0;
}
