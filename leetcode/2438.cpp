#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> productQueries(int n, vector<vector<int>> &&queries) {
    // 思路：位运算 + 哈希表
    // 时间 O(logn * logn + k)，空间 O(logn * logn)

    // 用前缀积会先取模，后面再除的话结果会出错
    // 因为位数不多，可以直接存下来
    vector<vector<int>> vvec;
    int t = 1;
    const int mod = 1e9 + 7;
    while (n) {
        if (n & 1) {
            for (int i = 0; i < vvec.size(); i++) {
                vvec[i].push_back(((long long)vvec[i].back() * t) % mod);
            }
            vvec.push_back({t});
        }
        n >>= 1;
        t <<= 1;
    }

    vector<int> res;
    for (const auto &query : queries) {
        res.push_back(vvec[query[0]][query[1] - query[0]]);
    }

    return res;
}

int main(int argc, char *argv[]) {

    // {2,4,64}
    cout << productQueries(15, {{0, 1}, {2, 2}, {0, 3}}) << endl;
    // {2}
    cout << productQueries(2, {{{0, 0}}}) << endl;

    return 0;
}
