#include "../template/head.h"
#include <bits/stdc++.h>

int countPartitions(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    int sum = reduce(nums.begin(), nums.end(), 0);
    int sz = nums.size();
    int pre{}, tail{sum};
    int res{};
    for (int i = 0; i < sz - 1; i++) {
        pre += nums[i];
        tail -= nums[i];
        res += !((tail - pre) & 1);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countPartitions({10, 10, 3, 7, 6}) << endl;
    // 0
    cout << countPartitions({1, 2, 2}) << endl;
    // 3
    cout << countPartitions({2, 4, 6, 8}) << endl;

    return 0;
}
