#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;
class UnionFind {
  private:
    vector<int> parent;
    vector<double> weight;

  public:
    UnionFind(int sz) : parent(sz), weight(sz, 1.0) {
        iota(parent.begin(), parent.end(), 0);
    }

    void Union(int x, int y, double val) {
        int xparent = Find(x);
        int yparent = Find(y);
        if (xparent == yparent) {
            return;
        }

        // 前面的 Find() 调用后，两个节点都已经进行了状态压缩
        // 层数已经 <= 2
        parent[xparent] = yparent;
        // weight 的 计算方法是 2->3, 4->5
        // 连接 2->4，需要求 3->5，那么 (2->3 * 3->5) = (2->4 * 4->5)
        // 即 weight[x] * t = val * weight[y]
        weight[xparent] = val * weight[y] / weight[x];
    }

    int Find(int x) {
        if (parent[x] != x) {
            int ori = parent[x];
            parent[x] = Find(parent[x]);
            // 当前节点到根节点的权值
            // = 当前节点到之前父节点的权值 * 之前父节点到根节点的权值
            // 注意：这里的 Find() 递归后都已经进行了状态压缩
            // 那么之前的父节点已经指向了根节点，所以直接相乘即可
            weight[x] *= weight[ori];
        }

        return parent[x];
    }

    double isConnected(int x, int y) {
        int xparent = Find(x);
        int yparent = Find(y);
        if (xparent != yparent) { // 不属于同一个集合
            return -1.0;
        }

        // 用和根节点的权值来计算
        return weight[x] / weight[y];
    }
};

vector<double> calcEquation(vector<vector<string>> equations,
                            vector<double> values,
                            vector<vector<string>> queries) {
    // 并查集：过程中记录权重
    // 时间 O((N+Q)logA), N 是 equations 的大小, Q 是 queries 的大小
    // 合并和查询都是对数复杂度的，A 是指不重复的字符个数
    // 空间 O(A)
    unordered_map<string, int> umap;

    int idx = 0;
    auto getIdx = [&](string s) {
        if (umap.find(s) != umap.end()) {
            return umap[s];
        }

        umap[s] = idx++;
        return umap[s];
    };

    // 如果 equations 中全是不重复的
    UnionFind union_find(2 * equations.size());
    for (int i = 0; i < equations.size(); i++) {
        auto &t = equations[i];
        int x = getIdx(t[0]);
        int y = getIdx(t[1]);
        union_find.Union(x, y, values[i]);
    }

    vector<double> res;
    for (auto &q : queries) {
        if (umap.find(q[0]) == umap.end() || umap.find(q[1]) == umap.end()) {
            res.push_back(-1.0);
        } else {
            res.push_back(union_find.isConnected(umap[q[0]], umap[q[1]]));
        }
    }

    return res;
}

vector<double> calcEquation_dfs(vector<vector<string>> equations,
                                vector<double> values,
                                vector<vector<string>> queries) {
    // 思路
    // 1. 建图，考虑反向直接除，还是最后计算再除
    // 2. 直接 DFS 即可
    // 题目中给出不会给出矛盾值，直接求就可以了

    unordered_map<string, int> umap; // 保存变量和索引的关系
    vector<vector<pair<int, double>>> edges;

    int idx = 0;
    auto getIdx = [&](const string &var) {
        if (umap.find(var) != umap.end()) {
            return umap[var];
        }

        umap[var] = idx++;
        edges.emplace_back();
        return umap[var];
    };

    // 建图
    for (int i = 0; i < equations.size(); i++) {
        int a = getIdx(equations[i][0]);
        int b = getIdx(equations[i][1]);
        edges[a].emplace_back(b, values[i]);
        edges[b].emplace_back(a, 1.0 / values[i]);
    }

    unordered_set<int> uset;
    vector<vector<double>> dist(umap.size(), vector<double>(umap.size(), -1));

    auto getPath = [&](int a) {
        if (uset.find(a) != uset.end()) {
            return;
        }
        uset.insert(a);

        // init
        queue<int> qu;
        vector<bool> visited(umap.size());
        qu.push(a);
        dist[a][a] = 1.0;
        visited[a] = 1;

        while (!qu.empty()) {
            int t = qu.front();
            qu.pop();

            for (auto &c : edges[t]) {
                int ckey = c.first;
                double cval = c.second;
                if (visited[ckey] == true) {
                    continue;
                }

                dist[a][ckey] = dist[a][t] * cval;
                visited[ckey] = true;
                qu.push(ckey);
            }
        }
    };

    vector<double> res;
    for (auto &qu : queries) {
        if (umap.find(qu[0]) == umap.end() || umap.find(qu[1]) == umap.end()) {
            res.push_back(-1);
        } else if (qu[0] == qu[1]) {
            res.push_back(1);
        } else {
            getPath(umap[qu[0]]);
            double t = dist[umap[qu[0]]][umap[qu[1]]];
            res.push_back(t);
        }
    }

    return res;
}

int main(void) {
    printVector(calcEquation(
        {{"a", "b"}, {"b", "c"}}, {2.0, 3.0},
        {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}}));
    printVector(calcEquation(
        {{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0},
        {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}, {"b", "d"}}));
    printVector(calcEquation(
        {{"a", "b"}}, {0.5},
        {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}, {"b", "d"}}));
    printVector(calcEquation(
        {{"b", "a"}, {"c", "b"}, {"d", "c"}, {"e", "d"}, {"f", "e"},
         {"g", "f"}, {"h", "g"}, {"i", "h"}, {"j", "i"}, {"k", "j"},
         {"k", "l"}, {"l", "m"}, {"m", "n"}, {"n", "o"}, {"o", "p"},
         {"p", "q"}, {"q", "r"}, {"r", "s"}, {"s", "t"}, {"t", "u"}},
        {1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05,
         1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05},
        {{"a", "u"}}));

    return 0;
}
