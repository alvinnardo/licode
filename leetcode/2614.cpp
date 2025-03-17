#include "../template/head.h"
#include <bits/stdc++.h>

int diagonalPrime(vector<vector<int>> nums) {
    // 思路：素筛
    // 时间 O(n + klogk)
    int end = 4e6;
    vector<int> vec(end + 2, 1);
    vec[0] = 0;
    vec[1] = 0;
    for (int i = 2; i < sqrt(end); i++) {
        if (vec[i]) {
            for (int j = i * i; j < vec.size(); j += i) {
                vec[j] = 0;
            }
        }
    }

    int maxv = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int t = nums[i][i];
        if (vec[t]) {
            maxv = max(maxv, t);
        }

        t = nums[i][nums.size() - i - 1];
        if (vec[t]) {
            maxv = max(maxv, t);
        }
    }

    return maxv == INT_MIN ? 0 : maxv;
}

int main(int argc, char *argv[]) {
    // 11
    cout << diagonalPrime({{1, 2, 3}, {5, 6, 7}, {9, 10, 11}}) << endl;
    // 17
    cout << diagonalPrime({{1, 2, 3}, {5, 17, 7}, {9, 11, 10}}) << endl;

    return 0;
}
