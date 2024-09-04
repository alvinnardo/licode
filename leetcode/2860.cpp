#include "../template/head.h"
#include <bits/stdc++.h>

int countWays(vector<int> nums) {
    // 思路：排序 + 贪心
    // 只有选中和不选中两种情况，
    // 对于未选中的，选中个数必须小于 nums[i]，所以只能选中小于 nums[i] 的
    // 且如果选中则前面的都要选中
    // 时间：O(nlogn)，空间 O(logn)，排序用的栈空间
    sort(nums.begin(), nums.end());
    int cnt = nums[0] != 0;
    for (int i = 1; i <= nums.size(); i++) {
        if (i > nums[i - 1] && (i == nums.size() || i < nums[i])) {
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countWays({1, 1}) << endl;
    // 3
    cout << countWays({6, 0, 3, 3, 6, 7, 2, 7}) << endl;

    return 0;
}
