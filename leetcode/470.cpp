#include "../template/head.h"
#include <bits/stdc++.h>
int rand7() { return rand() % 7 + 1; }

int rand10() {
    // 题解：拒绝采样
    // 把空隙撑大，再插入
    // rand7() 能随机产生 [1, 7]
    // rand7() - 1 能随机产生 [0, 6]
    // (rand7() - 1) * 7 能随机产生 {0, 7, 14, 21, 28, 35, 42}
    // (rand7() - 1) * 7 + rand7() 就能随机产生 [1, 49]
    while (true) {
        int t = (rand7() - 1) * 7 + rand7();
        if (t <= 40) { // 只要 40 个数
            return (t - 1) % 10 + 1;
        }
    }

    return 0;
}

int rand10_simple() {
    // 思路：拒绝采样，如果没选中，就一直尝试
    // 从所有可能中选取 10 个概率相同的数字，如果没在这些数字中，就再抽一次
    // 比如 rand7() + rand7()，数字不太均匀
    // 选择 rand7() * rand7()，数字比较均匀，
    // 总共 49 种可能，选取十个数字，使每个数字都是 4/49 的概率
    unordered_map<int, int> umap{{2, 1},  {3, 1},   {1, 2},  {4, 2},  {5, 3},
                                 {7, 3},  {6, 4},   {8, 5},  {10, 5}, {12, 6},
                                 {14, 7}, {15, 7},  {18, 8}, {20, 8}, {21, 9},
                                 {24, 9}, {28, 10}, {30, 10}};
    int res = 0;
    while (true) {
        int t = rand7() * rand7();
        if (umap.count(t)) {
            res = umap[t];
            break;
        }
    }

    return res;
}

int rand10_wrong() {
    // 思路：想了三天，想不出来，放弃了
    srand(rand());
    return rand() % 10 + 1;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    vector<int> vec(10);
    for (int i = 0; i < 100000; i++) {
        vec[rand10() - 1]++;
    }

    printVector(vec);
    return 0;
}
