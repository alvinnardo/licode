#include "../template/head.h"
#include <bits/stdc++.h>

int checkRecord(int n) {
    // 思路：DP + 矩阵快速幂
    // 时间 O(lognk)，空间 O(k)，k 为状态个数
    /* 状态转移矩阵为
         0 1 2 3 4 5 6
       0 1 1 0 1 0 0 0
       1 1 0 1 1 0 0 0
       2 1 0 0 1 0 0 0
       3 0 0 0 0 1 1 0
       4 0 0 0 0 1 1 0
       5 0 0 0 0 1 0 1
       6 0 0 0 0 1 0 0
     */
    if (n == 1) {
        return 3;
    }

    const int k = 7;
    const int mod = 1e9 + 7;
    vector<int> state = {1, 1, 0, 1, 0, 0, 0};
    vector<vector<int>> trans = {{1, 1, 0, 1, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0},
                                 {1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0},
                                 {0, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 1, 0, 1},
                                 {0, 0, 0, 0, 1, 0, 0}};

    vector<vector<int>> tmp(k, vector<int>(k));
    auto multipy2 = [&](const vector<vector<int>> &mat1,
                        const vector<vector<int>> &mat2) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int t = 0;
                for (int p = 0; p < k; p++) {
                    t = ((long long)mat1[i][p] * mat2[p][j] + t) % mod;
                }
                tmp[i][j] = t;
            }
        }
    };

    vector<vector<int>> sum;
    int t = n - 1;
    while (t) {
        if (t & 1) {
            if (sum.empty()) {
                sum = trans;
            } else {
                multipy2(sum, trans);
                sum = tmp;
            }
        }

        multipy2(trans, trans);
        trans = tmp;
        t >>= 1;
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        long long t = 0;
        for (int j = 0; j < k; j++) {
            t += (long long)state[j] * sum[j][i];
            t %= mod;
        }

        res = (t + res) % mod;
    }

    return res;
}

int checkRecord1(int n) {
    // 思路：DP，状态转移
    // 时间 O(nk)，空间 O(k)，k 为状态个数

    // 定义 k 种状态
    // 状态 0: A = 0，以 P 为结尾的个数
    // 状态 1: A = 0，以 L 结尾 且 为 1 的个数
    // 状态 2: A = 0，以 L 结尾 且 为 2 的个数
    // 状态 3：A = 1，以 A 为结尾的个数
    // 状态 4: A = 1，以 P 为结尾的个数
    // 状态 5: A = 1，以 L 结尾 且 为 1 的个数
    // 状态 6: A = 1，以 L 结尾 且 为 2 的个数

    // 状态转移
    // 0 --A--> 3; 0 --L--> 1; 0 --P--> 0
    // 1 --A--> 3; 1 --L--> 2; 1 --p--> 0
    // 2 --A--> 3; 2 --L--> x; 2 --p--> 0
    // 3 --A--> x; 3 --L--> 5; 3 --p--> 4
    // 4 --A--> x; 4 --L--> 5; 4 --p--> 4
    // 5 --A--> x; 5 --L--> 6; 5 --p--> 4
    // 6 --A--> x; 6 --L--> x; 6 --p--> 4

    const int k = 7;
    const int mod = 1e9 + 7;
    vector<int> state = {1, 1, 0, 1, 0, 0, 0};

    for (int i = 1; i < n; i++) {
        vector<int> tmp_state(k);
        tmp_state[0] = ((long long)state[0] + state[1] + state[2]) % mod;
        tmp_state[1] = state[0];
        tmp_state[2] = state[1];
        tmp_state[3] = ((long long)state[0] + state[1] + state[2]) % mod;
        tmp_state[4] =
            ((long long)state[3] + state[4] + state[5] + state[6]) % mod;
        tmp_state[5] = ((long long)state[3] + state[4]) % mod;
        tmp_state[6] = state[5];

        state = tmp_state;
    }

    long long sum = 0;
    for (int i : state) {
        sum = (sum + i) % mod;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 8
    cout << checkRecord(2) << endl;
    // 3
    cout << checkRecord(1) << endl;
    // 183236316
    cout << checkRecord(10101) << endl;

    return 0;
}
