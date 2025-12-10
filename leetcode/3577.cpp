#include "../template/head.h"
#include <bits/stdc++.h>

int countPermutations(vector<int> &&complexity) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 题目中给出的是编号为 0 的计算机已经解锁
    // 所以需要使用该计算机解锁后面的计算机
    // 如果后面的计算机有小于或等于的，就不能解开
    int sz = complexity.size();
    for (int i = 1; i < sz; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    // 后面可以任意排列
    // 排列的是位置，所以密码相同的位置是不同的，不需要去重
    // (n-1)!
    long long res{1};
    int mod = 1e9 + 7;
    for (int i = 1; i <= sz - 1; i++) {
        res = (res * i) % mod;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countPermutations({1, 2, 3}) << endl;
    // 0
    cout << countPermutations({3, 3, 3, 4, 4, 4}) << endl;

    return 0;
}
