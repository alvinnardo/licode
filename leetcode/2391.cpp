#include "../template/head.h"
#include <bits/stdc++.h>

int garbageCollection(vector<string> garbage, vector<int> travel) {
    // 思路：前缀和，统计字符即处理时间
    // 主要是要找到没有该字符的位置，然后用总时间 - 没有字符的时间
    // 时间 O(2n + m)，n 是 数组长度，m 是字符串最大长度；空间 O(1)
    int sz = garbage.size();
    for (int i = 1; i < sz - 1; i++) {
        travel[i] += travel[i - 1];
    }

    int pos[]{0, 0, 0}, cnt[]{0, 0, 0};
    unordered_map<char, int> mm{{'G', 0}, {'P', 1}, {'M', 2}};

    for (int i = 0; i < sz; i++) {
        for (auto c : garbage[i]) {
            pos[mm[c]] = i;
            cnt[mm[c]]++;
        }
    }

    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (pos[i] != 0) {
            res += travel[pos[i] - 1];
        }
        res += cnt[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 21
    cout << garbageCollection({"G", "P", "GP", "GG"}, {2, 4, 3}) << endl;
    // 37
    cout << garbageCollection({"MMM", "PGM", "GP"}, {3, 10}) << endl;

    return 0;
}
