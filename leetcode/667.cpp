#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> constructArray(int n, int k) {
    // 思路：左边从大到小排序，差值为 1，右边交替构造
    // 时间: O(n)，空间 O(1)
    vector<int> res;
    for (int i = n; i >= k + 1; i--) { // 左边
        res.push_back(i);
    }

    // 右边放 k 个数
    int cnt = 0;
    int low = 1, up = k;
    bool put_low = true;
    while (cnt < k) {
        if (put_low) {
            res.push_back(low++);
            put_low = false;
        } else {
            res.push_back(up--);
            put_low = true;
        }
        cnt++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    printVector(constructArray(3, 1));
    printVector(constructArray(3, 2));
    printVector(constructArray(7, 4));

    return 0;
}
