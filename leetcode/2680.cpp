#include "../template/head.h"
#include <bits/stdc++.h>

long long maximumOr(vector<int> nums, int k) {
    // 思路：双指针
    // 时间 O(n)，空间 O(n)

    // 本质思想是测试每一个数，其余的相与
    // 从后往前的保存下来，从前往后的遍历一次即可

    int sz = nums.size();
    vector<int> pre(sz);
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            pre[i] = nums[i];
        } else {
            pre[i] = nums[i] | pre[i - 1];
        }
    }

    long long maxv = LLONG_MIN;
    int tail = 0;
    for (int i = sz - 1; i >= 0; i--) {
        if (i == 0) {
            maxv = max(maxv, ((long long)nums[i] << k) | tail);
        } else {
            maxv = max(maxv, ((long long)nums[i] << k) | tail | pre[i - 1]);
            tail |= nums[i];
        }
    }

    return maxv;
}

long long maximumOr1(vector<int> nums, int k) {
    // 思路：统计
    // 时间 O(nlogC)，空间 O(logC)

    // 考虑到如果最高位相同，乘以 2 以后再或，不一定最大值最优
    // 则对每个数进行模拟，或就用数组统计
    long long maxv = LLONG_MIN;
    vector<int> vec(32);

    // 统计每一位
    auto bitAdd = [&](int num, bool add = true) {
        int pos = 0;
        while (num) {
            if (num & 1) {
                if (add) {
                    vec[pos]++;
                } else {
                    vec[pos]--;
                }
            }
            num >>= 1;
            pos++;
        }
    };

    // 将数组生成数字
    auto genNum = [&]() {
        int res = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i]) {
                res += (1 << i);
            }
        }
        return res;
    };

    for (int num : nums) {
        bitAdd(num);
    }

    // 依次遍历，找到最优的那个数字
    for (int num : nums) {
        bitAdd(num, false);
        // 直接 k 次，如果是的话，乘以 2 后，后面都是它
        maxv = max(maxv, ((long long)num << k) | genNum());
        bitAdd(num);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 30
    cout << maximumOr({12, 9}, 1) << endl;
    // 35
    cout << maximumOr({8, 1, 2}, 2) << endl;
    // 49759
    cout << maximumOr({87, 97, 17, 20, 5, 11}, 9) << endl;
    // 96383
    cout << maximumOr({41, 79, 82, 27, 71, 62, 57, 67, 34, 8,  71, 2,  12, 93,
                       52, 91, 86, 81, 1,  79, 64, 43, 32, 94, 42, 91, 9,  25},
                      10)
         << endl;

    return 0;
}
