#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> getNoZeroIntegers(int n) {
    // 思路: 模拟
    // 时间 O(nlogn)，空间 O(1)

    auto check = [](int t) {
        while (t) {
            if (t % 10 == 0) {
                return false;
            }
            t /= 10;
        }
        return true;
    };

    for (int i = 1; i < n; i++) {
        if (check(i) && check(n - i)) {
            return {i, n - i};
        }
    }

    return {};
}

int main(int argc, char *argv[]) {
    // {1, 1}
    cout << getNoZeroIntegers(2) << endl;
    // {2, 9}
    cout << getNoZeroIntegers(11) << endl;

    return 0;
}
