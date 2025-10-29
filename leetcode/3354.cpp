#include "../template/head.h"
#include <bits/stdc++.h>

int countValidSelections(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)

    // 计算每一位左边和以及右边和
    // 左和右相等就是两次
    // 差的绝对值不超过 1 就行
    int sz = nums.size();
    vector<int> left(sz), right(sz);
    int t{};
    for (int i = 1; i < sz; i++) {
        t = sz - i - 1;

        left[i] = i == 1 ? nums[i - 1] : nums[i - 1] + left[i - 1];
        right[t] = i == 1 ? nums[t + 1] : nums[t + 1] + right[t + 1];
    }

    int res{};
    for (int i = 0; i < sz; i++) {
        if (nums[i] == 0) {
            if (left[i] == right[i]) {
                res += 2;
            } else if (abs(left[i] - right[i]) == 1) {
                res++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countValidSelections({1, 0, 2, 0, 3}) << endl;
    // 0
    cout << countValidSelections({2, 3, 4, 0, 4, 1, 0}) << endl;

    return 0;
}
