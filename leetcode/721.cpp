#include "../template/head.h"
#include <bits/stdc++.h>

class UnionFind {

  public:
    vector<int> parents;
    UnionFind(int n) : parents(n) { iota(parents.begin(), parents.end(), 0); }

    void union_(int a, int b) {
        int pa = find_(a);
        int pb = find_(b);
        parents[pa] = pb;
    }

    int find_(int a) {
        if (parents[a] != a) {
            parents[a] = find_(parents[a]);
        }
        return parents[a];
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
    // 思路：哈希表 + 红黑树 + 并查集
    // 时间 O(mnlogm)，空间 O(mn + m)
    map<string, int> umap; // emails 和 user 的对应关系

    int sz = accounts.size();
    UnionFind uf = UnionFind(sz);

    for (int i = 0; i < sz; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (umap.count(accounts[i][j])) {
                uf.union_(i, umap[accounts[i][j]]);
            }
            umap[accounts[i][j]] = i;
        }
    }
    vector<vector<string>> res;

    unordered_map<int, int> uumap; // 存放父节点和最终位置的映射关系
    int id = 0;
    for (int i = 0; i < sz; i++) {
        int pa = uf.find_(i);
        if (!uumap.count(pa)) {
            uumap[pa] = id++;
            res.push_back({accounts[i][0]});
        }
    }

    for (auto &it : umap) {
        // 先找最开始属于谁，再找它的父亲是谁，最后找最终位置
        res[uumap[uf.find_(it.second)]].emplace_back(it.first);
    }

    return res;
}

int main(int argc, char *argv[]) {
    /* {{"John", 'john00@mail.com', 'john_newyork@mail.com',
     * 'johnsmith@mail.com'}, {"John", "johnnybravo@mail.com"}, {"Mary",
     * "mary@mail.com"}} */
    vector<vector<string>> vec = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}};
    printVectorVector(accountsMerge(vec));

    /*
     * {{"Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"},
     * {"Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"},
     * {"Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"},
     * {"Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"},
     * {"Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"}}
     */
    vec = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
           {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
           {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
           {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
           {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
    printVectorVector(accountsMerge(vec));

    vec = {{"John", "John497@m.co", "John4473@m.co", "John4474@m.co"},
           {"John", "John499@m.co", "John4491@m.co", "John4492@m.co",
            "John4493@m.co"},
           {"John", "John497@m.co", "John498@m.co", "John499@m.co"}};

    vec = {{"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"},
           {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"},
           {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"},
           {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"},
           {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"}};

    printVectorVector(accountsMerge(vec));

    return 0;
}
