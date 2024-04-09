#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

int maximumCount(vector<int> nums) {
    // 两次二分
    // 大于等于 0 和 大于 0
    return max(
        (int)(lower_bound(nums.begin(), nums.end(), 0) - nums.begin()),
        (int)nums.size() -
            (int)(upper_bound(nums.begin(), nums.end(), 0) - nums.begin()));
}

int main(void) {
    cout << maximumCount({-2, -1, -1, 1, 2, 3}) << endl;
    cout << maximumCount({-3, -2, -1, 0, 0, 1, 2}) << endl;
    cout << maximumCount({5, 20, 66, 1314}) << endl;
    cout << maximumCount({-2, -1, -1}) << endl;
    cout << maximumCount({3, 3, 3, 3, 3, 3, 3}) << endl;
    cout << maximumCount({0, 0, 0, 0, 0}) << endl;

    return 0;
}
