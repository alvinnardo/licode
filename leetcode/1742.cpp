#include "../template/head.h"
#include <bits/stdc++.h>

int countBalls(int lowLimit, int highLimit) {
    // 思路：哈希表 + 模拟
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    int maxv = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        int sum = 0, t = i;
        while (t) {
            sum += t % 10;
            t /= 10;
        }
        umap[sum]++;
        maxv = max(maxv, umap[sum]);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countBalls(1, 10) << endl;
    // 2
    cout << countBalls(5, 15) << endl;
    // 2
    cout << countBalls(19, 28) << endl;

    return 0;
}
