#include "head.h"
#include <bits/stdc++.h>
using namespace std;

class Trie {
  private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }

            node = node->children[ch];
        }
        return node;
    }

  public:
    Trie() : children(26), isEnd(false) {}
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
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
