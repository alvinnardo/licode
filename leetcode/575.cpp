#include "../template/head.h"
#include <bits/stdc++.h>

int distributeCandies(vector<int> candyType) {
    // 思路：哈希表
    // 时间: O(n)，空间 O(n)
    unordered_set<int> uset;
    int sz = candyType.size(), n = candyType.size() >> 1;
    for (int i = 0; i < candyType.size(); i++) {
        uset.insert(candyType[i]);
        if (uset.size() == n) {
            return n;
        }
    }

    return uset.size();
}

int main(int argc, char *argv[]) {
    // 3
    cout << distributeCandies({1, 1, 2, 2, 3, 3}) << endl;
    // 2
    cout << distributeCandies({1, 1, 2, 3}) << endl;
    // 1
    cout << distributeCandies({6, 6, 6, 6}) << endl;

    return 0;
}
