#include "../template/head.h"
#include <bits/stdc++.h>

int lengthAfterTransformations(string s, int t) {
    // 思路：矩阵快速幂
    // 时间 O(k^3 * logt)，空间 O(k2)，k = 26

    int len = s.length(), k = 26;
    constexpr int mod = 1e9 + 7;
    vector<vector<int>> down(1, vector<int>(k));
    for (int i = 0; i < len; i++) {
        down[0][s[i] - 'a']++;
    }

    vector<vector<int>> trans(k, vector<int>(k));
    for (int i = 0; i < k - 1; i++) {
        trans[i][i + 1] = 1;
    }
    trans[k - 1][0] = trans[k - 1][1] = 1; // z -> ab

    // 矩阵乘法
    auto matrix_mul = [](const vector<vector<int>> &a,
                         const vector<vector<int>> &b) {
        int m = a.size(), n = b[0].size(), c = a[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < c; j++) {
                long long t = 0;
                for (int k = 0; k < n; k++) {
                    res[i][k] = ((long long)res[i][k] +
                                 ((long long)a[i][j] * b[j][k]) % mod) %
                                mod;
                }
            }
        }

        return res;
    };

    vector<vector<int>> E(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        E[i][i] = 1;
    }

    while (t) {
        if (t & 1) {
            E = matrix_mul(E, trans);
        }
        trans = matrix_mul(trans, trans);
        t >>= 1;
    }

    down = matrix_mul(down, E);
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum = (sum + down[0][i]) % mod;
    }

    return sum;
}

int lengthAfterTransformations1(string s, int t) {
    // 思路：哈希表
    // 时间 O(n + kt)，空间 O(k)，k = 26
    int len = s.length(), k = 26;
    constexpr int mod = 1e9 + 7;

    vector<int> up(k), down(k);
    for (int i = 0; i < len; i++) {
        down[s[i] - 'a']++;
    }

    // 模拟每时刻
    for (int i = 1; i <= t; i++) {
        up = down;
        for (int j = 0; j < k; j++) {
            down[j] = 0;
        }
        for (int j = 0; j < k; j++) {
            if (j < k - 1) {
                down[j + 1] = up[j];
            } else {
                down[0] = up[j];
                down[1] = ((long long)down[1] + up[j]) % mod;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum = (sum + down[i]) % mod;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    // 7
    cout << lengthAfterTransformations("abcyy", 2) << endl;
    // 5
    cout << lengthAfterTransformations("azbk", 1) << endl;

    return 0;
}
