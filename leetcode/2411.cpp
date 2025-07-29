#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> smallestSubarrays(vector<int> &&nums) {
    // 思路：统计 + 双指针
    // 时间 O(kn)，空间 O(n + k)
    int sz = nums.size();

    // 从后往前遍历一遍能获取到每一个数到最后的最大值
    vector<int> maxv_vec(sz);
    for (int i = sz - 1; i >= 0; i--) {
        maxv_vec[i] = i == sz - 1 ? nums[i] : (nums[i] | maxv_vec[i + 1]);
    }

    // 用于存放每一位的个数
    vector<int> digit_vec(32);
    auto add_digit = [&](int t, bool add = true) {
        int pos = 0;
        while (t) {
            if (t & 1) {
                if (add) {
                    digit_vec[pos]++;
                } else {
                    digit_vec[pos]--;
                }
            }
            pos++;
            t >>= 1;
        }
    };

    // 检查当前范围的数能否组成最大值
    auto check = [&](int target) {
        int tmp = 0;
        for (int i = 0; i < digit_vec.size(); i++) {
            if (digit_vec[i]) {
                tmp += (1 << i);
            }
            if (tmp == target) {
                return true;
            }
        }
        return tmp == target;
    };

    vector<int> res(sz);
    int j = 0;
    // 双指针，每次移动右边界
    for (int i = 0; i < sz; i++) {
        // 范围是空的话必须获取一个数
        while (j == i || !check(maxv_vec[i])) {
            add_digit(nums[j++]);
        }

        res[i] = j - i;
        add_digit(nums[i], false);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,3,2,2,1}
    printVector(smallestSubarrays({1, 0, 2, 1, 3}));
    // {2,1}
    printVector(smallestSubarrays({1, 2}));
    // {1}
    printVector(smallestSubarrays({0}));

    return 0;
}
