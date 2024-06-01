#include "../template/head.h"
#include <bits/stdc++.h>

long long distributeCandies(int n, int limit) {
    // 题解：容斥原理
    // 所有可能方案数 - 至少一个超过 limit + 至少两个超过 limit - 至少三个超过
    // limit 插板法：n 个数 + 2 个板子，选取两个板子的位置 时间 O(1)，空间 O(1)

    // 计算 C(n, 2)
    auto C = [](long long t) -> long long {
        return t > 1 ? t * (t - 1) / 2 : 0;
    };

    return C(n + 2) - 3 * C(n - (limit + 1) + 2) +
           3 * C(n - (limit * 2 + 2) + 2) - C(n - (limit * 3 + 3) + 2);
}

long long distributeCandies_my(int n, int limit) {
    // 思路：先判断能否成立，然后第一个值，判断第二个的取值范围
    // 时间 O(min(n, limit))，空间 O(1)
    if (limit * 3 < n) {
        return 0;
    }

    long long cnt = 0;
    for (int i = 0; i <= min(n, limit); i++) {

        // 剩下的太多，分不完
        if (n - i > limit * 2) {
            continue;
        }

        // 剩下两人分 n - i 个
        // 最多拿看数量和上限，最少拿看下限和对方的上限
        // 第二个最多拿 min(n - i, limit)，最少拿 max(0, n - i - limit)
        cnt += min(n - i, limit) - max(0, n - i - limit) + 1;
    }

    return cnt;
}

int main(int argc, char *argv[]) {

    // 3
    cout << distributeCandies(5, 2) << endl;

    // 10
    cout << distributeCandies(3, 3) << endl;

    return 0;
}
