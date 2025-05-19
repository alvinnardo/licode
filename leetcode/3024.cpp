#include "../template/head.h"
#include <bits/stdc++.h>

string triangleType(vector<int> nums) {
    // 思路：模拟
    // 时间 O(1)，空间 O(1)
    sort(nums.begin(), nums.end());
    if (nums[0] + nums[1] <= nums[2]) {
        return "none"; // 最小的两条边和需要大于第三条边
    }
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
        return "equilateral";
    }
    if (nums[0] == nums[1] || nums[1] == nums[2]) {
        return "isosceles";
    }

    return "scalene";
}

int main(int argc, char *argv[]) {
    // "equilateral"
    cout << triangleType({3, 3, 3}) << endl;
    // "scalene"
    cout << triangleType({3, 4, 5}) << endl;

    return 0;
}
