#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> countMentions(int numberOfUsers, vector<vector<string>> events) {
    // 思路：差分数组
    // 时间 O(n + mlogm)，空间 O(n)，n 是用户个数，m 是事件个数
    vector<int> res(numberOfUsers + 2); // 用户 0 下标是 1
    unordered_map<int, int> umap;

    sort(events.begin(), events.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });

    for (const auto &event : events) {
        int t = std::atoi(event[1].c_str());
        if (umap.size() > 0) {
            for (auto &p : umap) {
                if (p.second + 60 <= t) {
                    umap.erase(p.first);
                }
            }
        }

        if (event[0] == "MESSAGE") {
            if (event[2] == "ALL") {
                res[1]++;
            } else if (event[2] == "HERE") {
                res[1]++;
                for (auto &p : umap) {
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2,2}
    printVector(countMentions(2, {{"MESSAGE", "10", "id1 id0"},
                                  {"OFFLINE", "11", "0"},
                                  {"MESSAGE", "71", "HERE"}}));
    // {2,2}
    printVector(countMentions(2, {{"MESSAGE", "10", "id1 id0"},
                                  {"OFFLINE", "11", "0"},
                                  {"MESSAGE", "12", "ALL"}}));
    // {0,1}
    printVector(
        countMentions(2, {{"OFFLINE", "10", "0"}, {"MESSAGE", "12", "HERE"}}));

    return 0;
}
