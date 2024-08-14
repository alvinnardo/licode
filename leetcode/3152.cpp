#include "../template/head.h"
#include <bits/stdc++.h>

vector<bool> isArraySpecial(vector<int> nums, vector<vector<int>> queries) {
    // 思路：模拟，找到每个区间的范围，对每次查询判断两个点是否在同一区间内
    // 时间 O(m + n)，空间 O(1)
    int sz = nums.size();
    int cur = 0;
    bool odd = (nums[0] & 1) ? true : false;
    nums[0] = 0;
    for (int i = 1; i < sz; i++) {
        if ((nums[i] & 1) && odd || !(nums[i] & 1) && !odd) {
            cur++;
        } else {
            odd = !odd;
        }
        nums[i] = cur;
    }

    vector<bool> res;
    for (auto &q : queries) {
        res.push_back(nums[q[0]] == nums[q[1]] ? 1 : 0);
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {false}
    printVector(isArraySpecial({3, 4, 1, 2, 6}, {{0, 4}}));
    // {false,true}
    printVector(isArraySpecial({4, 3, 1, 6}, {{0, 2}, {2, 3}}));

    return 0;
}
