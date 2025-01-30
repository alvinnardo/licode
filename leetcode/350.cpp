#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> intersect(vector<int> nums1, vector<int> nums2) {
    // 思路：排序
    // 时间 O(mlogm + nlogn)，空间 O(logm + logn)
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2,2}
    printVector(intersect({1, 2, 2, 1}, {2, 2}));
    // {4,9}
    printVector(intersect({4, 9, 5}, {9, 4, 9, 8, 4}));

    return 0;
}
