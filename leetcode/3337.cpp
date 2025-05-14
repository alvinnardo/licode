#include "../template/head.h"
#include <bits/stdc++.h>

int lengthAfterTransformations(string s, int t, vector<int> nums) {
    // 思路：矩阵快速幂
    // 时间 O(np + k^3logt), 空间 O(k^2)
    // p 是 nums[i] 的平均值，k = 26

    constexpr int k = 26;
    constexpr int mod = 1e9 + 7;
    int sz = nums.size();
    vector<vector<int>> trans(k, vector<int>(k));
    for (int i = 0; i < sz; i++) {
        int t = i;
        for (int j = 0; j < nums[i]; j++) {
            t = (t + 1) % k;
            trans[i][t] = 1;
        }
    }

    // 左乘右，结果保存在左中
    vector<vector<int>> tmp(k, vector<int>(k));
    auto matrixMul = [&](auto &ma, const auto &mb) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (ma[i][j] == 0) {
                    continue;
                }

                for (int p = 0; p < k; p++) {
                    tmp[i][p] = ((long long)tmp[i][p] +
                                 (long long)ma[i][j] * mb[j][p]) %
                                mod;
                }
            }
        }

        // 从 tmp 拿结果，并清空 tmp
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                ma[i][j] = tmp[i][j];
                tmp[i][j] = 0;
            }
        }
    };

    // E
    vector<vector<int>> sum(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        sum[i][i] = 1;
    }

    while (t) {
        if (t & 1) {
            matrixMul(sum, trans);
        }

        t >>= 1;
        if (t) {
            matrixMul(trans, trans);
        }
    }

    // 获取初始数组
    vector<int> vec(26);
    for (int i = 0; i < s.length(); i++) {
        vec[s[i] - 'a']++;
    }

    // 初始数组乘累乘结果，注意是 sum 不是 trans
    long long res = 0;
    for (int i = 0; i < k; i++) {
        if (vec[i] == 0) {
            continue;
        }

        for (int j = 0; j < k; j++) {
            res = (res + (long long)vec[i] * sum[i][j]) % mod;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 472961
    cout << lengthAfterTransformations(
                "a", 5, {14, 23, 6,  9,  14, 15, 18, 15, 16, 17, 18, 11, 17,
                         2,  21, 24, 23, 2,  13, 21, 13, 7,  3,  6,  5,  18})
         << endl;
    // 7
    cout << lengthAfterTransformations("abcyy", 2,
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2})
         << endl;
    // 8
    cout << lengthAfterTransformations("azbk", 1,
                                       {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2})
         << endl;

    return 0;
}
