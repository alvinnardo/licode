#include "../template/head.h"
#include <bits/stdc++.h>

int maximumLength(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    // max{全奇，全偶, 奇偶合并后混合}
    vector<int> vec{0, 0, 0};
    bool odd = false;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & 1) {
            // 如果之前是偶
            if (i == 0 || !odd) {
                odd = true;
                ++vec[2];
            }
            ++vec[0];
        } else {
            // 如果之前是奇
            if (i == 0 || odd) {
                odd = false;
                ++vec[2];
            }
            ++vec[1];
        }
    }

    return *max_element(vec.begin(), vec.end());
}

int main(int argc, char *argv[]) {
    // 4
    cout << maximumLength({1, 2, 3, 4}) << endl;
    // 6
    cout << maximumLength({1, 2, 1, 1, 2, 1, 2}) << endl;
    // 2
    cout << maximumLength({1, 3}) << endl;

    return 0;
}
