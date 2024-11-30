#include "../template/head.h"
#include <bits/stdc++.h>

bool canAliceWin(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int a = 0, b = 0;
    for (int num : nums) {
        a += num < 10 ? num : 0;
        b += num >= 10 ? num : 0;
    }

    return a != b;
}

int main(int argc, char *argv[]) {
    // 0
    cout << canAliceWin({1, 2, 3, 4, 10}) << endl;
    // 1
    cout << canAliceWin({1, 2, 3, 4, 5, 14}) << endl;
    // 1
    cout << canAliceWin({5, 5, 5, 25}) << endl;

    return 0;
}
