#include "../template/head.h"
#include <bits/stdc++.h>

int monotoneIncreasingDigits(int n) {
    // 思路：单调栈
    // 栈内从顶到底广义递增
    // 时间 O(k)，空间 O(k)，k 是 n 的数字位数
    vector<int> st;
    int res = 0;
    while (n) {
        int t = n % 10;
        n /= 10;
        if (!st.empty() && t > st.back()) {
            for (int i = st.size() - 1; i >= 0; i--) {
                if (st[i] == 9) {
                    break;
                }
                st[i] = 9;
            }
            st.push_back(t - 1);
        } else {
            st.push_back(t);
        }
    }

    for (int i = st.size() - 1; i >= 0; i--) {
        res = res * 10 + st[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 9
    cout << monotoneIncreasingDigits(10) << endl;
    // 1234
    cout << monotoneIncreasingDigits(1234) << endl;
    // 299
    cout << monotoneIncreasingDigits(332) << endl;

    return 0;
}
