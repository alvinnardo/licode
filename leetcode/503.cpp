#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> nextGreaterElements(vector<int> nums) {
    // 思路：单调栈
    // 时间 O(n), 空间 O(n)
    // 先从倒数第二个到第一个元素初始化单调栈，然后从后往前处理每个元素
    int sz = nums.size();
    stack<int> st;
    for (int i = sz - 2; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        st.emplace(nums[i]);
    }

    vector<int> res(sz);
    for (int i = sz - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.emplace(nums[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2,-1,2}
    printVector(nextGreaterElements({1, 2, 1}));
    // {2,3,4,-1,4}
    printVector(nextGreaterElements({1, 2, 3, 4, 3}));

    return 0;
}
