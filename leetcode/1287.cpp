#include "../template/head.h"
#include <bits/stdc++.h>

int findSpecialInteger(vector<int> arr) {
    // 思路：模拟 + 统计
    // 因为是有序的，则不需要哈希表
    // 时间 O(n)，空间 O(1)
    int cnt = 0, pre = -1, yu = (arr.size() >> 2);
    for (int a : arr) {
        if (a != pre) {
            pre = a;
            cnt = 1;
        } else {
            cnt++;
        }

        if (cnt > yu) {
            return pre;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // 6
    cout << findSpecialInteger({1, 2, 2, 6, 6, 6, 6, 7, 10}) << endl;

    return 0;
}
