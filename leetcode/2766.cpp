#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> relocateMarbles(vector<int> nums, vector<int> moveFrom,
                            vector<int> moveTo) {
    // 思路：模拟 + 哈希表
    // 时间 O(mlogm + n)，空间 O(m)
    unordered_set<int> uset(nums.begin(), nums.end());
    for (int i = 0; i < moveFrom.size(); i++) {
        if (uset.count(moveFrom[i])) {
            uset.erase(moveFrom[i]);
            uset.insert(moveTo[i]);
        }
    }

    vector<int> res(uset.begin(), uset.end());
    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[]) {
    // {5,6,8,9}
    printVector(relocateMarbles({1, 6, 7, 8}, {1, 7, 2}, {2, 9, 5}));
    // {2}
    printVector(relocateMarbles({1, 1, 3, 3}, {1, 3}, {2, 2}));

    return 0;
}
