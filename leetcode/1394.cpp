#include "../template/head.h"
#include <bits/stdc++.h>

int findLucky(vector<int> &&arr) {
    // 思路：红黑树
    // 时间 O(n + klogk)，空间 O(k)
    map<int, int> mm;
    for (int i = 0; i < arr.size(); i++) {
        mm[arr[i]]++;
    }

    int res = -1;
    for (auto &t : mm) {
        if (t.first == t.second) {
            res = t.first;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 2
    cout << findLucky({2, 2, 3, 4}) << endl;
    // 3
    cout << findLucky({1, 2, 2, 3, 3, 3}) << endl;
    // -1
    cout << findLucky({2, 2, 2, 3, 3}) << endl;
    // -1
    cout << findLucky({5}) << endl;
    // 7
    cout << findLucky({7, 7, 7, 7, 7, 7, 7}) << endl;

    return 0;
}
