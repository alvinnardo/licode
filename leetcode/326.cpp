#include "../template/head.h"
#include <bits/stdc++.h>

bool isPowerOfThree(int n) {
    // 题解：数学
    // 时间 O(1)，空间 O(1)

    // 题目给出范围的 n 的最大可能值是 3^19 = 1162261467
    // 判断 n 是否是其的约数
    // 由于 3^19 是由 3 相乘得出，如果 n 中有非 3 的因子，则不能整除

    return n > 0 && 1162261467 % n == 0;
}

// 由于精度问题，解法错误
bool isPowerOfThree3(int n) {
    // 思路：数学
    // 时间 O(1)，空间 O(1)

    // 判断 log3(n) 是否为整数
    // log3(n) = log2(n) / log2(3)
    if (n <= 0) {
        return 0;
    }

    auto is_integer = [](double num) { return (int)num == num; };

    return is_integer(std::log2((double)n) / std::log2((double)3));
}

bool isPowerOfThree2(int n) {
    // 思路：哈希表
    // 时间 O(logn)，空间 O(logn)

    // 用数组替换哈希表，用二分查找
    vector<int> vec{1,        3,        9,         27,        81,
                    243,      729,      2187,      6561,      19683,
                    59049,    177147,   531441,    1594323,   4782969,
                    14348907, 43046721, 129140163, 387420489, 1162261467};
    return std::binary_search(vec.begin(), vec.end(), n);
}

bool isPowerOfThree1(int n) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)
    if (n == 0) {
        return 0;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}

int main(int argc, char *argv[]) {
    // 1
    cout << isPowerOfThree(27) << endl;
    // 0
    cout << isPowerOfThree(0) << endl;
    // 1
    cout << isPowerOfThree(9) << endl;
    // 0
    cout << isPowerOfThree(45) << endl;
    // 1
    cout << isPowerOfThree(1594323) << endl;

    return 0;
}
