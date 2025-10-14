#include "../template/head.h"
#include <bits/stdc++.h>

bool hasIncreasingSubarrays(vector<int> &&nums, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 记录连续两个递增串的长度
    int a{}, b{}, sz = nums.size(), dk = k << 1;
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            b = 1;
        } else if (nums[i] - nums[i - 1] > 0) {
            b++;
        } else {
            a = b;
            b = 1;
        }

        // 如果连续递增个数大于等于 2*k 也成立
        if (b >= dk || a >= k && b >= k) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // 1
    cout << hasIncreasingSubarrays({2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3) << endl;
    // 0
    cout << hasIncreasingSubarrays({1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 5) << endl;
    // 1
    cout << hasIncreasingSubarrays({-15, 9}, 1) << endl;

    return 0;
}
