#include "../template/head.h"
#include <bits/stdc++.h>

int largestPerimeter(vector<int> &&nums) {
    // 思路：排序 + 贪心
    // 时间 O(nlogn)，空间 O(1)

    // 从后往前遍历，如果能成三角形肯定是最大的
    sort(nums.begin(), nums.end());
    int res{}, sz = nums.size();
    int c = sz - 3, b = sz - 2, a = sz - 1;
    while (c >= 0) {
        if (nums[c] + nums[b] > nums[a]) {
            res = nums[c] + nums[b] + nums[a];
            break;
        }
        c--, b--, a--;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << largestPerimeter({2, 1, 2}) << endl;
    // 0
    cout << largestPerimeter({1, 2, 1, 10}) << endl;

    return 0;
}
