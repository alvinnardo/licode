#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
  public:
    int mod = 10009;
    vector<list<pair<int, int>>> vlist;
    int hashKey(int key) { return key % mod; }

    MyHashMap() : vlist(mod) {}

    void put(int key, int value) {
        int hkey = hashKey(key);
        bool find = false;
        for (auto it = vlist[hkey].begin(); it != vlist[hkey].end(); it++) {
            if (it->first == key) {
                find = true;
                it->second = value;
                break;
            }
        }

        if (!find) {
            vlist[hkey].emplace_back(key, value);
        }
    }

    int get(int key) {
        int hkey = hashKey(key);
        for (auto it = vlist[hkey].begin(); it != vlist[hkey].end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }

        return -1;
    }

    void remove(int key) {
        int hkey = hashKey(key);
        for (auto it = vlist[hkey].begin(); it != vlist[hkey].end(); it++) {
            if (it->first == key) {
                vlist[hkey].erase(it);
                // 只有一个，直接 return 就行
                // 如果有多个，删除之后不能直接 it++，会自动指向下一个迭代器
                return;
            }
        }
    }
};

int main(void) {

    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl; // 1
    cout << myHashMap.get(3) << endl; // -1
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl; // 1
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl; // -1

    return 0;
}
