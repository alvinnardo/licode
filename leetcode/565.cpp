#include "../template/head.h"
#include <bits/stdc++.h>

class UnionFind {
  public:
    vector<int> pa;
    UnionFind(int sz) : pa(sz) { iota(pa.begin(), pa.end(), 0); }

    int _find(int t) {
        if (pa[t] != t) {
            pa[t] = _find(pa[t]);
        }

        return pa[t];
    }

    void _union(int a, int b) {
        int fa = _find(a);
        int fb = _find(b);
        pa[fa] = fb;
    }

    int getMaxIsland() {
        unordered_map<int, int> umap;
        int maxv = 0;
        for (int i = 0; i < pa.size(); i++) {
            _find(i);
            maxv = max(maxv, ++umap[pa[i]]);
        }

        return maxv;
    }
};

int arrayNesting_my(vector<int> nums) {
    // 思路：并查集 + 统计
    // 时间 O(nlogn)，空间 O(n)
    UnionFind uf(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        uf._union(i, nums[i]);
    }

    return uf.getMaxIsland();
}

int arrayNesting(vector<int> nums) {
    // 题解：图遍历
    // 自己的算法麻烦了
    // 时间 O(n)，空间 O(1)
    // 值是 [0, n - 1]，可以将访问过的点赋值为 n
    int sz = nums.size();
    int maxv = 0;
    for (int i = 0; i < sz; i++) {
        int cnt = 0;

        int j = i;
        while (nums[j] != sz) {
            cnt++;
            int t = j;
            j = nums[j];
            nums[t] = sz;
        }

        maxv = max(maxv, cnt);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 4
    cout << arrayNesting({5, 4, 0, 3, 1, 6, 2}) << endl;
    cout << arrayNesting({0}) << endl;

    return 0;
}
