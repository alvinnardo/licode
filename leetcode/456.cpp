#include "../template/head.h"
#include <bits/stdc++.h>

bool find132pattern(vector<int> nums) {
    int sz = nums.size();
    if (sz < 3) {
        return false;
    }

    // 思路：保存每个元素前面小于它的最小值，后面小于它的最大值
    // 如果前小值和后大值都小于它，且前小值小于后大值，则成立
    // 前面最小值可以直接求最小，后面小于它的最大值用单调栈求
    // 从后往前判断后面小于它的最大值，如果不能满足，就需要找更大的波峰，
    // 所以单调栈要保留大的值
    // 时间 O(n)，空间 O(n)
    vector<int> min_dp(sz, INT_MAX);
    for (int i = 1; i < sz; i++) {
        min_dp[i] = min(min_dp[i - 1], nums[i - 1]);
    }

    stack<int> st;
    for (int i = sz - 1; i >= 0; i--) {
        if (st.empty()) {
            st.push(nums[i]);
            continue;
        }

        int t = INT_MAX;
        while (!st.empty() && st.top() < nums[i]) {
            t = st.top();
            st.pop();
        }

        st.push(nums[i]);

        if (t != INT_MAX && min_dp[i] < nums[i] && min_dp[i] < t) {
            return true;
        }
    }
    // printVector(min_dp);

    return false;
}

int main(int argc, char *argv[]) {
    // f
    cout << find132pattern({1, 2, 3, 4}) << endl;
    // t
    cout << find132pattern({3, 1, 4, 2}) << endl;
    // t
    cout << find132pattern({-1, 3, 2, 0}) << endl;

    return 0;
}
