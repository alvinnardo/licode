#include "../template/head.h"
#include <bits/stdc++.h>

bool isNStraightHand(vector<int> hand, int groupSize) {
    // 思路：红黑树
    // 时间 O(nlogn)，最差空间 O(n)
    // 需要找最小值，所以有排序的需求；又要快速定位，有快速查找的需求
    map<int, int> mm;
    for (int num : hand) { // 先统计
        mm[num]++;
    }

    while (!mm.empty()) {
        int t = mm.begin()->first;            // 拿最小值
        for (int i = 0; i < groupSize; i++) { // 按顺序拿牌
            int num = t + i;
            if (!mm.count(num)) { // 没有这张牌，返回失败
                return false;
            } else {
                if (--mm[num] == 0) { // 有这张牌，删除这张牌
                    mm.erase(num);
                }
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // true
    cout << isNStraightHand({1, 2, 3, 6, 2, 3, 4, 7, 8}, 3) << endl;
    // false
    cout << isNStraightHand({1, 2, 3, 4, 5}, 4) << endl;

    return 0;
}
