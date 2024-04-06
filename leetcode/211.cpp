#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class Trie {
  public:
    vector<Trie *> child;
    bool isEnd = false;

    Trie() : child(26) {}

    void dfs(Trie *root, int pos, string &word) {
        // 注意是最后一个节点是结束符
        // 当 pos == word.length() 时，此时的 root 才是最后的结束字符
        if (pos == word.length()) {
            root->isEnd = true;
            return;
        }

        char t = word[pos];
        if (root->child[t - 'a'] == nullptr) {
            root->child[t - 'a'] = new Trie();
        }
        dfs(root->child[t - 'a'], pos + 1, word);
    }
    void addWord(std::string word) { dfs(this, 0, word); }

    bool searchOne(Trie *root, int pos, string &word) {
        if (pos == word.length()) {
            return root->isEnd;
        }

        char c = word[pos];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->child[i] &&
                    searchOne(root->child[i], pos + 1, word)) {
                    return true;
                }
            }
            return false;

        } else if (root->child[c - 'a'] == nullptr) {
            return false;
        }

        return searchOne(root->child[c - 'a'], pos + 1, word);
    }
    bool search(std::string word) { return searchOne(this, 0, word); }
};
// 用字典树
// 最差情况用例中没有给出，工程中可接受
class WordDictionary {
  public:
    Trie *trie;
    WordDictionary() { trie = new Trie(); }

    void addWord(string word) { trie->addWord(word); }

    bool search(string word) { return trie->search(word); }
};

// 超时
class WordDictionary1 {

  public:
    unordered_set<string> uset;
    vector<int> dict;
    // 长度 -> 字符位置 -> 字符 -> 字符串位置
    vector<vector<vector<vector<int>>>> aux;
    // 长度 1..25，字符 0..25
    WordDictionary1() : dict(26), aux(26) {
        vector<vector<int>> tmp(26);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < i; j++) {
                aux[i].push_back(tmp);
            }
        }
    }

    void addWord(string word) {
        if (uset.find(word) == uset.end()) {
            uset.insert(word);
        } else {
            return;
        }

        int sz = word.length();
        auto &len_aux = aux[sz];
        int pos = dict[sz];
        for (int i = 0; i < sz; i++) {
            len_aux[i][word[i] - 'a'].push_back(pos);
        }

        ++dict[sz];
    }

    bool search(string word) {
        int sz = word.length();
        auto &len_aux = aux[sz];
        unordered_set<int> uset;
        bool start = true;
        int dot_cnt = 0;
        for (int i = 0; i < sz; i++) {
            char c = word[i];
            if (c == '.') {
                dot_cnt++;
                continue;
            }
            unordered_set<int> tset;
            auto &v = len_aux[i][c - 'a'];
            // 在这里超时，如果有相同后缀的单词特别多，
            // 那么合并的时间就会很长
            for (auto &p : v) {
                if (start) {
                    tset.insert(p);
                } else if (uset.find(p) != uset.end()) {
                    tset.insert(p);
                }
            }
            start = false;
            uset = tset;
            if (uset.empty()) {
                return false;
            }
        }

        if (dot_cnt == sz && dict[sz] == 0) {
            return false;
        }
        return true;
    }
};

int main(void) {
    auto *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    obj->addWord("abcdefghijklmnopqrstuvwxy");
    printBool(obj->search("pad"));
    printBool(obj->search("abcdefghijklmnopqrstuvwxy"));
    printBool(obj->search("a........................"));
    printBool(obj->search("ac......................."));
    printBool(obj->search("bad"));
    printBool(obj->search(".ad"));
    printBool(obj->search("b.."));
    printBool(obj->search("b."));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 13; j++) {
            for (int k = 0; k < 15; k++) {
                string t;
                t += (char)('a' + i);
                t += (char)('a' + j);
                t += (char)('a' + k);
                // t += "defghijklmnopqrstuvwxy";
                t += "defghijklmnopqrstuvwxy";
                // cout << i * j * k << endl;
                // cout << t << endl;
                obj->addWord(t);
            }
        }
    }
    for (int i = 0; i < 5000; i++) {
        // printBool(obj->search("a........................"));
        // printBool(obj->search("aa......................."));
        printBool(obj->search("abcd.fghijklmnopqrstuvwx."));
        printBool(obj->search("."));
    }

    obj->addWord("mwsgyywmmkzmy");
    obj->addWord("y");
    printBool(obj->search("m"));
    return 0;
}
