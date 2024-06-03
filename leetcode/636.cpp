#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> exclusiveTime(int n, vector<string> logs) {
    // 思路：栈模拟
    // 时间 O(n)，空间 O(n)
    /* clang-format off */
    // 0：开始时间，0: 时间戳，1：间隔
    // 有个用例有问题，需要记录开始的标识符
    // {"1:start:0", "0:start:2", "1:start:3", "2:start:4", "2:end:4", "0:end:6", "1:end:7", "1:end:8"}
    // 不用记录标识符和开始结束，因为 end 肯定能遇到 start
    /* clang-format on */
    vector<int> res(n);
    stack<vector<int>> st;
    for (auto &log : logs) {
        bool first_colon = false, second_colon = false;
        string a, b, c;
        for (int i = 0; i < log.length(); i++) {
            if (!first_colon) {
                if (log[i] == ':') {
                    first_colon = true;
                } else {
                    a += log[i];
                }
            } else if (!second_colon) {
                if (log[i] == ':') {
                    second_colon = true;
                } else {
                    b += log[i];
                }
            } else {
                c += log[i];
            }

            if (i == log.length() - 1) {
                if (b == "start") {
                    st.push({atoi(a.c_str()), atoi(c.c_str()), 0});
                } else {
                    auto p = st.top();
                    st.pop();

                    int span = atoi(c.c_str()) - p[1] + 1;
                    res[p[0]] += span - p[2];

                    if (!st.empty()) {
                        st.top()[2] += span;
                    }
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,4}
    printVector(
        exclusiveTime(2, {"0:start:0", "1:start:2", "1:end:5", "0:end:6"}));
    // {8}
    printVector(exclusiveTime(1, {"0:start:0", "0:start:2", "0:end:5",
                                  "0:start:6", "0:end:6", "0:end:7"}));
    // {7,1}
    printVector(exclusiveTime(2, {"0:start:0", "0:start:2", "0:end:5",
                                  "1:start:6", "1:end:6", "0:end:7"}));
    // {2, 6, 1}
    printVector(
        exclusiveTime(3, {"1:start:0", "0:start:2", "1:start:3", "2:start:4",
                          "2:end:4", "0:end:6", "1:end:7", "1:end:8"}));

    return 0;
}
