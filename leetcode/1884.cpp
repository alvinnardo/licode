#include "../template/head.h"
#include <bits/stdc++.h>

int twoEggDrop(int n) {
    // 思路：找规律
    // 时间 O(√n)，空间 O(1)
    // 第二个加数是倒序的，如果满了，则再开一行
    // 如 3(1+1, 2+0), 4(1+1, 2+1), 5(1+2, 2+1)
    // 6(1+2, 2+1, 3+0), 7(1+2, 2+1, 3+1), 8(1+2, 2+2, 3+1)
    // 9(1+3, 2+2, 3+1), 10(1+3, 2+2, 3+1, 4+0)
    int sum = 0, step = 0;
    while (sum < n) {
        sum += ++step;
    }

    return step;
}

int main(int argc, char *argv[]) {
    // 2
    cout << twoEggDrop(2) << endl;
    // 14
    cout << twoEggDrop(100) << endl;

    return 0;
}
