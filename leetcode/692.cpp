#include "../template/head.h"
#include <bits/stdc++.h>

struct cmp {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    };
};

vector<string> topKFrequent(vector<string> words, int k) {
    // 思路：哈希表 + 优先队列
    // 时间 O(nlogk)，空间 O(n)
    unordered_map<string, int> umap;
    for (auto &s : words) {
        umap[s]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
    for (auto &it : umap) {
        pq.emplace(it.second, it.first);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // 优化，直接从后往前取
    vector<string> res(k);
    for (int i = k - 1; i >= 0; i--) {
        res[i] = pq.top().second;
        pq.pop();
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {"i", "love"}
    printVector(
        topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2));
    // {"the", "is", "sunny", "day"}
    printVector(topKFrequent(
        {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
        4));

    return 0;
}
