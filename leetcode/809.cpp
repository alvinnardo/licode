#include "../template/head.h"
#include <bits/stdc++.h>

int expressiveWords(string s, vector<string> words) {
    // 思路: 统计
    // 时间 O(mnk)，空间 O(m + nk)
    vector<pair<int, int>> svec;
    auto getVec = [&](const string &sstr) {
        vector<pair<int, int>> vec;
        for (const char &c : sstr) {
            if (vec.empty() || c != vec.back().first) {
                vec.emplace_back(c, 1);
            } else {
                vec.back().second++;
            }
        }
        return vec;
    };

    svec = std::move(getVec(s));

    auto isMatch = [](auto &a, auto &b) -> bool {
        if (a.size() != b.size()) {
            return false;
        }

        for (int i = 0; i < a.size(); i++) {
            // 不能多，也不能少
            if (a[i].first != b[i].first || a[i].second < b[i].second ||
                a[i].second > b[i].second && (a[i].second < 3)) {
                return false;
            }
        }
        return true;
    };

    int res = 0;
    vector<pair<int, int>> tvec;
    for (const auto &word : words) {
        tvec = std::move(getVec(word));

        res += isMatch(svec, tvec);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << expressiveWords("heeellooo", {"hello", "hi", "helo"}) << endl;
    // 2
    cout << expressiveWords("heeelllooo", {"hello", "hi", "helo"}) << endl;
    // 0
    cout << expressiveWords("aaa", {"aaaa"}) << endl;

    return 0;
}
