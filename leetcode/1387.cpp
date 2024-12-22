#include "../template/head.h"
#include <bits/stdc++.h>

int getKth(int lo, int hi, int k) {
    // 思路：记忆化搜索
    // 时间 O(nlogn)，空间 O(n)

    unordered_map<int, int> umap;
    umap[1] = 0;

    function<int(int)> dfs = [&](int val) -> int {
        if (umap.count(val)) {
            return umap[val];
        }

        int t = (val & 1) ? dfs(3 * val + 1) : dfs(val >> 1);
        umap[val] = t + 1;
        return umap[val];
    };

    vector<pair<int, int>> vec;
    for (int i = lo; i <= hi; i++) {
        vec.emplace_back(i, dfs(i));
    }
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    return vec[k - 1].first;
}

int main(int argc, char *argv[]) {
    // 13
    cout << getKth(12, 15, 2) << endl;
    // 7
    cout << getKth(7, 11, 4) << endl;
    // 8
    cout << getKth(1, 1000, 4) << endl;

    return 0;
}
