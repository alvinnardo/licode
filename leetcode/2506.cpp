#include "../template/head.h"
#include <bits/stdc++.h>

int similarPairs(vector<string> words) {
    // 思路：哈希表 + 位运算
    // 时间 O(nk)，最差空间 O(nk)，k 是平均长度
    unordered_map<int, int> umap;
    int res = 0;
    auto getInt = [](const auto &w) -> int {
        int t = 0;
        for (auto c : w) {
            t |= (1 << (int)(c - 'a'));
        }

        return t;
    };

    for (const auto &w : words) {
        res += umap[getInt(w)]++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << similarPairs({"aba", "aabb", "abcd", "bac", "aabc"}) << endl;
    // 3
    cout << similarPairs({"aabb", "ab", "ba"}) << endl;
    // 0
    cout << similarPairs({"nba", "cba", "dba"}) << endl;

    return 0;
}
