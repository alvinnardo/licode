#include "../template/head.h"
#include <bits/stdc++.h>

int numSpecialEquivGroups(vector<string> &&words) {
    // 思路：排序 + 哈希表
    // 时间 O(nklogk)，空间 O(logk)

    // 遍历每个串，分奇偶串成两个串，排序后拼接
    // 哈希表统计
    unordered_map<string, int> umap;
    string odd, even;
    for (auto &word : words) {
        odd = even = "";
        for (int i = 0; i < word.size(); i++) {
            if (i & 1) {
                odd += word[i];
            } else {
                even += word[i];
            }
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        umap[odd + " " + even]++;
    }

    return umap.size();
}

int main(int argc, char *argv[]) {
    // 3
    cout << numSpecialEquivGroups(
                {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"})
         << endl;
    // 3
    cout << numSpecialEquivGroups({"abc", "acb", "bac", "bca", "cab", "cba"})
         << endl;

    return 0;
}
