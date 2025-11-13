#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> &&nums) {
    // 思路：贪心
    // 时间 O(n2logn)，空间 O(1)
    // gcd 有 O(logn) 时间复杂度

    // 先检测是否有 1，如果有就能全变成 1
    int sz = nums.size();
    int one_cnt{};
    for (int i = 0; i < sz; i++) {
        one_cnt += (nums[i] == 1);
    }

    if (one_cnt > 0) {
        return sz - one_cnt;
    }

    // 遍历每个位置进行操作，找到出现 1 最少操作次数
    int min_cnt = INT_MAX;
    for (int i = 0; i < sz; i++) {
        int t = nums[i], cnt = 0;
        for (int j = i + 1; j < sz; j++) {
            ++cnt;
            t = gcd(t, nums[j]);
            if (t == 1) {
                min_cnt = min(min_cnt, cnt);
                break;
            }
        }
    }

    return min_cnt == INT_MAX ? -1 : sz + min_cnt - 1;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minOperations({2, 6, 3, 4}) << endl;
    // -1
    cout << minOperations({2, 10, 6, 14}) << endl;
    // 4
    cout << minOperations({6, 10, 15}) << endl;
    // 0
    cout << minOperations({1, 1}) << endl;

    return 0;
}
