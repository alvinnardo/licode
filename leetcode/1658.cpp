#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int left = 0, right = 0;

    // 滑动窗口
    auto minOperations = [&](const vector<int> &nums, int x) -> int {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int target = tot - x;
        int sz = nums.size();

        int l = 0, r = 0;
        int sum = 0;
        int max_len = INT_MIN;
        while (r < sz) {
            sum += nums[r++];
            while (sum > target && l < r) {
                sum -= nums[l++];
            }
            if (sum == target) {
                max_len = max(max_len, r - l);
            }
        }

        return max_len == INT_MIN ? -1 : sz - max_len;
    };

    cout << minOperations({1, 1, 4, 2, 3}, 5) << endl; // 2
    cout << minOperations({3, 2, 20, 1, 1, 3}, 10) << endl; // 5
    cout << minOperations({5, 6, 7, 8, 9}, 4) << endl; // -1
    cout << minOperations({9,4}, 4) << endl; // 1
    cout << minOperations({2,3,1,1,1}, 5) << endl; // 2
    cout << minOperations({10,3,20,30,40}, 100) << endl; // 4
    cout << minOperations({1,1,3,2,5}, 5) << endl; // 1
    cout << minOperations({9,3,3,3}, 9) << endl; // 1
    cout << minOperations({1,1}, 3) << endl; // 1

    return 0;
}
