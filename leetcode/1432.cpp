#include "../template/head.h"
#include <bits/stdc++.h>

int maxDiff(int num) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(logn)
    vector<int> s1, s2;
    int t = 0;
    while (num) {
        t = num % 10;
        num /= 10;
        s1.push_back(t);
        s2.push_back(t);
    }

    // 得到最大值，找到第一个不是 9 的
    t = -1;
    int num1 = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        if (t < 0 && s1[i] < 9) {
            t = s1[i];
        }

        num1 = num1 * 10 + (t < 0 ? s1[i] : (s1[i] == t ? 9 : s1[i]));
    }

    // 如果最高位是 1，那么后面找 > 0 的数进行替换成 0
    // 如果最高位 > 1，那么找 s2.back() 的数进行替换成 1
    t = -1;
    int alter = s2.back() > 1 ? 1 : 0;
    int num2 = 0;
    for (int i = s2.size() - 1; i >= 0; i--) {
        // 找 0 需要从倒数第二个开始 且 不能是 1
        // 因为如果替换 1，那开头的 1 就矛盾了
        // 所以直接找 > 1 的
        if (t < 0 && s2[i] > 1) {
            t = s2[i];
        }

        num2 = num2 * 10 + (t < 0 ? s2[i] : (s2[i] == t ? alter : s2[i]));
    }

    return num1 - num2;
}

int main(int argc, char *argv[]) {
    // 888
    cout << maxDiff(555) << endl;
    // 8
    cout << maxDiff(9) << endl;
    // 820000
    cout << maxDiff(123456) << endl;
    // 80000
    cout << maxDiff(10000) << endl;
    // 8700
    cout << maxDiff(9288) << endl;
    // 8800099
    cout << maxDiff(1100099) << endl;

    return 0;
}
