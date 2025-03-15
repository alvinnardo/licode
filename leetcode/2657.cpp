#include "../template/head.h"
#include <bits/stdc++.h>
#include <stdio.h>
vector<int> findThePrefixCommonArray(vector<int> A, vector<int> B) {
    // 题解：位运算
    // 灵神的位运算太 6 了
    vector<int> res(A.size());
    long long p = 0, q = 0;
    for (int i = 0; i < A.size(); i++) {
        p |= (1LL << A[i]);
        q |= (1LL << B[i]);
        // 注意这里用 __builtin_popcountl 或 __builtin_popcountll，
        // GCC 编译器中自带的函数
        // __builtin_popcount 32 位，
        // __builtin_popcountl 64 位，
        // __builtin_popcountll 128 位
        res[i] = __builtin_popcountll(p & q); // 个数
    }
    return res;
}

vector<int> findThePrefixCommonArray2(vector<int> A, vector<int> B) {
    // 思路：位运算
    // 时间 O(n)，空间 O(1)
    // 看了题解，发现数据量很小，50 可以用位运算简化

    vector<int> res;
    long long posa = 0, posb = 0;
    int pre = 0;
    for (int i = 0; i < A.size(); i++) {
        posa |= ((long long)1 << A[i]);
        posb |= ((long long)1 << B[i]);
        if (A[i] == B[i]) {
            res.push_back(pre + 1);
        } else {
            res.push_back(pre + ((posa >> B[i]) & 1) + ((posb >> A[i]) & 1));
        }
        pre = res.back();
    }

    return res;
}

vector<int> findThePrefixCommonArray1(vector<int> A, vector<int> B) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    // 先放，然后看是否在对方的前缀里
    // 用数组优化一下
    vector<int> res(A.size()), posa(A.size() + 1), posb(B.size() + 1);
    posa[A[0]] = 1;
    posb[B[0]] = 1;
    res[0] = A[0] == B[0];
    for (int i = 1; i < A.size(); i++) {
        posa[A[i]] = 1;
        posb[B[i]] = 1;
        if (A[i] == B[i]) {
            res[i] = res[i - 1] + 1;
        } else { // 不同，则看是否在对方的前缀中出现过
            res[i] = res[i - 1] + (posa[B[i]]) + (posb[A[i]]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,2,3,4}
    printVector(findThePrefixCommonArray({1, 3, 2, 4}, {3, 1, 2, 4}));
    // {0,1,3}
    printVector(findThePrefixCommonArray({2, 3, 1}, {3, 1, 2}));

    return 0;
}
