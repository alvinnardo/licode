#include "../template/head.h"
#include <bits/stdc++.h>

class MagicDictionary {
  public:
    // 思路：哈希表，只比较同等长度的词
    unordered_map<int, vector<string>> umap;
    MagicDictionary() {}

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
    cout << magicDictionary.search("hello") << endl;
    cout << magicDictionary.search("hhllo") << endl;
    cout << magicDictionary.search("hell") << endl;
    cout << magicDictionary.search("leetcoded") << endl;

    return 0;
}
