#include "../template/head.h"
#include <bits/stdc++.h>

long long countAlternatingSubarrays(vector<int> nums) {
    // 思路：统计
    // 时间 O(n)，空间 O(1)
    long long sum = 1, cnt = 1;
    int sz = nums.size();
    for (int i = 1; i < sz; i++) {
        if (nums[i] != nums[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }

        sum += cnt;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 5
    cout << countAlternatingSubarrays({0, 1, 1, 1}) << endl;
    // 10
    cout << countAlternatingSubarrays({1, 0, 1, 0}) << endl;
    return 0;
}
