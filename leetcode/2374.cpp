#include "../template/head.h"
#include <bits/stdc++.h>

int edgeScore(vector<int> edges) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)

    int node = -1, sz = edges.size();
    long long cnt = -1;
    vector<long long> vec(sz);
    for (int i = 0; i < sz; i++) {
        vec[edges[i]] += i;
        if (vec[edges[i]] > cnt || vec[edges[i]] == cnt && edges[i] < node) {
            cnt = vec[edges[i]];
            node = edges[i];
        }
    }

    return node;
}

int main(int argc, char *argv[]) {
    // 7
    cout << edgeScore({1, 0, 0, 0, 0, 7, 7, 5}) << endl;
    // 0
    cout << edgeScore({2, 0, 0, 2}) << endl;

    return 0;
}
