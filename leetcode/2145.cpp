#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfArrays(vector<int> differences, int lower, int upper) {
    // 思路：前缀和
    // 时间 O(n)，空间 O(1)

    // 差分数组的前缀和为原数组
    // 令 原数组的第一个元素为 x
    // 遍历差分数组，求出原数组值的范围，并与 lower 和 upper 联立
    // 求得 x 范围

    // 10^5 个 10^5 可能超 int
    long long maxv = LLONG_MIN, minv = LLONG_MAX;
    int sz = differences.size();
    long long cur = 0;
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            maxv = minv = differences[i];
            cur = differences[i];
        } else {
            cur += differences[i];
            maxv = max(maxv, cur);
            minv = min(minv, cur);
        }
    }

    // 根据最大值和最小值求出了一个 x 的范围
    // x 也在 [lower, upper] 中，也是一个条件
    long long more_than = max((long long)lower, lower - minv),
              less_than = min((long long)upper, upper - maxv);

    return less_than < more_than ? 0 : less_than - more_than + 1;
}

int main(int argc, char *argv[]) {
    // 2
    cout << numberOfArrays({1, -3, 4}, 1, 6) << endl;
    // 4
    cout << numberOfArrays({3, -4, 5, 1, -2}, -4, 5) << endl;
    // 0
    cout << numberOfArrays({4, -7, 2}, 3, 6) << endl;
    // 60
    cout << numberOfArrays({-40}, -46, 53) << endl;

    return 0;
}
