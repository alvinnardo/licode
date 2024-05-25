#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findIndices(vector<int> nums, int indexDifference,
                        int valueDifference) {
    // 题解思路：一次遍历
    // 遍历 j，记录 nums[i] 的最大值和最小值
    int sz = nums.size();
    int maxv = INT_MIN, max_pos = -1, minv = INT_MAX, min_pos = -1;
    for (int j = 0; j < sz; j++) {
        int i = j - indexDifference;
        if (i >= 0) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                max_pos = i;
            }
            if (nums[i] < minv) {
                minv = nums[i];
                min_pos = i;
            }
        }

        if (max_pos >= 0 && abs(nums[j] - nums[max_pos]) >= valueDifference) {
            return {max_pos, j};
        }
        if (min_pos >= 0 && abs(nums[j] - nums[min_pos]) >= valueDifference) {
            return {min_pos, j};
        }
    }

    return {-1, -1};
}

vector<int> findIndices_my(vector<int> nums, int indexDifference,
                           int valueDifference) {
    // 时间 O(n2)，空间 O(1)
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (abs(i - j) >= indexDifference &&
                abs(nums[i] - nums[j]) >= valueDifference) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main(int argc, char *argv[]) {
    // // {0, 3}
    // printVector(findIndices({5, 1, 4, 1}, 2, 4));
    // // {0, 0}
    // printVector(findIndices({2, 1}, 0, 0));
    // // {-1, -1}
    // printVector(findIndices({1, 2, 3}, 2, 4));
    // {0, 1}
    printVector(findIndices({5, 48}, 0, 24));

    return 0;
}
