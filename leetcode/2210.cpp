#include "../template/head.h"
#include <bits/stdc++.h>

int countHillValley(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    // 遍历一次
    int first = 0, second = 0, third = 0;
    int cnt = 0;

    while (nums[second] == nums[first]) {
        second++;
        if (second == nums.size()) {
            return cnt;
        }
    }

    third = second;
    while (nums[third] == nums[second]) {
        third++;
        if (third == nums.size()) {
            return cnt;
        }
    }

    while (third < nums.size()) {
        cnt += (nums[second] > nums[first] && nums[second] > nums[third]) ||
               (nums[second] < nums[first] && nums[second] < nums[third]);

        first = second;
        second = third;

        while (nums[third] == nums[second]) {
            third++;
            if (third == nums.size()) {
                return cnt;
            }
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countHillValley({2, 4, 1, 1, 6, 5}) << endl;
    // 0
    cout << countHillValley({6, 6, 5, 5, 4, 1}) << endl;

    return 0;
}
