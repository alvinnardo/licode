#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> countMentions(int numberOfUsers, vector<vector<string>> events) {
    // 思路：差分数组
    // 时间 O(n + mlogm)，空间 O(n)，n 是用户个数，m 是事件个数

    // 有两个细节需要注意
    vector<int> res(numberOfUsers + 2); // 补个前缀 0，则用户 0 下标是 1
    unordered_map<int, int> umap;

    // 1. 先按时间排序，然后离线事件在通知事件之前
    // 注意将时间字符串转为数字
    sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
        return a[1] == b[1] ? a[0][0] > b[0][0]
                            : std::atoi(a[1].c_str()) < std::atoi(b[1].c_str());
    });

    for (const auto &event : events) {
        int t = std::atoi(event[1].c_str());
        // 2. 唤醒
        std::erase_if(umap, [&](const auto &item) { return item.second <= t; });

        if (event[0] == "MESSAGE") {
            if (event[2] == "ALL") {
                res[1]++;
                res.back()--;
            } else if (event[2] == "HERE") {
                res[1]++;
                res.back()--;
                for (auto &p : umap) { // 去掉睡眠的
                    res[p.first + 1]--;
                    res[p.first + 2]++;
                }
            } else {
                string tmp;
                const auto &ids = event[2];
                for (int j = 0; j <= ids.length(); j++) {
                    if (j == ids.length() || ids[j] == ' ') {
                        int id = std::atoi(tmp.c_str());
                        res[id + 1]++;
                        res[id + 2]--;
                        tmp = "";
                    } else if (ids[j] >= '0' && ids[j] <= '9') {
                        tmp += ids[j];
                    }
                }
            }
        } else {
            int id = std::atoi(event[2].c_str());
            umap[id] = t + 60;
        }
    }

    for (int i = 1; i < res.size(); i++) {
        res[i] += res[i - 1];
    }
    return vector<int>(res.begin() + 1, res.begin() + res.size() - 1);
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
    // {1, 0, 2}
    printVector(countMentions(3, {{"MESSAGE", "2", "HERE"},
                                  {"OFFLINE", "2", "1"},
                                  {"OFFLINE", "1", "0"},
                                  {"MESSAGE", "61", "HERE"}}));

    // {1, 3, 2}
    printVector(countMentions(3, {{"MESSAGE", "5", "HERE"},
                                  {"OFFLINE", "10", "0"},
                                  {"MESSAGE", "15", "HERE"},
                                  {"OFFLINE", "18", "2"},
                                  {"MESSAGE", "20", "HERE"}}));

    return 0;
}
