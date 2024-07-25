#include "../template/head.h"
#include <bits/stdc++.h>

int maximumDetonation(vector<vector<int>> bombs) {
    // 思路：BFS
    // 注意是爆炸范围和炸弹之间的比较
    // 一个炸弹爆炸，可以同时引爆多个炸弹
    // 时间 O(n2)，空间 O(n2)
    int sz = bombs.size();
    vector<vector<int>> vec(sz);

    auto can = [&](int i, int j) -> pair<bool, bool> {
        long long x = bombs[i][0] - bombs[j][0];
        long long y = bombs[i][1] - bombs[j][1];
        long long r1 = bombs[i][2], r2 = bombs[j][2];
        long long d = x * x + y * y;
        r1 = r1 * r1;
        r2 = r2 * r2;

        return {r1 >= d, r2 >= d};
    };

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            auto t = can(i, j);
            if (t.first) {
                vec[i].push_back(j);
            }
            if (t.second) {
                vec[j].push_back(i);
            }
        }
    }

    int res = INT_MIN;
    for (int i = 0; i < sz; i++) {
        unordered_set<int> uset;
        queue<int> qu;
        qu.push(i);

        while (!qu.empty()) {
            int t = qu.front();
            qu.pop();
            if (uset.count(t)) {
                continue;
            }

            uset.insert(t);
            for (int j : vec[t]) {
                qu.push(j);
            }
        }

        res = max(res, (int)uset.size());
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maximumDetonation({{2, 1, 3}, {6, 1, 4}}) << endl;
    // 1
    cout << maximumDetonation({{1, 1, 5}, {10, 10, 5}}) << endl;
    // 5
    cout << maximumDetonation(
                {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}})
         << endl;

    return 0;
}
