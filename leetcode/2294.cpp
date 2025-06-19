#include "../template/head.h"
#include <bits/stdc++.h>

int partitionArray(vector<int> &&nums, int k) {
    // 思路：排序 + 贪心
    // 时间 O(nlogn)，空间 O(logn)

    // 子序列则可以用集合的思想，先排序再从最小值开始选
    sort(nums.begin(), nums.end());
    int cnt = 0;
    int minv = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] - minv > k) {
            cnt++;
            minv = nums[i];
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << partitionArray({3, 6, 1, 2, 5}, 2) << endl;
    // 2
    cout << partitionArray({1, 2, 3}, 1) << endl;
    // 3
    cout << partitionArray({2, 2, 4, 5}, 0) << endl;

    return 0;
}
