#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findArray(vector<int> pref) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    for (int i = pref.size() - 1; i >= 1; i--) {
        pref[i] ^= pref[i - 1];
    }

    return pref;
}

int main(int argc, char *argv[]) {
    // {5,7,2,3,2}
    printVector(findArray({5, 2, 0, 3, 1}));
    // {13}
    printVector(findArray({13}));

    return 0;
}
