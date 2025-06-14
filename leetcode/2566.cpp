#include "../template/head.h"
#include <bits/stdc++.h>

int minMaxDifference(int num) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(logn)

    // 最大值替换最开始不是 9 的数字
    // 最小值替换开头的数字
    vector<int> s1, s2;
    int t = 0;
    while (num) {
        t = num % 10;
        num /= 10;
        s1.push_back(t);
        s2.push_back(t);
    }

    int pos = s1.size() - 1;
    bool find = false;
    while (pos >= 0) {
        if (find) {
            if (s1[pos] == t) {
                s1[pos] = 9;
            }
        } else if (s1[pos] != 9) {
            find = true;
            t = s1[pos];
            s1[pos] = 9;
        }

        num = num * 10 + s1[pos];
        pos--;
    }

    t = s2.back();
    int num2 = 0;
    for (int i = s2.size() - 1; i >= 0; i--) {
        if (s2[i] == t) {
            s2[i] = 0;
        }

        num2 = num2 * 10 + s2[i];
    }

    return num - num2;
}

int main(int argc, char *argv[]) {
    // 99009
    cout << minMaxDifference(11891) << endl;
    // 99
    cout << minMaxDifference(90) << endl;

    return 0;
}
