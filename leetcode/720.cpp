#include "../template/head.h"
#include <bits/stdc++.h>

struct DictTree {
    bool isEnd = false;
    vector<DictTree *> alpha;

    DictTree() : alpha(26, nullptr) {}
    DictTree(char c) : alpha(26, nullptr) {}
};

void traverse(DictTree *root, int pos, const std::string &str) {
    if (pos == str.length()) {
        root->isEnd = true;
        return;
    }

    int t = str[pos] - 'a';
    if (root->alpha[t] == nullptr) {
        root->alpha[t] = new DictTree();
    }

    traverse(root->alpha[t], pos + 1, str);
}

string longestWord(vector<string> words) {
    // 思路：字典树 + DFS
    // 时间 O(nl)，空间 O(nl)

    DictTree *dt = new DictTree();

    for (auto &w : words) {
        traverse(dt, 0, w);
    }

    string res, tmp;
    function<void(DictTree *)> dfs = [&](DictTree *root) {
        if (!tmp.empty()) {
            if (tmp.length() > res.length() ||
                tmp.length() == res.length() && tmp < res) {
                res = tmp;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (root->alpha[i] != nullptr && root->alpha[i]->isEnd) {
                tmp += (char)('a' + i);
                dfs(root->alpha[i]);
                tmp.pop_back();
            }
        }
    };

    dfs(dt);
    return res;
}

int main(int argc, char *argv[]) {

    // "world"
    cout << longestWord({"w"}) << endl;
    // "world"
    cout << longestWord({"w", "wo", "wor", "worl", "world"}) << endl;
    // "apple"
    cout << longestWord({"a", "banana", "app", "appl", "ap", "apply", "apple"})
         << endl;

    return 0;
}
