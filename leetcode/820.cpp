#include "../template/head.h"
#include <bits/stdc++.h>

struct DictNode {
    DictNode *alpha[26]{};
};

bool FindDict(DictNode *dt, const string &str) {
    DictNode *p = dt;
    bool find = true;
    for (int i = str.length() - 1; i >= 0; i--) {
        int t = str[i] - 'a';
        if (p->alpha[t] == nullptr) {
            find = false;
            p->alpha[t] = new DictNode();
        }
        p = p->alpha[t];
    }

    return find;
}

int minimumLengthEncoding(vector<string> words) {
    // 思路：字典树
    // 时间 O(nlogn + nk)，空间 O(nk)
    sort(words.begin(), words.end(),
         [&](const auto &a, const auto &b) { return a.size() > b.size(); });

    DictNode *dt = new DictNode();

    int len = 0;
    for (const auto &word : words) {
        // 查后缀
        if (!FindDict(dt, word)) {
            len += word.length() + 1;
        }
    }

    return len;
}

int minimumLengthEncoding1(vector<string> words) {
    // 思路：贪心
    // 时间 O(nlogn + nk)，空间 O(nk)
    sort(words.begin(), words.end(),
         [&](const auto &a, const auto &b) { return a.size() > b.size(); });

    string tmp;
    for (const auto &word : words) {
        // 查后缀
        string t = word + '#';
        if (tmp.find(t) == std::string::npos) {
            tmp += t;
        }
    }

    return tmp.length();
}

int main(int argc, char *argv[]) {

    // 10
    cout << minimumLengthEncoding({"time", "me", "bell"}) << endl;
    // 10
    cout << minimumLengthEncoding({"time", "bell", "me"}) << endl;
    // 10
    cout << minimumLengthEncoding({"time", "bell", "me", "ell"}) << endl;
    // 14
    cout << minimumLengthEncoding({"time", "bell", "tme", "ell"}) << endl;
    // 10
    cout << minimumLengthEncoding({"feipyxx", "e"}) << endl;

    return 0;
}
