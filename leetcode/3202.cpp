#include "../template/head.h"
#include <bits/stdc++.h>

int maximumLength(vector<int> &&nums, int k) {
    // 思路：DP
    // 时间 O(n2)，空间 O(nk)
    // (a + b) % k = (a % k + b % k) % k

    int sz = nums.size();
    // vec[i][j] 表示以 nums[i] 为结尾，j 为前一个数的序列的最大长度
    vector<vector<int>> vec(sz, vector<int>(k));
    int maxv = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] % k;

        for (int j = i - 1; j >= 0; j--) {
            if (vec[i][nums[j]]) {
                continue;
            }

            vec[i][nums[j]] =
                max(vec[j][nums[i]] == 0 ? 2 : vec[j][nums[i]] + 1,
                    vec[i][nums[j]]);

            maxv = max(vec[i][nums[j]], maxv);
        }
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 5
    cout << maximumLength({1, 2, 3, 4, 5}, 2) << endl;
    // 4
    cout << maximumLength({1, 4, 2, 3, 1, 4}, 3) << endl;
    // 3
    cout << maximumLength(
                {927517, 576090, 339604, 276827, 578131, 366183, 608823, 123674,
                 895043, 48909,  581264, 249449, 208263, 642942, 849188, 322834,
                 741966, 763793, 191104, 188253, 647135, 614212, 179766, 624505,
                 227334, 819696, 69764,  43208,  447951, 98985,  254006, 891820,
                 191426, 593609, 168646, 769556, 476143},
                468)
         << endl;

    return 0;
}
