#include "../template/head.h"
#include <bits/stdc++.h>

string frequencySort(string s) {
    // 思路：哈希表统计，然后对频数排序
    // 时间 O(n + klogk), 空间 O(k)
    unordered_map<char, int> umap;
    for (auto &c : s) {
        umap[c]++;
    }

    vector<pair<int, char>> vec;
    for (auto &it : umap) {
        vec.emplace_back(it.second, it.first);
    }

    sort(vec.begin(), vec.end());

    string res;
    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        char c = it->second;
        int t = it->first;
        while (t--) {
            res += c;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {

    cout << frequencySort("tree") << endl;
    cout << frequencySort("cccaaa") << endl;
    cout << frequencySort("Aabb") << endl;
    cout << frequencySort("A111122222234342342424225jlkkwabb") << endl;

    return 0;
}
