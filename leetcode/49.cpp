#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strs) {
    // 哈希表存放字符频次串与位置的关系
    unordered_map<string, int> umap;
    vector<vector<string>> res;
    int idx = 0; // 先放再加

    // 每一个单词获取一下字符频次串
    int freq[26];
    for (auto &str : strs) {
        for (int i = 0; i < 26; i++) { // clear
            freq[i] = 0;
        }

        for (auto &c : str) {
            freq[c - 'a']++;
        }

        string freq_str;
        for (int i = 0; i < 26; i++) {
            freq_str += (char)('a' + i) + to_string(freq[i]);
        }
        // cout << freq_str << endl;

        if (umap.find(freq_str) == umap.end()) {
            umap[freq_str] = idx++;
            res.push_back({str});
        } else {
            res[umap[freq_str]].emplace_back(str);
        }
    }
    return res;
}

int main(void) {
    printVectorVector(
        groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}));
    printVectorVector(groupAnagrams({""}));
    printVectorVector(groupAnagrams({"a", "a"}));
    printVectorVector(groupAnagrams({"a", "a", "ba", "ab", "bbc", "dcb"}));

    return 0;
}
