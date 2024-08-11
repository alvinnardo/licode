#include "../template/head.h"
#include <bits/stdc++.h>

int maxUncrossedLines(vector<int> nums1, vector<int> nums2) {
    // 思路：DP，最长公共子序列
    // 时间 O(mn)，空间 O(mn)
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                vec[i][j] = vec[i - 1][j - 1] + 1;
            } else {
                vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
            }
        }
    }

    return vec[m][n];
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxUncrossedLines({1, 4, 2}, {1, 2, 4}) << endl;
    // 3
    cout << maxUncrossedLines({2, 5, 1, 2, 5}, {10, 5, 2, 1, 5, 2}) << endl;
    // 2
    cout << maxUncrossedLines({1, 3, 7, 1, 7, 5}, {1, 9, 2, 5, 1}) << endl;

    return 0;
}
