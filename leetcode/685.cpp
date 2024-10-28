#include "../template/head.h"
#include <bits/stdc++.h>

struct UnionFind {

    int m_sz = 0;
    vector<int> m_fa_vec;

    UnionFind(int sz) : m_sz(sz), m_fa_vec(m_sz) { init(); }
    void init() { iota(m_fa_vec.begin(), m_fa_vec.end(), 0); }
    void _union(int a, int b) {
        int fa = _find(a);
        int fb = _find(b);
        m_fa_vec[fa] = fb;
    }

    int _find(int a) {
        if (m_fa_vec[a] != a) {
            m_fa_vec[a] = _find(m_fa_vec[a]);
        }
        return m_fa_vec[a];
    }

    int getNum() {
        int cnt = 0;
        for (int i = 0; i < m_sz; i++) {
            cnt += m_fa_vec[i] == i;
        }
        return cnt;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
    /* clang-format off */
    // 思路：并查集 + 哈希表
    // 只有一个点没有入度且出度不为 0，其他节点是入度为 1，且最后只有一个连通区域
    // 时间 O(n2)，空间 O(n)
    /* clang-format on */
    int maxv = INT_MIN;
    for (const auto &edge : edges) {
        maxv = max(maxv, max(edge[0], edge[1]));
    }

    vector<pair<int, int>> vec(maxv + 1); // 保存每个点的度
    UnionFind uf(maxv + 1);
    int sz = edges.size();

    auto canJoin = [&](int pos) -> bool {
        for (int i = 0; i < sz; i++) {
            if (i == pos) {
                continue;
            }
            uf._union(edges[i][0], edges[i][1]);

            ++vec[edges[i][0]].first;            // 出度
            if (++vec[edges[i][1]].second > 1) { // 入度
                return false;
            }
        }

        int cnt_root = 0;
        for (int i = 1; i <= maxv; i++) {
            if (vec[i].second == 0 && vec[i].first > 0) {
                cnt_root++;
            }
        }

        // cout << edges[pos][0] << ", " << edges[pos][1] << ": " << uf.getNum()
        //      << endl;
        return cnt_root == 1 && uf.getNum() == 2;
    };

    for (int i = sz - 1; i >= 0; i--) {
        vec.assign(maxv + 1, {0, 0});
        uf.init();
        if (canJoin(i)) {
            return edges[i];
        }
    }

    return {};
}

int main(int argc, char *argv[]) {
    // {2,3}
    printVector(findRedundantDirectedConnection({{1, 3}, {2, 3}, {1, 2}}));
    // {2,3}
    printVector(findRedundantDirectedConnection({{1, 2}, {1, 3}, {2, 3}}));
    // {1,3}
    printVector(findRedundantDirectedConnection({{1, 2}, {2, 3}, {1, 3}}));
    // {4,1}
    printVector(findRedundantDirectedConnection(
        {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}}));
    // {4,2}
    printVector(findRedundantDirectedConnection(
        {{4, 2}, {1, 5}, {5, 2}, {5, 3}, {2, 4}}));

    return 0;
}
