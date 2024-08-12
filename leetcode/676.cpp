#include "../template/head.h"
#include <bits/stdc++.h>

class DictTree {
  public:
    vector<DictTree *> vec;
    bool isEnd = false;
    DictTree() : vec(26, nullptr) {}

    void build(const std::string &str, int pos) {
        if (pos == str.length()) {
            isEnd = true;
            return;
        }

        int idx = str[pos] - 'a';
        if (vec[idx] == nullptr) {
            vec[idx] = new DictTree();
        }
        vec[idx]->build(str, pos + 1);
    }

    bool search(const std::string &str, int pos, int skip) {
        if (pos == str.length()) {
            if (isEnd) {
                return skip == 0; // 表示换过
            }
            return false;
        }

        int idx = str[pos] - 'a';
        for (int i = 0; i < vec.size(); i++) {
            bool isFind = false;
            if (idx == i && vec[idx] != nullptr) {
                isFind = vec[idx]->search(str, pos + 1, skip);
            } else if (vec[i] != nullptr && skip) {
                isFind = vec[i]->search(str, pos + 1, 0);
            }

            if (isFind) {
                return true;
            }
        }

        return false;
    }
};

class MagicDictionary {
  public:
    // 思路：字典树
    // 时间: 构造 O(k)，查询 O(26k)
    DictTree *dt;
    MagicDictionary() { dt = new DictTree(); }

    void buildDict(vector<string> dictionary) {
        for (auto &str : dictionary) {
            dt->build(str, 0);
        }
    }

    bool search(string searchWord) { return dt->search(searchWord, 0, 1); }
};

class MagicDictionary1 {
  public:
    // 思路：哈希表，只比较同等长度的词
    unordered_map<int, vector<string>> umap;
    MagicDictionary1() {}

    void buildDict(vector<string> dictionary) {
        for (auto &s : dictionary) {
            umap[s.length()].emplace_back(s);
        }
    }

    bool search(string searchWord) {
        if (umap[searchWord.length()].size() == 0) {
            return false;
        }

        for (auto &s : umap[searchWord.length()]) {
            int cnt = 0;
            for (int i = 0; i < searchWord.length(); i++) {
                if (s[i] != searchWord[i]) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    MagicDictionary magicDictionary;
    magicDictionary.buildDict({"hello", "leetcode"});
    cout << magicDictionary.search("hello") << endl;     // 0
    cout << magicDictionary.search("hhllo") << endl;     // 1
    cout << magicDictionary.search("hell") << endl;      // 0
    cout << magicDictionary.search("leetcoded") << endl; // 0

    return 0;
}
