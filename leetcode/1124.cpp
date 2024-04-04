#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int longestWPI(vector<int> hours) {
    // 这道题难在问题转换
    // 1. 将 > 8 的转化为 1，<= 8 转换为 -1
    //    问题转化为 > 0 的区间值的最大长度
    // 2. 用前缀和可以计算区间值
    // 3. 用单调栈保存位置

    int sz = hours.size();
    // hours[i] 到 hours[j] 的和，是 psum[j] - psum[i-1]
    vector<int> psum(sz + 1);

    stack<int> st;
    st.push(0);
    for (int i = 1; i < sz + 1; i++) {
        psum[i] = psum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
        if (st.empty() || psum[i] < psum[st.top()]) {
            st.push(i);
        }
    }
    // 先都压栈，然后倒序遍历
    int res = 0;
    for (int i = sz; i; i--) {
        // 从后往前，大的数把可能区间都处理了，中间的小值就不会再改变结果
        while (!st.empty() && psum[i] > psum[st.top()]) {
            res = max(res, i - st.top());
            st.pop();
        }
    }

    printVector(psum);
    return res;
}

int main(void) {
    cout << longestWPI({9, 9, 6, 0, 6, 6, 9}) << endl;
    cout << longestWPI({6, 6, 6}) << endl;

    return 0;
}
