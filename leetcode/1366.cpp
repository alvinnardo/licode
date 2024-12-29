#include "../template/head.h"
#include <bits/stdc++.h>

string rankTeams(vector<string> votes) {
    // 思路: 统计 + 自定义排序
    // 时间 O(mklogm)，空间 O(logm + k2)
    if (votes.size() == 1) {
        return votes.back();
    }

    int n = votes[0].size();
    // 用于保存字母和在每个位置上出现的次数
    vector<vector<int>> freq(n, vector<int>(n));
    unordered_map<char, int> umap;
    string res = votes[0];
    for (const auto &v : votes[0]) {
        umap[v] = umap.size();
    }

    // 统计
    for (const auto &vote : votes) {
        for (int i = 0; i < vote.size(); i++) {
            freq[umap[vote[i]]][i]++;
        }
    }

    // 排序
    std::function<bool(char &a, char &b)> cmp = [&](char &a, char &b) -> bool {
        const auto &va = freq[umap[a]];
        const auto &vb = freq[umap[b]];

        for (int i = 0; i < va.size(); i++) {
            if (va[i] == vb[i]) { // 频数相等比较下一位
                continue;
            }
            return va[i] > vb[i]; // 不相等直接返回关系
        }

        return a < b; // 都相等，则按字母顺序
    };

    sort(res.begin(), res.end(), cmp);
    return res;
}

int main(int argc, char *argv[]) {
    // "ACB"
    cout << rankTeams({"ABC", "ACB", "ABC", "ACB", "ACB"}) << endl;
    // "XWYZ"
    cout << rankTeams({"WXYZ", "XYZW"}) << endl;
    // "ZMNAGUEDSJYLBOPHRQICWFXTVK"
    cout << rankTeams({"ZMNAGUEDSJYLBOPHRQICWFXTVK"}) << endl;

    return 0;
}
