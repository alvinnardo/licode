#include <bits/stdc++.h>
using namespace std;

int minimumSum(const vector<int> &nums) {

    // 求每个位置前面和后面的最小值
    int res = INT_MAX;

    int sz = nums.size();
    vector<int> left(sz), right(sz);

    int left_minv = INT_MAX;
    for (int i = 0; i < sz; i++) {
        left[i] = left_minv;
        left_minv = min(left_minv, nums[i]);
    }

    int right_minv = INT_MAX;
    for (int i = sz - 1; i >= 0; i--) {
        right[i] = right_minv;
        right_minv = min(right_minv, nums[i]);
    }

    for (int i = 0; i < sz; i++) {
        if (left[i] < nums[i] && nums[i] > right[i]) {
            res = min(res, left[i] + nums[i] + right[i]);
        }
    }

    return res == INT_MAX ? -1 : res;
}

int main(void) {
    cout << minimumSum({8, 6, 1, 5, 3}) << endl;
    cout << minimumSum({5, 4, 8, 7, 10, 2}) << endl;
    cout << minimumSum({6, 5, 4, 3, 4, 5}) << endl;
    return 0;
}
