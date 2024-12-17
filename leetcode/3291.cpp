#include "../template/head.h"
#include <bits/stdc++.h>

struct TrieTreeNode {
    TrieTreeNode *child[26]{};
};

int minValidStrings(vector<string> words, string target) {
    // 思路：字典树 + DP
    // 只需判断是否是前缀
    // 时间 O(n2)，空间 O(m + n2)

    TrieTreeNode *tree = new TrieTreeNode();
    for (auto &word : words) {
        TrieTreeNode *t = tree;
        int idx = 0;
        for (auto c : word) {
            idx = c - 'a';

            if (t->child[idx] == nullptr) {
                t->child[idx] = new TrieTreeNode();
            }
            t = t->child[idx];
        }
    }

    int len = target.size();
    vector<vector<bool>> vv(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++) {
        TrieTreeNode *t = tree;
        int idx = 0;
        for (int j = i; j < len; j++) {
            idx = target[j] - 'a';
            if (t->child[idx] == nullptr) {
                break;
            } else {
                vv[i][j] = true;
                t = t->child[idx];
            }
        }
    }

    // 分段，前面段的个数 + 后面是否能表示
    vector<int> res(len + 1, INT_MAX);
    res[0] = 0;
    for (int i = 0; i < len + 1; i++) {
        if (res[i] == INT_MAX) {
            continue;
        }

        for (int j = i + 1; j < len + 1; j++) {
            if (vv[i][j - 1]) {
                res[j] = min(res[i] + 1, res[j]);
            }
        }

        if (res.back() != INT_MAX) {
            break;
        }
    }

    return res.back() == INT_MAX ? -1 : res.back();
}

int main(int argc, char *argv[]) {
    // 3
    cout << minValidStrings({"abc", "aaaaa", "bcdef"}, "aabcdabc") << endl;
    // 2
    cout << minValidStrings({"abababab", "ab"}, "ababaababa") << endl;
    // -1
    cout << minValidStrings({"abcdef"}, "xyz") << endl;

    return 0;
}
