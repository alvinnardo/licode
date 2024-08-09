#include "../template/head.h"
#include <bits/stdc++.h>

int minimumAddedInteger(vector<int> nums1, vector<int> nums2) {
    // 思路：贪心
    // 时间 O(n2)，空间 O(logn)
    /**
      证明: 如果排序后最大值的差 = 最小值的差，则该差就是最终的差
      设 nums1 的最小值为 min1, 最大值为 max1；
         nums2 的最小值为 min2，最大值为 max2
      反证法：如果不是最终的差，那么相等的数组在中间
      由于数组在递增，min2 - 第二个元素 就会比之前的 差要小
                      max2 - 倒数第二个元素 比之前的 差更大
      相互矛盾，所以原假设成立
    */
    int m = nums1.size(), n = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    auto getDiff = [&](int begin, int end, int pos = -1) {
        int res = INT_MAX;
        int j = 0;
        for (int i = begin; i <= end; i++) {
            if (i == pos) {
                continue;
            }

            if (res == INT_MAX) {
                res = nums2[j] - nums1[i];
            } else if (nums2[j] - nums1[i] != res) {
                return INT_MAX;
            }

            j++;
        }

        return res;
    };

    int res = INT_MAX;
    if (nums2[0] - nums1[0] == nums2[n - 1] - nums1[m - 1]) {
        return nums2[0] - nums1[0];
    }

    // 两边都不成立
    res = min(res, getDiff(1, m - 2));
    for (int i = 1; i < m; i++) { // 左边不成立，遍历右边的
        res = min(res, getDiff(1, m - 1, i));
    }
    for (int i = 0; i < m - 1; i++) { // 右边不成立，遍历左边的
        res = min(res, getDiff(0, m - 2, i));
    }

    return res;
}

int main(int argc, char *argv[]) {
    // -2
    cout << minimumAddedInteger({4, 20, 16, 12, 8}, {14, 18, 10}) << endl;
    // 2
    cout << minimumAddedInteger({3, 5, 5, 3}, {7, 7}) << endl;
    //-3
    cout << minimumAddedInteger({3, 5, 10, 9, 9, 4}, {1, 6, 6, 0}) << endl;

    return 0;
}
