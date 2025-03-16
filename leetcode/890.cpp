#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> findAndReplacePattern(vector<string> words, string pattern) {
    // 思路: 模拟
    // 时间 O(mn)，空间 O(m)
    vector<string> res;
    // 一对一映射
    unordered_map<char, char> umap1, umap2;
    for (const auto &word : words) {
        umap1.clear();
        umap2.clear();
        if (word.length() != pattern.length()) {
            continue;
        }

        bool matched = true;
        for (int i = 0; i < pattern.length(); i++) {
            if (umap1.count(pattern[i]) && umap2.count(word[i])) {
                if (umap1[pattern[i]] != word[i] ||
                    umap2[word[i]] != pattern[i]) {
                    matched = false;
                    break;
                }
            } else if (!umap1.count(pattern[i]) && !umap2.count(word[i])) {
                umap1[pattern[i]] = word[i];
                umap2[word[i]] = pattern[i];
            } else {
                matched = false;
                break;
            }
        }

        if (matched) {
            res.emplace_back(word);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"mee","aqq"}
    printVector(findAndReplacePattern(
        {"abc", "deq", "mee", "aqq", "dkd", "ccc"}, "abb"));

    return 0;
}
