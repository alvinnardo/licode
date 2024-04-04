#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>> edges) {
    vector<vector<int>> nei(n);
    vector<unordered_set<int>> ancs(n);
    vector<int> head(n);

    for (auto &edge : edges) {
        nei[edge[0]].push_back(edge[1]);
        head[edge[1]] = 1;
    }

    // 层序遍历
    queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (head[i] == 0) {
            qu.push(i);
        }
    }

    while (!qu.empty()) {

        int cnt = qu.size();
        unordered_set<int> seen;
        while (cnt--) {
            auto t = qu.front();
            qu.pop();

            for (auto &c : nei[t]) {
                if (seen.find(c) == seen.end()) {
                    qu.push(c);
                    seen.insert(c);
                }

                // 把父节点的祖父节点和父节点，放入孩子节点的结果中
                for (auto &pa : ancs[t]) {
                    ancs[c].insert(pa);
                }
                ancs[c].insert(t);
            }
        }
    }

    vector<vector<int>> res;
    for (auto &anc : ancs) {
        res.emplace_back(anc.begin(), anc.end());
    }
    return res;
}

int main(void) {
    /* clang-format off */
    printVectorVector(getAncestors(8, {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}}));
    printVectorVector(getAncestors(5, {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}));
    printVectorVector(getAncestors(1, {}));
    printVectorVector(getAncestors(2, {}));
    vector<vector<int>> ori;
    for (int i = 0; i < 999; i++) {
        ori.push_back({i, i+1});
        // cout << "[" << i << "," << i + 1 << "],";
    }
    printVectorVector(getAncestors(1000, ori));
    // getAncestors(1000, ori);
    /* clang-format on */

    return 0;
}
