#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfPairs(vector<int> nums1, vector<int> nums2, int k) {
    // 思路：数据量不大，暴力解决
    // 时间: O(mn)，空间 O(1)
    int m = nums1.size(), n = nums2.size();
    for (int i = 0; i < n; i++) {
        nums2[i] *= k;
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res += (nums1[i] % nums2[j]) == 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << numberOfPairs({1, 3, 4}, {1, 3, 4}, 1) << endl;
    // 2
    cout << numberOfPairs({1, 2, 4, 12}, {2, 4}, 3) << endl;

    return 0;
}
