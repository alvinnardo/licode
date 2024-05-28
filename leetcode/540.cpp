#include "../template/head.h"
#include <bits/stdc++.h>

int singleNonDuplicate(vector<int> nums) {
    // 思路：二分
    // 因为是排好序的，则可以二分，每次在奇数范围中找
    // 时间 O(logn)，空间 O(1)

    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        if (i == j) {
            return nums[i];
        }

        int mid = i + (j - i) / 2;
        if (mid > i && nums[mid] == nums[mid - 1]) {
            if ((mid - 2 - i + 1) & 1) {
                j = mid - 2;
            } else {
                i = mid + 1;
            }
        } else if (mid < j && nums[mid] == nums[mid + 1]) {
            if ((mid - 1 - i + 1) & 1) {
                j = mid - 1;
            } else {
                i = mid + 2;
            }
        } else {
            return nums[mid];
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 8
    cout << singleNonDuplicate({1, 1, 2, 2, 3, 3, 4, 4, 8}) << endl;
    // 2
    cout << singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}) << endl;
    // 10
    cout << singleNonDuplicate({3, 3, 7, 7, 10, 11, 11}) << endl;
    // 1
    cout << singleNonDuplicate({0}) << endl;

    return 0;
}
