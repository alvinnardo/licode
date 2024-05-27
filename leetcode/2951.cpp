#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findPeaks(vector<int> mountain) {
    // 思路：遍历
    // 时间 O(n)，时间 O(1)
    vector<int> res;
    int sz = mountain.size();
    for (int i = 1; i < sz - 1; i++) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
            res.push_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // []
    printVector(findPeaks({2, 4, 4}));
    // {1,3}
    printVector(findPeaks({1, 4, 3, 8, 5}));

    return 0;
}
