#include "../template/head.h"
#include <bits/stdc++.h>

int numRabbits(vector<int> answers) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(k)，k 是数组不同数的个数
    // 如果没有个数了，就添加个数；如果有个数，就抱团
    int sz = answers.size(), res = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < sz; i++) {
        if (umap[answers[i]] == 0) {
            res += answers[i] + 1;
            umap[answers[i]] = answers[i];
        } else {
            umap[answers[i]]--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << numRabbits({0}) << endl;
    // 101
    cout << numRabbits({100}) << endl;
    // 5
    cout << numRabbits({1, 1, 2}) << endl;
    // 11
    cout << numRabbits({10, 10, 10}) << endl;
    // 4
    cout << numRabbits({0, 0, 0, 0}) << endl;

    return 0;
}
