#include "../template/head.h"
#include <bits/stdc++.h>

int minimumRefill(vector<int> plants, int capacityA, int capacityB) {

    // 思路：模拟，遍历数组的一半，最后判断奇数
    // 时间 O(n)，空间 O(1)
    int sz = plants.size();
    int half_sz = sz >> 1, cnt = 0;
    int ta = capacityA, tb = capacityB;
    for (int i = 0; i < half_sz; i++) {
        int apos = i, bpos = sz - i - 1;
        if (ta >= plants[apos]) {
            ta -= plants[apos];
        } else {
            cnt++; // 加水
            ta = capacityA - plants[apos];
        }

        if (tb >= plants[bpos]) {
            tb -= plants[bpos];
        } else {
            cnt++; // 加水
            tb = capacityB - plants[bpos];
        }
    }

    // 处理中间的植物
    if (sz & 1 && max(ta, tb) < plants[half_sz]) {
        cnt++;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumRefill({2, 2, 3, 3}, 5, 5) << endl;
    // 2
    cout << minimumRefill({2, 2, 3, 3}, 3, 4) << endl;
    // 0
    cout << minimumRefill({5}, 10, 8) << endl;

    return 0;
}
