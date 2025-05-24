#include "../template/head.h"
#include <bits/stdc++.h>

int longestPalindrome(vector<string> words) {
    // 思路：哈希表
    // 时间 O(m)，空间 O(m)
    unordered_map<int, int> umap;
    int sz = words.size();
    int res = 0, t = 0;
    for (int i = 0; i < sz; i++) {
        t = (words[i][1] - 'a') * 100 + (words[i][0] - 'a');
        if (umap.count(t)) {
            umap[t]--;
            res += 4;
            if (umap[t] == 0) {
                umap.erase(t);
            }
        } else {
            t = (words[i][0] - 'a') * 100 + (words[i][1] - 'a');
            umap[t]++;
        }
    }

    for (auto &t : umap) {
        if (t.first / 100 == t.first % 100) {
            res += 2;
            break;
        }
    }

    return res;
}

int longestPalindrome1(vector<string> words) {
    // 思路：哈希表
    // 时间 O(m)，空间 O(m)
    unordered_map<string, int> umap;
    int sz = words.size();
    string tmp = "  ";
    int res = 0;
    for (int i = 0; i < sz; i++) {
        tmp[0] = words[i][1];
        tmp[1] = words[i][0];
        if (umap.count(tmp)) {
            umap[tmp]--;
            res += 4;
            if (umap[tmp] == 0) {
                umap.erase(tmp);
            }
        } else {
            umap[words[i]]++;
        }
    }

    for (auto &t : umap) {
        if (t.first[0] == t.first[1]) {
            res += 2;
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << longestPalindrome({"lc", "cl", "gg"}) << endl;
    // 8
    cout << longestPalindrome({"ab", "ty", "yt", "lc", "cl", "ab"}) << endl;
    // 2
    cout << longestPalindrome({"cc", "ll", "xx"}) << endl;

    return 0;
}
