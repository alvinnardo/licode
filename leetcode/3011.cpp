#include "../template/head.h"
#include <bits/stdc++.h>

bool canSortArray(vector<int> nums) {
    // 思路：模拟，计算每个区间内的最小值和最大值
    // 最后判断相邻区间是否满足条件
    // 时间 O(n)，空间 O(n)
    int maxv = -1, cnt = -1;
    int sz = nums.size();

    auto getNum = [](int t) { return __builtin_popcount(t); };
    vector<pair<int, int>> vec;

    for (int i = 0; i < sz; i++) {
        int v = getNum(nums[i]);
        if (v != cnt) {
            vec.emplace_back(nums[i], nums[i]);
            cnt = v;
        } else {
            auto &t = vec.back();
            t.first = min(t.first, nums[i]);
            t.second = max(t.second, nums[i]);
        }
    }

    for (int i = 1; i < vec.size(); i++) {
        auto &pre = vec[i - 1];
        auto &pfx = vec[i];
        if (pre.second > pfx.first) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << canSortArray({8, 4, 2, 30, 15}) << endl;
    // 1
    cout << canSortArray({1, 2, 3, 4, 5}) << endl;
    // 0
    cout << canSortArray({3, 16, 8, 4, 2}) << endl;

    return 0;
}
