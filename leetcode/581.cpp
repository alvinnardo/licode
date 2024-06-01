#include "../template/head.h"
#include <bits/stdc++.h>

int findUnsortedSubarray(vector<int> nums) {
    // 题解：一次遍历
    // 从左到右遍历，保存最大值，如果小于最大值表示值有问题
    // 从右到左遍历，保存最小值，如果大于最小值表示值有问题

    int maxv = INT_MIN, right = -1;
    int minv = INT_MAX, left = -1;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        if (nums[i] < maxv) {
            right = i;
        } else {
            maxv = nums[i];
        }

        int t = sz - i - 1;
        if (nums[t] > minv) {
            left = t;
        } else {
            minv = nums[t];
        }
    }

    return left == -1 ? 0 : right - left + 1;
}

int findUnsortedSubarray_my(vector<int> nums) {
    // 思路：单调栈 + 二分查找
    // 时间 O(nlogn)，空间 O(n)
    vector<int> vec;
    int sz = nums.size();
    int bng = -1, end = -1;
    for (int i = 0; i < sz; i++) {
        if (vec.empty()) {
            vec.push_back(i);
            continue;
        }

        if (nums[i] < nums[vec.back()]) {
            int a = 0, b = vec.size();
            while (a <= b) {
                int mid = a + (b - a) / 2;
                if (nums[vec[mid]] <= nums[i]) {
                    a = mid + 1;
                } else {
                    b = mid - 1;
                }
            }

            if (bng == -1) {
                bng = vec[a];
            } else {
                bng = min(bng, vec[a]);
            }
            end = i;
        } else {
            vec.push_back(i);
        }
    }

    return bng < 0 ? 0 : end - bng + 1;
}

int main(int argc, char *argv[]) {
    // 5
    cout << findUnsortedSubarray({1, 2, 6, 7, 7, 7, 7, 6}) << endl;
    // 5
    cout << findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15}) << endl;
    // 0
    cout << findUnsortedSubarray({1, 2, 3, 4}) << endl;
    // 0
    cout << findUnsortedSubarray({1}) << endl;
    // 5
    cout << findUnsortedSubarray({5, 4, 3, 2, 1}) << endl;

    return 0;
}
