#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> sumZero(int n) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    vector<int> res;
    for (int i = 1; i <= (n >> 1); i++) {
        res.push_back(i);
        res.push_back(-i);
    }
    if (n & 1) {
        res.push_back(0);
    }

    return res;
}

int main(int argc, char *argv[]) {
    cout << sumZero(5) << endl;
    cout << sumZero(3) << endl;
    cout << sumZero(1) << endl;

    return 0;
}
