#include "../template/head.h"
#include <bits/stdc++.h>

int countOfSubstrings(string word, int k) {
    // 思路：模拟 + 哈希表
    // 时间 O(n)，空间 O(1)
    // 双指针的方法滑动条件没想明白，数据量不大，先直接做
    int res = 0, len = word.length();
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> umap;
    int cnt = 0; // 元音字母个数
    for (int i = 0; i < len; i++) {
        cnt = 0;
        umap.clear();
        char c{};
        for (int j = i; j < len; j++) {
            c = word[j];
            if (uset.count(c)) {
                umap[c]++;
                cnt++;
            }
            int num = j - i + 1 - cnt;
            if (num > k) { // 多了就不再继续了
                break;
            } else if (num == k && umap.size() == uset.size()) {
                res++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 0
    cout << countOfSubstrings("aeioqq", 1) << endl;
    // 1
    cout << countOfSubstrings("aeiou", 0) << endl;
    // 3
    cout << countOfSubstrings("ieaouqqieaouqq", 1) << endl;

    return 0;
}
