#include "../template/head.h"
#include <bits/stdc++.h>

int maxFreeTime(int eventTime, int k, vector<int> &&startTime,
                vector<int> &&endTime) {
    // 思路：滑动窗口
    // 时间 O(n)，空间 O(1)
    // 移动相邻的 k 个块，获取这几个块所有左右的空间
    int maxv = INT_MIN;

    int tmp = startTime[0];
    for (int i = 0; i < startTime.size(); i++) {
        if (i >= k) {
            int pre = i - k;
            tmp -=
                pre == 0 ? startTime[pre] : startTime[pre] - endTime[pre - 1];
        }
        tmp += i == startTime.size() - 1 ? eventTime - endTime[i]
                                         : startTime[i + 1] - endTime[i];
        maxv = max(maxv, tmp);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxFreeTime(5, 1, {1, 3}, {2, 5}) << endl;
    // 6
    cout << maxFreeTime(10, 1, {0, 2, 9}, {1, 4, 10}) << endl;
    // 0
    cout << maxFreeTime(5, 2, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}) << endl;

    return 0;
}
