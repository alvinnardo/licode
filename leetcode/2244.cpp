#include "../template/head.h"
#include <bits/stdc++.h>

int minimumRounds(vector<int> tasks) {
    // 思路：统计 + 贪心
    // 时间 O(n)，空间 O(n)
    unordered_map<int, int> umap;
    for (auto &task : tasks) {
        umap[task]++;
    }

    int cnt = 0;
    for (auto [a, b] : umap) {
        if (b == 1) {
            return -1;
        } else if (b % 3 == 0) {
            cnt += b / 3;
        } else if (b % 3 == 1) { // 可以拿出两个 2
            b -= 4;
            cnt += b / 3 + 2;
        } else { // 可以拿出一个 2
            b -= 2;
            cnt += b / 3 + 1;
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minimumRounds({2, 2, 3, 3, 2, 4, 4, 4, 4, 4}) << endl;
    // -1
    cout << minimumRounds({2, 3, 3}) << endl;

    return 0;
}
