#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfPoints(vector<vector<int>> nums) {
    // 思路：差分数组
    // 时间 O(n + k)，空间 O(k)
    int maxv = INT_MIN;
    for (auto &t : nums) {
        maxv = t[1] > maxv ? t[1] : maxv;
    }

    vector<int> vec(maxv + 2);
    for (auto &t : nums) {
        vec[t[0]]++;
        vec[t[1] + 1]--;
    }

    int cnt = 0;
    for (int i = 1; i < vec.size(); i++) {
        vec[i] += vec[i - 1];
        cnt += vec[i] > 0;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    // 7
    cout << numberOfPoints({{3, 6}, {1, 5}, {4, 7}}) << endl;
    // 7
    cout << numberOfPoints({{1, 3}, {5, 8}}) << endl;
    return 0;
}
