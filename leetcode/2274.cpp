#include "../template/head.h"
#include <bits/stdc++.h>

int maxConsecutive(int bottom, int top, vector<int> special) {
    // 思路：排序 + 模拟
    // 时间 O(nlogn)，空间 O(logn)

    sort(special.begin(), special.end());
    int maxv = 0;
    for (int i = 1; i < special.size(); i++) {
        maxv = max(maxv, special[i] - special[i - 1] - 1);
    }

    return max(maxv, max(special[0] - bottom, top - special.back()));
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxConsecutive(2, 9, {4, 6}) << endl;
    // 0
    cout << maxConsecutive(6, 8, {7, 6, 8}) << endl;

    return 0;
}
