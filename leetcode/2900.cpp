#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> getLongestSubsequence(vector<string> words, vector<int> groups) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    // 简单说就是相邻的 group 不能相等
    int j = 0, sz = words.size();
    int gj = groups[j];
    for (int i = 1; i < sz; i++) {
        if (groups[i] != gj) {
            j++;
            if (i != j) {
                words[j] = words[i];
            }
            gj = groups[i];
        }
    }

    words.resize(j + 1);
    return words;
}

int main(int argc, char *argv[]) {
    // {"e","b"}
    printVector(getLongestSubsequence({"e", "a", "b"}, {0, 0, 1}));
    // {"a","b","c"}
    printVector(getLongestSubsequence({"a", "b", "c", "d"}, {1, 0, 1, 1}));
    // {"r","pb","x"}
    printVector(getLongestSubsequence({"r", "k", "pb", "x"}, {0, 0, 1, 0}));
    // {"h","vv","kp"}
    printVector(getLongestSubsequence({"h", "vv", "kp"}, {0, 1, 0}));

    return 0;
}
