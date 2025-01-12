#include "../template/head.h"
#include <bits/stdc++.h>
int largestCombination(vector<int> candidates) {
    // 优化：交换遍历顺序，不用保存历史
    // 时间 O(nk)，空间 O(1)

    int res = 0;
    int tmp = 1;
    for (int i = 0; i < 25; i++) {
        int cnt = 0;
        for (int v : candidates) {
            if (v & tmp) {
                cnt++;
            }
        }

        tmp <<= 1;
        res = max(res, cnt);
    }

    return res;
}

int largestCombination1(vector<int> candidates) {
    // 刚开始读错题了，看成找子数组了，想了半天如何去掉与的那个数
    // 重看了一遍题，发现只需要组合
    // 思路：统计
    // 每一位都是或的关系，则取最大的即可
    // 时间 O(nk)，空间 O(k)，k 为 25
    // 因为数字最大是 1e7，25 位即可
    vector<int> cnt(25);
    for (int v : candidates) {
        int tmp = 1;
        for (int i = 0; i < 25; i++) {
            if (v & (tmp << i)) {
                cnt[i]++;
            }
        }
    }

    return *max_element(cnt.begin(), cnt.end());
}

int main(int argc, char *argv[]) {
    // 4
    cout << largestCombination({16, 17, 71, 62, 12, 24, 14}) << endl;
    // 2
    cout << largestCombination({8, 8}) << endl;
    // 2
    cout << largestCombination({68, 80, 59, 4, 40}) << endl;

    return 0;
}
