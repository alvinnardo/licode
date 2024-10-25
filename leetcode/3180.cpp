#include "../template/head.h"
#include <bits/stdc++.h>

int maxTotalReward(vector<int> rewardValues) {
    // 思路：暴力 + 红黑树
    // 时间 O(n2logn)，空间 O(n2)
    sort(rewardValues.begin(), rewardValues.end());
    set<int> ss;
    vector<int> vec;
    for (int i = 0; i < rewardValues.size(); i++) {
        vec.clear();
        vec.emplace_back(rewardValues[i]);
        for (int t : ss) {
            if (t >= rewardValues[i]) {
                break;
            }

            vec.push_back(t + rewardValues[i]);
        }

        for (auto t : vec) {
            ss.insert(t);
        }
    }

    return *ss.rbegin();
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxTotalReward({1, 1, 3, 3}) << endl;
    // 11
    cout << maxTotalReward({1, 6, 4, 3, 2}) << endl;

    return 0;
}
