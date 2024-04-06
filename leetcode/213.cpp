#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 优化空间
int rob(vector<int> nums) {
    int sz = nums.size();
    if (sz == 1) {
        return nums.back();
    }

    int res = 0;
    int a = 0, b = nums[0];
    int c = 0, d = nums[1];
    for (int i = 2; i < sz; i++) {
        int m = max(a + nums[i - 1], b);
        int n = max(c + nums[i], d);
        a = b;
        b = m;

        c = d;
        d = n;
    }
    return max(b, d);
}

int rob2(vector<int> nums) {

    int sz = nums.size();
    if (sz == 1) {
        return nums.back();
    }

    vector<int> dp(sz);
    int res = 0;

    // 第一个偷，从 0 .. sz - 2
    // 第一个不偷，从 1 .. sz - 1
    dp[1] = nums[0];
    for (int i = 2; i < sz; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    res = dp[sz - 1];

    dp[1] = nums[1];
    for (int i = 2; i < sz; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return max(res, dp[sz - 1]);
}

int main(void) {
    cout << rob({1}) << endl;
    cout << rob({1, 2}) << endl;
    cout << rob({2, 3, 2}) << endl;
    cout << rob({1, 2, 3}) << endl;
    cout << rob({1, 2, 3, 1}) << endl;
    return 0;
}
