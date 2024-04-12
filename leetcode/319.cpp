#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// O(logn)
int bulbSwitch_my(int n) {
    // 找规律
    // 0: 0
    // 1~(1 + 2): 1
    // 4~(4 + 4): 2
    // 9~(9 + 6): 3

    if (n == 0) {
        return 0;
    }

    int cnt = 0;
    int sum = 0;
    for (int i = 3; sum < n; i += 2) {
        sum += i;
        cnt++;
    }

    return cnt;
}

int bulbSwitch(int n) {
    // 题解: 本质上就是求平方根
    return sqrt(n + 0.5);
}

int main(void) {
    for (int i = 0; i < 100; i++) {
        cout << i << ": " << bulbSwitch(i) << endl;
    }
    cout << 1000000000 << ": " << bulbSwitch(1000000000) << endl;
    return 0;
}
