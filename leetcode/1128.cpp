#include "../template/head.h"
#include <bits/stdc++.h>

int numEquivDominoPairs(vector<vector<int>> dominoes) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(min(n, 10000))
    unordered_map<int, int> umap;
    int sz = dominoes.size();
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        auto &domi = dominoes[i];
        // 都转成正向的，从小到大
        int t =
            domi[0] < domi[1] ? domi[0] * 10 + domi[1] : domi[1] * 10 + domi[0];
        cnt += umap[t]++;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << numEquivDominoPairs({{1, 2}, {2, 1}, {3, 4}, {5, 6}}) << endl;
    // 3
    cout << numEquivDominoPairs({{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}})
         << endl;

    return 0;
}
