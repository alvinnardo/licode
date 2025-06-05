#include "../template/head.h"
#include <bits/stdc++.h>

struct UnionFind {

    vector<int> fa;

    UnionFind() : fa(26) { iota(fa.begin(), fa.end(), 0); }

    void _union(int a, int b) {
        a = _find(a), b = _find(b);
        if (a == b) {
            return;
        }

        if (a < b) {
            fa[b] = a;
        } else {
            fa[a] = b;
        }
    }

    int _find(int a) {
        if (fa[a] != a) {
            fa[a] = _find(fa[a]);
        }
        return fa[a];
    }
};

string smallestEquivalentString(string s1, string s2, string baseStr) {
    // 思路：并查集
    // 时间 O(n + m + klogk)，空间 O(k)
    int n = s1.size(), m = baseStr.size();

    shared_ptr<UnionFind> uf = make_shared<UnionFind>();

    for (int i = 0; i < n; i++) {
        uf->_union(s1[i] - 'a', s2[i] - 'a');
    }

    for (int i = 0; i < m; i++) {
        baseStr[i] = 'a' + uf->_find(baseStr[i] - 'a');
    }
    return baseStr;
}

int main(int argc, char *argv[]) {
    // "makkek"
    cout << smallestEquivalentString("parker", "morris", "parser") << endl;
    // "hdld"
    cout << smallestEquivalentString("hello", "world", "hold") << endl;
    // "aauaaaaada"
    cout << smallestEquivalentString("leetcode", "programs", "sourcecode")
         << endl;

    return 0;
}
