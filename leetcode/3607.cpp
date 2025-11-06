#include "../template/head.h"
#include <bits/stdc++.h>

class UnionFind {
    vector<int> m_vec;

  public:
    UnionFind(int num) {
        for (int i = 0; i < num + 1; i++) {
            m_vec.push_back(i);
        }
    }

    void _union(int a, int b) {
        int fa = _find(a), fb = _find(b);
        m_vec[fb] = fa;
    }

    int _find(int a) {

        int t = m_vec[a];
        if (m_vec[a] != a) {
            t = _find(m_vec[a]);
        }

        m_vec[a] = t;
        return m_vec[a];
    }

    vector<int> &getVec() {
        // 整理一下
        for (int i = 0; i < m_vec.size(); i++) {
            _find(i);
        }

        return m_vec;
    }
};

vector<int> processQueries(int c, vector<vector<int>> &&connections,
                           vector<vector<int>> &&queries) {
    // 思路：并查集 + 哈希表 + 红黑树
    // 时间 O(nlogn)，空间 O(n)

    // 先用并查集组网，再用哈希表存放组信息，红黑树用于排序和查找
    std::shared_ptr<UnionFind> ufp = std::make_shared<UnionFind>(c);
    for (auto &conn : connections) {
        ufp->_union(conn[0], conn[1]);
    }

    unordered_map<int, set<int>> umap;
    vector<int> &vec = ufp->getVec();
    for (int i = 1; i < vec.size(); i++) {
        umap[vec[i]].insert(i);
    }

    vector<int> res;
    for (auto &query : queries) {
        int g = vec[query[1]];
        if (query[0] == 1) {
            if (umap[g].empty()) {
                res.push_back(-1);
            } else if (umap[g].count(query[1])) {
                res.push_back(query[1]);
            } else {
                res.push_back(*umap[g].begin());
            }
        } else {
            umap[g].erase(query[1]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,2,3}
    cout << processQueries(5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}},
                           {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}})
         << endl;
    // {1,-1}
    cout << processQueries(3, {}, {{1, 1}, {2, 1}, {1, 1}}) << endl;
    // {1,1,3,1,3,1,1,3,-1,-1,-1,-1,-1,-1}
    cout << processQueries(3, {{3, 2}, {1, 3}, {2, 1}},
                           {{2, 2}, {1, 2}, {1, 2}, {1, 3}, {1, 1},
                            {1, 3}, {1, 1}, {1, 1}, {2, 1}, {1, 1},
                            {2, 3}, {2, 3}, {2, 3}, {2, 1}, {2, 1},
                            {2, 1}, {1, 1}, {1, 1}, {1, 2}, {1, 2},
                            {2, 1}, {2, 1}, {2, 2}, {1, 2}, {1, 1}})
         << endl;

    return 0;
}
