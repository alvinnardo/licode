#include "../template/head.h"
#include <bits/stdc++.h>
bool judgeSquareSum(int c) {
    // 题解2：双指针
    // 两数相加的模式
    // 注意溢出
    // 时间 O(√n)，空间 O(1)
    long left = 0, right = sqrt(c);
    while (left <= right) {
        long sum = left * left + right * right;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

bool judgeSquareSum1(int c) {
    // 题解：枚举
    // 思路一样，判断的时候可以直接用 sqrt
    // 时间 O(√n)，空间 O(1)
    for (int i = 0; i <= sqrt(c); i++) { // 注意 0 也是，所以从 0 开始

        double b = sqrt(c - i * i);
        if (b == (int)b) { // 这里会将整形 b 转为 double 再比较
            return true;
        }
    }

    return false;
}

bool judgeSquareSum_my(int c) {
    // 思路：哈希表
    // 时间 O(√n)，空间 (√n)
    unordered_set<int> uset;
    uset.insert(0);
    for (int i = 0; i <= sqrt(c); i++) {
        int m = i * i;
        uset.insert(m);
        int rem = c - m;
        if (uset.count(rem)) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    cout << judgeSquareSum(0) << endl;
    cout << judgeSquareSum(1) << endl;
    cout << judgeSquareSum(3) << endl;
    cout << judgeSquareSum(9) << endl;
    cout << judgeSquareSum(INT_MAX) << endl;
    cout << INT_MAX << endl;

    return 0;
}
