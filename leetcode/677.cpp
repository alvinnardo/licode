#include "../template/head.h"
#include <bits/stdc++.h>

class MapSum {
  public:
    // 思路：枚举
    vector<string> vec;
    unordered_map<string, int> umap;
    MapSum() {}

    void insert(string key, int val) {
        if (!umap.count(key)) {
            vec.emplace_back(key);
        }
        umap[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (auto &s : vec) {
            if (s.length() < prefix.length()) {
                continue;
            }
            int i = 0;
            for (; i < prefix.length(); i++) {
                if (s[i] != prefix[i]) {
                    break;
                }
            }

            if (i == prefix.length()) {
                res += umap[s];
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    MapSum mapSum;
    mapSum.insert("apple", 3);
    cout << mapSum.sum("ap") << endl; // 3
    mapSum.insert("app", 2);
    cout << mapSum.sum("ap") << endl; // 2

    return 0;
}
