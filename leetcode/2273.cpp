#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> removeAnagrams(vector<string> &&words) {
    // 思路：模拟
    // 时间 O(nk)，空间 O(k)，k 是字符串平均长度
    vector<string> res;
    int sz = words.size();

    string t1, t2;
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            t1 = words[i];
            res.emplace_back(words[i]);
            std::ranges::sort(t1);
        } else {
            t2 = words[i];
            std::ranges::sort(t2);
            if (t2 != t1) {
                res.emplace_back(words[i]);
                t1 = t2;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"abba","cd"}
    cout << removeAnagrams({"abba", "baba", "bbaa", "cd", "cd"}) << endl;
    // {"a","b","c","d","e"}
    cout << removeAnagrams({"a", "b", "c", "d", "e"}) << endl;

    return 0;
}
