#include "../template/head.h"
#include <bits/stdc++.h>

int countOperations(int num1, int num2) {
    // 思路：数学
    // 时间 O(log(max(num1, num2)))，空间 O(1)
    // 中间如果能整除则优化一下

    // 辗转相除法，也叫欧几里得算法，用于求最大公约数
    // 时间复杂度是 log(max(num1, num2))
    // 每一步，至少一个值会减少一半
    int res{};
    while (num1 > 0 && num2 > 0) {
        if (num2 < num1) {
            swap(num1, num2);
        }

        res += num2 / num1;
        num2 %= num1;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countOperations(2, 3) << endl;
    // 1
    cout << countOperations(10, 10) << endl;

    return 0;
}
