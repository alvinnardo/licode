#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> changed) {

    // 思路：依次找出最小的值，并将它的 2 倍删除，如果最后为空，则成立
    // 如果没有 2 倍，则不成立
    if (changed.size() & 1) { // 奇数个不成立
        return {};
    }

    map<int, int> mm;
    for (auto &num : changed) {
        mm[num]++;
    }

    vector<int> res;
    for (auto it = mm.begin(); it != mm.end();) {
        if (it->second == 0) {
            it++;
            continue;
        }

        int val = it->first << 1;
        if (val == 0 && mm[val] < 2) { // 0 的 倍数还是 0
            return {};
        }

        if (mm.find(val) == mm.end() || mm[val] == 0) {
            return {};
        }

        res.push_back(it->first);
        it->second--;
        mm[val]--;
    }
    return res;
}

int main(void) {
    // [1, 3, 4]
    printVector(findOriginalArray({1, 3, 4, 2, 6, 8}));
    // []
    printVector(findOriginalArray({6, 3, 0, 1}));
    // []
    printVector(findOriginalArray({1}));
    printVector(findOriginalArray({1, 1, 2, 2, 3, 3, 6, 6}));
    printVector(findOriginalArray({0, 0, 0, 0, 3, 3, 6, 6}));

    return 0;
}
