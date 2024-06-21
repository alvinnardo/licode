#include "../template/head.h"
#include <bits/stdc++.h>

int findLength(vector<int> nums1, vector<int> nums2) {
    // 思路：向两边拽，每次查询一遍，滑动窗口
    // 时间 O(mn)，空间 O(1)
    int m = nums1.size(), n = nums2.size();
    int maxv = 0;
    for (int step = 0; step <= m + n - 2; step++) {
        int la = 0, lb = m - 1;
        int ra = -n + 1 + step, rb = step;
        int ora = max(la, ra), orb = min(lb, rb);

        int cnt = 0;
        for (int i = ora; i < orb + 1; i++) {
            int ni = n - 1 - step + i;
            if (nums1[i] == nums2[ni]) {
                cnt++;
            } else {
                cnt = 0;
            }

            if (cnt > maxv) {
                maxv = cnt;
            }
        }
    }

    return maxv;
}

int main(int argc, char *argv[]) {

    // 3
    cout << findLength({1, 2, 3, 2, 1}, {3, 2, 1, 4, 7}) << endl;
    // 5
    cout << findLength({0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}) << endl;
    // 3
    cout << findLength({1, 2, 3, 4, 5}, {1, 2, 3}) << endl;
    // 3
    cout << findLength({1, 2, 3}, {1, 2, 3, 4, 5}) << endl;

    return 0;
}
