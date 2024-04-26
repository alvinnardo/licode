#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    // 思路：一眼单调栈，当出现更小的数字时，可以将之前大的弹出
    // 如果最后全递增，那么弹出最大值
    // 最后输出结果时，处理前导0

    // 时间 O(n), 空间 O(n)
    int sz = num.size();
    stack<char> st;
    for (int i = 0; i < sz; i++) {
        auto c = num[i];
        while (k && !st.empty() && c < st.top()) {
            st.pop();
            k--;
        }

        st.push(c);
    }

    // 单调栈中全是非递减的
    while (k) {
        st.pop();
        k--;
    }

    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // 去掉结尾 0
    while (!res.empty() && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

int main(void) {
    // 1219
    cout << removeKdigits("1432219", 3) << endl;
    // 1
    cout << removeKdigits("10200", 1) << endl;
    // 2
    cout << removeKdigits("10", 2) << endl;
    return 0;
}
