#include "../template/head.h"
#include <bits/stdc++.h>

int addedInteger(vector<int> nums1, vector<int> nums2) {
    // 脑筋急转弯：直接比较最大值或最小值的差即可
    // 时间 O(n)，空间 O(1)
    return *max_element(nums2.begin(), nums2.end()) -
           *max_element(nums1.begin(), nums1.end());
}

int main(int argc, char *argv[]) {
    // 3
    cout << addedInteger({2, 6, 4}, {9, 7, 5}) << endl;
    // -5
    cout << addedInteger({10}, {5}) << endl;
    // 0
    cout << addedInteger({1, 1, 1, 1}, {1, 1, 1, 1}) << endl;

    return 0;
}
