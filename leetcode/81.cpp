#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return true;
        }

        if (nums[l] == nums[mid] &&
            nums[mid] == nums[r]) { // 都相等，无法判断哪边有序，缩区间
            l++;
            r--;
        } else if (nums[l] <= nums[mid]) { // 根据上面的条件，nums[mid] !=
                                           // nums[r], mid 点只有两种情况，1
                                           // 是单个非递减图，2
                                           // 是两个非递减图，在左边部分上
            // 左半部分肯定是大于等于右半部分的
            // 如果左小于中，则肯定是在递增区间上
            if (target >= nums[l] && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else { // 同理
            if (target > nums[mid] && target <= nums[r - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

bool search_review(vector<int> nums, int target) {
    // 思路：二分
    // 硬找
    // 时间 O(logn)，空间 O(logn)

    function<bool(int, int)> dfs = [&](int bng, int end) -> bool {
        if (bng > end) {
            return false;
        }

        if (bng == end) {
            return nums[bng] == target;
        }

        int mid = bng + ((end - bng) >> 1);
        if (nums[mid] == target) {
            return true;
        }

        return dfs(bng, mid - 1) || dfs(mid + 1, end);
    };

    return dfs(0, nums.size() - 1);
}

// 现在看之前写的算法太菜了
bool search_bad(vector<int> nums, int target) {
    // 找到突变点
    // 前后二分
    // 写麻烦了，O(n) 了，为什么不直接一次查找呢
    int pos = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            pos = i;
        }
    }

    if (pos == -1) {
        if (target < nums[0] || target > nums.back()) {
            return false;
        }

        auto f = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return target == nums[f];
    }

    // 圈定范围，在范围中找，不在范围中的都是 false
    if (target >= nums[0] && target <= nums[pos]) {
        auto f = lower_bound(nums.begin(), nums.begin() + pos + 1, target) -
                 nums.begin();
        return target == nums[f];
    } else if (target >= nums[pos + 1] && target <= nums.back()) {
        auto f = lower_bound(nums.begin() + pos + 1, nums.end(), target) -
                 nums.begin();
        return target == nums[f];
    }
    return 0;
}

int main(void) {
    printBool(search({3, 5, 6, 0, 1, 1, 2}, 0));
    printBool(search({2, 5, 6, 0, 0, 1, 2}, 3));
    return 0;
}
