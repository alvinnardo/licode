#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> partitionLabels(string &&s) {
    // 思路：贪心
    // 时间 O(n + k + klogk)，空间 O(k)
    // 合并区间
    vector<pair<int, int>> vec(26, {-1, -1});
    int len = s.length();

    // 找到每个字符的起始位置和结束位置
    for (int i = 0; i < len; i++) {
        int t = s[i] - 'a';
        if (vec[t].first == -1) {
            vec[t] = {i, i};
        } else {
            vec[t].second = i;
        }
    }

    sort(vec.begin(), vec.end(),
         [](const auto &a, const auto &b) { return a.first < b.first; });

    vector<int> res;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].first == -1) {
            continue;
        }

        if (i + 1 < vec.size()) {
            auto &t = vec[i + 1];
            if (t.first > vec[i].second) {
                res.push_back(vec[i].second - vec[i].first + 1);
            } else { // 合并
                t.first = vec[i].first;
                t.second = max(t.second, vec[i].second);
            }
        } else {
            res.push_back(vec[i].second - vec[i].first + 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {9,7,8}
    cout << partitionLabels("ababcbacadefegdehijhklij") << endl;
    // {10}
    cout << partitionLabels("eccbbbbdec") << endl;

    return 0;
}
