#include "../template/head.h"
#include <bits/stdc++.h>

// 题解给出矩阵快速幂解法，下次复习时用该算法解题
int knightDialer(int n) {
    // 思路：DP
    // 时间 O(nk)，空间 O(k)
    const int mod = 1e9 + 7;

    vector<vector<int>> jump{{4, 6}, {8, 6},    {7, 9}, {4, 8}, {3, 9, 0},
                             {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
    vector<int> mov(10, 1);
    for (int i = 0; i < n - 1; i++) {
        vector<int> tmp = mov;
        for (int j = 0; j < 10; j++) {
            long long t = 0;
            for (int k : jump[j]) {
                t = (t + mov[k]) % mod;
            }
            tmp[j] = t;
        }
        mov = tmp;
    }

    long long res = 0;
    for (int i : mov) {
        res = (res + i) % mod;
    }
    return res;
}

int main(int argc, char *argv[]) {
    // 10
    cout << knightDialer(1) << endl;
    // 20
    cout << knightDialer(2) << endl;
    // 46
    cout << knightDialer(3) << endl;
    // 136006598
    cout << knightDialer(3131) << endl;

    return 0;
}
