#include "../template/head.h"
#include <bits/stdc++.h>

int minimumSum(int n, int k) {
    // 题解：贪心 + 数学
    // 时间 O(1)，空间 O(1)

    // 1 + (k - 1) 选小的，就是 1
    // 2 + (k - 2) 选小的，就是 2
    // 以此类推，直到选到 k / 2，一个小于 k / 2，一个大于 k / 2
    // 每次选的是小于 k / 2 的

    // 奇偶分开讨论
    // 偶数 1 2 3 .. k/2     k k+1 k+2 ...
    // 奇数 1 2 3 .. k/2     k k+1 k+2 ...
    // 发现都相同，都是等差数列，可以直接计算

    int m = min(n, k / 2);
    return (m * (1 + m) + (n - m - 1 + (k << 1)) * (n - m)) >> 1;
}

int minimumSum1(int n, int k) {
    // 思路：贪心 + 哈希表
    // 时间 O(n)，空间 O(n)
    int cnt = 0;
    int num = 1;
    int res = 0;
    vector<int> uset(k + 1); // 用 vector 优化时间
    while (cnt < n) {
        if (num < k) {
            if (!uset[num]) {
                uset[k - num] = 1;
                res += num;
                cnt++;
            }
        } else {
            res += num;
            cnt++;
        }
        num++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 18
    cout << minimumSum(5, 4) << endl;
    // 3
    cout << minimumSum(2, 6) << endl;

    return 0;
}
