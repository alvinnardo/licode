#include "../template/head.h"
#include <bits/stdc++.h>

long long minimumSteps(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int len = s.length();
    int span = 0;
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            sum += i - span;
            span++;
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumSteps("101") << endl;
    // 2
    cout << minimumSteps("100") << endl;

    return 0;
}
