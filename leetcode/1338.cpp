#include "../template/head.h"
#include <bits/stdc++.h>

int minSetSize(vector<int> arr) {
    // 思路：贪心
    // 时间 O(nlogn)，空间 O(n)
    unordered_map<int, int> umap;
    for (int a : arr) {
        umap[a]++;
    }

    int sz = arr.size();
    priority_queue<int> pq;
    for (auto &t : umap) {
        pq.emplace(t.second);
    }

    int tot = 0, cnt = 0;
    while (tot < sz - tot) {
        tot += pq.top();
        pq.pop();
        cnt++;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minSetSize({3, 3, 3, 3, 5, 5, 5, 2, 2, 7}) << endl;
    // 1
    cout << minSetSize({7, 7, 7, 7, 7, 7}) << endl;
    // 5
    cout << minSetSize(
                {9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19})
         << endl;

    return 0;
}
