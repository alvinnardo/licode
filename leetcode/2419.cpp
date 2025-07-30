#include "../template/head.h"
#include <bits/stdc++.h>

int longestSubarray(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 位与，只有子数组中都是最大值才不会变小
    // 所以求连续最大值的最多个数
    int maxv = INT_MIN, maxv_cnt = 0, cnt = 0, last = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != last) {
            last = nums[i];
            cnt = 1;
        } else {
            cnt++;
        }

        if (nums[i] > maxv) {
            maxv = nums[i];
            maxv_cnt = cnt;
        } else if (nums[i] == maxv) {
            maxv_cnt = max(maxv_cnt, cnt);
        }
    }

    return maxv_cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << longestSubarray({1, 2, 3, 3, 2, 2}) << endl;
    // 1
    cout << longestSubarray({1, 2, 3, 4}) << endl;

    return 0;
}
