#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
  public:
    vector<int> vec;
    // 这里用 unordered_set 更能体现 O(1)
    unordered_map<int, vector<int>> umap;
    RandomizedCollection() { srand(time(NULL)); }

    bool insert(int val) {
        int res = false;
        if (umap.find(val) == umap.end()) {
            res = true;
        }

        vec.push_back(val);
        umap[val].push_back(vec.size() - 1);
        return res;
    }

    bool remove(int val) {
        if (umap.find(val) == umap.end()) {
            return false;
        }

        // 替换位置
        auto pos = umap[val].back();
        auto last_val = vec.back();
        auto &last_val_vec = umap[last_val];
        int j = last_val_vec.size() - 1;
        while (j - 1 >= 0 && last_val_vec[j - 1] > pos) {
            last_val_vec[j] = last_val_vec[j - 1];
            j--;
        }

        last_val_vec[j] = pos;
        vec[pos] = last_val;

        // 删除该 val 最后一个位置
        umap[val].pop_back();
        if (umap[val].empty()) {
            umap.erase(val);
        }
        vec.pop_back();

        return true;
    }

    int getRandom() { return vec[rand() % vec.size()]; }
};

int main(void) {
    RandomizedCollection *rset = new RandomizedCollection();
    printBool(rset->insert(1));        // true
    printBool(rset->insert(1));        // false
    printBool(rset->insert(2));        // true
    cout << rset->getRandom() << endl; // 1 || 2
    printBool(rset->remove(1));        // true
    cout << rset->getRandom() << endl; // 1 || 2

    return 0;
}
