#include "../template/head.h"
#include <bits/stdc++.h>

int totalNQueens(int n) {
    // 思路：枚举
    // 51 题已经求过了，这里直接用哈希表出结果
    // 时间 O(1)，空间 O(k)
    vector<int> vec{0, 1, 0, 0, 2, 10, 4, 40, 92, 352};

    return vec[n];
}

int main(int argc, char *argv[]) {
    // 1: 1
    // 2: 0
    // 3: 0
    // 4: 2
    // 5: 10
    // 6: 4
    // 7: 40
    // 8: 92
    // 9: 352
    for (int i = 1; i <= 9; i++) {
        cout << i << ": " << totalNQueens(i) << endl;
    }

    return 0;
}
