#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    // 题解：贪心
    // 如果某一个加油站无法到达一个加油站，
    // 那么这两个中间的加油站都不能到达该加油站
    // 时间 O(n)，空间 O(1)
    int sum = 0, dur = -1, res = -1, t = 0;
    for (int i = 0; i < gas.size(); i++) {
        if (dur < 0) {
            dur = 0;
            res = i;
        }
        t = gas[i] - cost[i];
        dur += t;
        sum += t;
    }

    return sum < 0 ? -1 : res;
}

int canCompleteCircuit1(vector<int> gas, vector<int> cost) {
    if (gas.size() == 1) {
        return gas[0] - cost[0] < 0 ? -1 : 0;
    }
    // 如果不能向右走，就从左边借
    // 如果最后剩的不是赋值，就表示能够走完
    // 两边指向的位置都不拿
    int sum = 0, sz = gas.size();
    int left = sz - 1, right = 0;
    while (right <= left) {
        if (sum + gas[right] - cost[right] >= 0) {
            sum += gas[right] - cost[right];
            right++;
            if (right == sz) {
                right = 0;
                break; // 又回到 0 了，可以停止循环
            }

        } else {
            sum += gas[left] - cost[left];
            left--;
        }
    }
    return sum < 0 ? -1 : right;
}

int main(void) {
    cout << canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) << endl;
    cout << canCompleteCircuit({2, 3, 4}, {3, 4, 3}) << endl;
    cout << canCompleteCircuit({0}, {0}) << endl;
    cout << canCompleteCircuit({3, 1, 1}, {1, 2, 2}) << endl;

    return 0;
}
