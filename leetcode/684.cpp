#include "../template/head.h"
#include <bits/stdc++.h>

struct UnionFind {
    int m_sz = 0;
    vector<int> m_fa_vec;

    UnionFind(int sz) : m_sz(sz), m_fa_vec(sz) {
        std::iota(m_fa_vec.begin(), m_fa_vec.end(), 0);
    }
    void clear() { std::iota(m_fa_vec.begin(), m_fa_vec.end(), 0); }

    int _find(int a) {
        if (m_fa_vec[a] != a) {
            m_fa_vec[a] = _find(m_fa_vec[a]);
        }
        return m_fa_vec[a];
    }

    void _union(int a, int b) {
        int fa = _find(a), fb = _find(b);
        m_fa_vec[fa] = fb;
    }

    int getNum() {
        int cnt = 0;
        for (int i = 0; i < m_sz; i++) {
            cnt += m_fa_vec[i] == i;
        }

        return cnt;
    }
};

// 用时 15 分钟，思路很明确
// 看了之前的提交记录，20 年尝试了 4 次放弃了
// 23 年用自己的算法解出，后看题解学习使用并查集思想转为自己的代码写出
// 今年又过了一年，做了很多题回顾这道题才发现，并查集的代码已经运用得很熟练了
vector<int> findRedundantConnection(vector<vector<int>> edges) {
    // 思路：并查集
    // 时间：O(n2)，空间 O(n)
    int sz = edges.size();

    UnionFind uf(sz + 1);

    auto canJoin = [&](int j) {
        uf.clear();
        for (int i = 0; i < sz; i++) {
            if (i == j) {
                continue;
            }
            uf._union(edges[i][0], edges[i][1]);
        }

        return uf.getNum() == 2; // 多一个 0 指向自己
    };

    for (int i = sz - 1; i >= 0; i--) {
        if (canJoin(i)) {
            return edges[i];
        }
    }

    return {};
}

int main(int argc, char *argv[]) {
    // {2,3}
    printVector(findRedundantConnection({{1, 2}, {1, 3}, {2, 3}}));
    // {1,4}
    printVector(
        findRedundantConnection({{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}));

    return 0;
}
