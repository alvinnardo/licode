#include "../template/head.h"
#include <bits/stdc++.h>

int minimumOperationsToMakeKPeriodic(string word, int k) {
    // 思路：哈希表统计
    // 时间: O(nk)，空间 O(n)
    unordered_map<string, int> umap;
    int maxv = INT_MIN;
    string tmp;
    for (int i = 0; i < word.size(); i++) {
        tmp += word[i];
        if ((i + 1) % k == 0) {
            maxv = max(maxv, ++umap[tmp]);
            tmp.clear();
        }
    }

    return word.size() / k - maxv;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumOperationsToMakeKPeriodic("leetcodeleet", 4) << endl;
    // 3
    cout << minimumOperationsToMakeKPeriodic("leetcoleet", 2) << endl;

    return 0;
}
