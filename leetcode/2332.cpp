#include "../template/head.h"
#include <bits/stdc++.h>

int latestTimeCatchTheBus(vector<int> buses, vector<int> passengers,
                          int capacity) {
    // 思路：贪心 + 模拟
    // 别人能上，我也能上，判断如果我是前一个时刻来的能否上车
    // 模拟容量用来判断人数多了，但是车少的情况
    // 从 2 开始，所以 1 是保守结果
    // 时间 O(mlogm + nlogn)，空间 O(logm + logn)
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int i = 0, j = 0;
    int cnt = 0, m = buses.size(), n = passengers.size();
    int res = -1;
    while (i < m && j < n) {
        if (buses[i] >= passengers[j]) { // 能上车
            if (j == 0 || passengers[j] - 1 != passengers[j - 1]) {
                res = passengers[j] - 1; // 在前一时刻抢这个乘客的位置
            }

            cnt++;
            j++;
            // 装满了，或最后一个乘客踩点上车，可以发车
            if (cnt == capacity || passengers[j - 1] == buses[i] && j == n) {
                cnt = 0;
                i++;
            }

        } else { // 时间到了，可以发车
            // 上不了车，肯定没装满，我在时间到的时候上车
            if (j == 0 || passengers[j - 1] != buses[i]) {
                res = buses[i];
            }
            cnt = 0;
            i++;
        }
    }

    // 没乘客了，但是有车
    if (i < m) {
        res = buses.back();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 16
    cout << latestTimeCatchTheBus({10, 20}, {2, 17, 18, 19}, 2) << endl;
    // 20
    cout << latestTimeCatchTheBus({20, 30, 10}, {19, 13, 26, 4, 25, 11, 21}, 2)
         << endl;
    // 1
    cout << latestTimeCatchTheBus({2, 4}, {2, 3, 4}, 2) << endl;
    // 3
    cout << latestTimeCatchTheBus({2, 4}, {2, 4}, 2) << endl;
    // 4
    cout << latestTimeCatchTheBus({2, 4}, {2, 3}, 2) << endl;

    // 100
    cout << latestTimeCatchTheBus({50, 88, 2,  44, 93, 69, 12, 6,  46,  68,
                                   52, 40, 34, 97, 49, 21, 13, 56, 31,  94,
                                   89, 14, 22, 79, 72, 8,  32, 67, 100, 78},
                                  {4, 50, 56}, 4)
         << endl;

    return 0;
}
