#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> successfulPairs(vector<int> &&spells, vector<int> &&potions,
                            long long success) {
    // 思路：排序 + 二分
    // 时间 O(nlogm)，空间 O(1)
    std::ranges::sort(potions);

    int n = spells.size(), m = potions.size();
    long long tmp{};
    vector<int> res;
    for (int i = 0; i < n; i++) {
        tmp = spells[i];

        // 大于等于
        auto pos =
            std::lower_bound(potions.begin(), potions.end(), success,
                             [&](int a, long long b) { return tmp * a < b; });
        res.push_back(potions.end() - pos);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {4,0,3}
    cout << successfulPairs({5, 1, 3}, {1, 2, 3, 4, 5}, 7) << endl;
    // {2,0,2}
    cout << successfulPairs({3, 1, 2}, {8, 5, 8}, 16) << endl;

    return 0;
}
