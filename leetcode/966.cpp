#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> spellchecker(vector<string> &&wordlist,
                            vector<string> &&queries) {
    // 思路：哈希表
    // 时间 O(mk + nk)，空间 O(mk)，k 是平均长度

    // 准备三个哈希表
    // 第 1 个存放原始值
    // 第 2 个存放大小写
    // 第 3 个存放元音替换的，把 a e i o u 统一替换成 a
    // 对于每一个哈希表，key 是标准，value 是原始值
    // value 保留为第一个成立的字符串

    auto m{wordlist.size()}, n{queries.size()};

    unordered_set<string> uset(wordlist.begin(), wordlist.end());
    unordered_map<string, string> umap_case, umap_replaced;

    auto toLowerStr = [](auto &t) {
        for (auto &c : t) {
            c = tolower(c);
        }
    };

    auto uniYuanStr = [](auto &t) {
        for (auto &c : t) {
            if (c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = 'a';
            }
        }
    };

    string t;
    for (int i = 0; i < m; i++) {
        t = wordlist[i];

        toLowerStr(t);
        if (!umap_case.count(t)) {
            umap_case[t] = wordlist[i];
        }

        uniYuanStr(t);
        if (!umap_replaced.count(t)) {
            umap_replaced[t] = wordlist[i];
        }
    }

    vector<string> res;
    for (int i = 0; i < n; i++) {
        auto &t = queries[i];
        if (uset.count(queries[i])) {
            res.emplace_back(t);
            continue;
        }

        toLowerStr(t);
        if (umap_case.count(t)) {
            res.emplace_back(umap_case[t]);
            continue;
        }

        uniYuanStr(t);
        if (umap_replaced.count(t)) {
            res.emplace_back(umap_replaced[t]);
            continue;
        }

        res.emplace_back();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"}
    cout << spellchecker({"KiTe", "kite", "hare", "Hare"},
                         {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear",
                          "hear", "keti", "keet", "keto"})
         << endl;

    // {"yellow"}
    cout << spellchecker({"yellow"}, {"YellOw"}) << endl;
    return 0;
}
