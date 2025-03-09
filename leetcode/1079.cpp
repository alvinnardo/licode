#include "../template/head.h"
#include <bits/stdc++.h>

int numTilePossibilities(string tiles) {
    // 思路：DFS
    // 枚举选哪个
    // 时间 O(n!)，空间 O(n)
    int res = 0;
    vector<int> tmp;
    unordered_map<char, int> umap;
    for (char c : tiles) {
        if (!umap.count(c)) {
            umap[c] = tmp.size();
            tmp.push_back(0);
        }
        tmp[umap[c]]++;
    }

    function<void(int)> dfs = [&](int pos) {
        if (pos > tiles.size()) {
            return;
        }
        res += pos > 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == 0) {
                continue;
            }
            tmp[i]--;
            dfs(pos + 1);
            tmp[i]++;
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    // 8
    cout << numTilePossibilities("AAB") << endl;
    // 188
    cout << numTilePossibilities("AAABBC") << endl;
    // 1
    cout << numTilePossibilities("V") << endl;

    return 0;
}
