#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findMissingAndRepeatedValues(vector<vector<int>> grid) {
    // 思路：用原数组标记找到多的那个数字
    // 求数组总和，再求得 1 到 n2 的总和，相减就是多的 - 少的
    // 时间 O(n2)，空间 O(1)
    int n = grid.size(), sum = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = grid[i][j] % 10000;
            sum += t;
            t--;
            int row = t / n, col = t % n;
            if (grid[row][col] > 10000) {
                a = t + 1;
            } else {
                grid[row][col] += 10000;
            }
        }
    }

    return {a, a - sum + (1 + n * n) * (n * n) / 2};
}

int main(int argc, char *argv[]) {
    // [9,5]
    printVector(
        findMissingAndRepeatedValues({{1, 3, 4}, {2, 6, 7}, {8, 9, 9}}));
    // {2,4}
    printVector(findMissingAndRepeatedValues({{1, 3}, {2, 2}}));

    return 0;
}
