#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> findWinners(vector<vector<int>> matches) {
    // 思路：模拟
    // 时间 O(n + k), k 为红黑树中值的个数
    // 空间 O(n)
    map<int, int> mm;
    for (auto &match : matches) {
        if (mm.find(match[0]) == mm.end()) {
            mm[match[0]] = 0;
        }
        mm[match[1]]++;
    }

    vector<int> zero, one;
    for (auto &it : mm) {
        if (it.second == 0) {
            zero.push_back(it.first);
        } else if (it.second == 1) {
            one.push_back(it.first);
        }
    }

    return {zero, one};
}

int main(int argc, char *argv[]) {
    // {{1,2,10},{4,5,7,8}}
    printVectorVector(findWinners({{1, 3},
                                   {2, 3},
                                   {3, 6},
                                   {5, 6},
                                   {5, 7},
                                   {4, 5},
                                   {4, 8},
                                   {4, 9},
                                   {10, 4},
                                   {10, 9}}));
    // {{1,2,5,6},{}}
    printVectorVector(findWinners({{2, 3}, {1, 3}, {5, 4}, {6, 4}}));

    return 0;
}
