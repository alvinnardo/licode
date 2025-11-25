#include "../template/head.h"
#include <bits/stdc++.h>

int smallestRepunitDivByK(int k) {
    // 思路：DP + 数学
    // 时间 O(p)，空间 O(1)，p 是测试次数

    // 1 % k
    // 10 % k = ((1 % k) * (10 % k)) % k
    // 100 % k = ((10 % k) * (10 % k)) % k
    // 1000 % k = ((100 % k) * (10 % k)) % k
    // 再用 sum 求和

    // 另一种思路：
    // 枚举 1 的个数，递推计算 (10x + 1) % k
    // 时间复杂度的分析：余数不能出现环，则根据鸽笼原理，时间复杂度为 O(k)
    // 循环测试 k 次即可

    // 只有 1 3 7 9 能乘出结尾为 1 的数
    unordered_set<char> uset{'1', '3', '7', '9'};
    if (!uset.count(to_string(k).back())) {
        return -1;
    }
    if (k == 1) {
        return 1;
    }

    int pre = 1, yu = 10 % k, sum = 1;
    int p = 100000;
    for (int i = 2; i < p + 2; i++) {
        pre = (pre * yu) % k;
        sum = (sum + pre) % k;
        if (sum == 0) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 1
    cout << smallestRepunitDivByK(1) << endl;
    // -1
    cout << smallestRepunitDivByK(2) << endl;
    // 3
    cout << smallestRepunitDivByK(3) << endl;

    return 0;
}
