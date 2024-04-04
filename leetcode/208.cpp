#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char val = '"';
    vector<TrieNode *> children;
    TrieNode() {}
    TrieNode(char x) : val(x) {}
};

class Trie {
  public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        if (search(word)) {
            return;
        }

        TrieNode *t = root;
        for (auto &c : word) {
            int pos = -1;
            for (int i = 0; i < t->children.size(); i++) {
                if (t->children[i]->val == c) {
                    pos = i;
                }
            }
            if (pos == -1) {
                TrieNode *p = new TrieNode(c);
                t->children.emplace_back(p);
                pos = t->children.size() - 1;
            }
            t = t->children[pos];
        }
        TrieNode *p = new TrieNode();
        t->children.emplace_back(p);
    }

    bool search(string word) {
        TrieNode *t = root;
        for (auto &c : word) {
            int pos = -1;
            for (int i = 0; i < t->children.size(); i++) {
                if (t->children[i]->val == c) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                return false;
            }

            t = t->children[pos];
        }

        int pos = -1;
        for (int i = 0; i < t->children.size(); i++) { // 找结束符
            if (t->children[i]->val == '"') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return false;
        }

        return true;
    }

    bool startsWith(string prefix) {
        TrieNode *t = root;
        for (auto &c : prefix) {
            int pos = -1;
            for (int i = 0; i < t->children.size(); i++) {
                if (t->children[i]->val == c) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                return false;
            }

            t = t->children[pos];
        }
        return true;
    }
};

int main(void) {
    Trie *obj = new Trie();
    obj->insert("apple");
    printBool(obj->search("apple"));
    printBool(obj->search("app"));
    printBool(obj->search("ap"));
    printBool(obj->search("pp"));
    printBool(obj->startsWith("app"));
    printBool(obj->startsWith("a"));
    printBool(obj->startsWith("p"));
    printBool(obj->startsWith("pp"));
    printBool(obj->search("ppappppppppppppppppppppppp"));
    obj->insert("app");
    printBool(obj->search("app"));

    return 0;
}
