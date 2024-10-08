#include "../template/head.h"
#include <bits/stdc++.h>

string destCity(vector<vector<string>> paths) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    // 保留出度
    unordered_map<string, int> umap;
    vector<string> vec;
    for (const auto &it : paths) {
        if (umap.count(it[0]) == 0) {
            vec.emplace_back(it[0]);
        }
        if (umap.count(it[1]) == 0) {
            vec.emplace_back(it[1]);
        }
        umap[it[0]]++;
    }

    for (auto &it : vec) {
        if (umap[it] == 0) {
            return it;
        }
    }

    return "";
}

int main(int argc, char *argv[]) {
    // "Sao Paulo"
    cout << destCity({{"London", "New York"},
                      {"New York", "Lima"},
                      {"Lima", "Sao Paulo"}})
         << endl;
    // "A"
    cout << destCity({{"B", "C"}, {"D", "B"}, {"C", "A"}}) << endl;
    // "Z"
    cout << destCity({{"A", "Z"}}) << endl;

    return 0;
}
