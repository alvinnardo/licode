#include "../template/head.h"
#include <bits/stdc++.h>

int maximumBeauty(vector<int> nums, int k) {
    // 思路：差分数组
    // 时间 O(n + m), m 是 [min(nums) - k, max(nums) + k]
    // 空间 O(max(nums) - min(nums) + 2k + 1)
    int minv = INT_MAX, maxv = INT_MIN;
    for (int i : nums) {
        if (i > maxv) {
            maxv = i;
        }
        if (i < minv) {
            minv = i;
        }
    }

    int left = minv - k, right = maxv + k;
    vector<int> vec(right - left + 2);
    for (int i : nums) {
        vec[i - k - left]++;
        vec[i + k + 1 - left]--;
    }

    int res = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) {
            vec[i] += vec[i - 1];
        }

        res = max(res, vec[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 3
    cout << maximumBeauty({4, 6, 1, 2}, 2) << endl;
    // 4
    cout << maximumBeauty({1, 1, 1, 1}, 10) << endl;
    // 4
    cout << maximumBeauty({10000, 20000, 100000, 4}, 100000) << endl;
    // 4
    cout << maximumBeauty({0, 0, 0, 0}, 0) << endl;

    return 0;
}
