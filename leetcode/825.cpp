#include "../template/head.h"
#include <bits/stdc++.h>

int numFriendRequests(vector<int> ages) {
    // 思路：哈希表 + 模拟
    // 时间 O(k2)，空间 O(k)
    int sz = 121;
    vector<int> vec(sz); // 0 - 120
    for (int age : ages) {
        vec[age]++;
    }

    int res = 0;
    for (int x = 1; x < sz; x++) {
        for (int y = 1; y < sz; y++) {
            if (!(y <= (x >> 1) + 7 || y > x || (y > 100 && x < 100))) {
                res += x == y ? vec[x] * (vec[x] - 1) : vec[x] * vec[y];
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << numFriendRequests({16, 16}) << endl;
    // 2
    cout << numFriendRequests({16, 17, 18}) << endl;
    // 3
    cout << numFriendRequests({20, 30, 100, 110, 120}) << endl;

    return 0;
}
