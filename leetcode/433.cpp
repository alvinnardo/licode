#include "../template/head.h"
#include <bits/stdc++.h>

int minMutation(string startGene, string endGene, vector<string> bank) {
    // 思路：无向图最短路径
    // 时间 O(n2), 空间 O(n2)
    int idx = 0;
    unordered_map<string, int> umap;
    vector<vector<int>> edges(12);
    auto getVal = [&](const string &str) {
        if (umap.find(str) == umap.end()) {
            umap[str] = idx++;
        }

        return umap[str];
    };

    auto isTran = [&](const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                cnt++;
            }
        }

        return cnt == 1;
    };

    bank.emplace_back(startGene);
    // 时间 O(n2)
    for (int i = 0; i < bank.size(); i++) {
        for (int j = i + 1; j < bank.size(); j++) {
            if (isTran(bank[i], bank[j])) {
                int a = getVal(bank[i]), b = getVal(bank[j]);
                edges[a].push_back(b);
                edges[b].push_back(a);
            }
        }
    }

    // 无法到达
    if (umap.find(startGene) == umap.end() ||
        umap.find(endGene) == umap.end()) {
        return -1;
    }

    queue<int> qu;
    qu.push(umap[startGene]);
    int end = umap[endGene];

    int cnt = 0;
    unordered_set<int> seen;
    while (!qu.empty()) {
        int sz = qu.size();
        cnt++;
        while (sz--) {
            int t = qu.front();
            qu.pop();
            if (seen.find(t) != seen.end()) {
                continue;
            }
            seen.insert(t);

            for (auto c : edges[t]) {
                if (c == end) {
                    return cnt;
                }
                qu.push(c);
            }
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minMutation("AACCGGTT", "AACCGGTA", {"AACCGGTA"}) << endl;
    // 2
    cout << minMutation("AACCGGTT", "AAACGGTA",
                        {"AACCGGTA", "AACCGCTA", "AAACGGTA"})
         << endl;
    // 3
    cout << minMutation("AAAAACCC", "AACCCCCC",
                        {"AAAACCCC", "AAACCCCC", "AACCCCCC"})
         << endl;
    // -1
    cout << minMutation("AACCGGTT", "AACCCCCC", {}) << endl;
    // -1
    cout << minMutation("AACCTTGG", "AATTCCGG",
                        {"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"})
         << endl;

    return 0;
}
