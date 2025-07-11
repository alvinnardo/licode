#include "../template/head.h"
#include <bits/stdc++.h>

// 看题解是被归类了单独的一种算法：区间合并
int countDays(int days, vector<vector<int>> &&meetings) {
    // 思路：排序
    // 时间 O(nlogn)，空间 O(1)
    // 会出现类似 [[1, 10], [2, 5]] 的情况
    sort(meetings.begin(), meetings.end());
    int cnt = meetings[0][0] - 1;
    int bng = INT_MIN, end = INT_MIN;
    for (int i = 0; i < meetings.size(); i++) {
        if (i == 0) {
            bng = meetings[i][0];
            end = meetings[i][1];
            continue;
        }

        if (meetings[i][0] <= end) {
            if (meetings[i][1] > end) {
                end = meetings[i][1];
            }
        } else {
            // 两次会议之间的距离
            cnt += meetings[i][0] - end - 1;
            bng = meetings[i][0];
            end = meetings[i][1];
        }
    }

    if (end < days) {
        cnt += days - end; // 最后剩下的空闲
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countDays(10, {{5, 7}, {1, 3}, {9, 10}}) << endl;
    // 1
    cout << countDays(5, {{2, 4}, {1, 3}}) << endl;
    // 0
    cout << countDays(6, {{1, 6}}) << endl;
    // 0
    cout << countDays(10, {{1, 10}, {2, 5}}) << endl;

    return 0;
}
