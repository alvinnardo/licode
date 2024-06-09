#include "../template/head.h"
#include <bits/stdc++.h>

bool checkPossibility(vector<int> nums) {
    // 思路：找到递增和递减的位置
    // 时间 O(n)，空间 O(1)
    int sz = nums.size();
    int pos = -1;
    for (int i = 1; i < sz; i++) {
        if (nums[i] < nums[i - 1]) {
            if (pos == -1) {
                pos = i;
            } else {
                return false;
            }
        }
    }

    // 没有递减
    if (pos == -1) {
        return true;
    }

    // 去掉大值 或 去掉小值
    int left = pos - 1 == 0 ? INT_MIN : nums[pos - 2];
    int right = pos == sz - 1 ? INT_MAX : nums[pos + 1];
    return left <= nums[pos] || nums[pos - 1] <= right;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkPossibility({4, 2, 3}) << endl;
    // 0
    cout << checkPossibility({4, 2, 1}) << endl;
    // 1
    cout << checkPossibility({1, 2}) << endl;
    // 0
    cout << checkPossibility({1, 2, 4, 1, 2}) << endl;
    // 1
    cout << checkPossibility({5, 7, 1, 8}) << endl;

    return 0;
}
