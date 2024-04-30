#include "../template/head.h"
#include <bits/stdc++.h>
int eraseOverlapIntervals(vector<vector<int>> intervals) {
    // 测试优化：不使用 map，会不会快一些
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });

    int cnt = 1, sz = intervals.size();
    int bng = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < sz; i++) {
        if (intervals[i][0] == intervals[i - 1][0]) {
            continue;
        }

        auto &t = intervals[i];
        if (t[0] >= end) {
            cnt++;
            bng = t[0];
            end = t[1];
        } else if (t[1] <= end) {
            bng = t[0];
            end = t[1];
        }
    }

    return sz - cnt;
}

int eraseOverlapIntervals1(vector<vector<int>> intervals) {
    // 思路：求无重叠区间最大个数，然后用总数减去该个数，就是去掉的最少个数
    // 贪心, 区间起点从小到大，区间越小越好
    map<int, int> mm;
    for (auto &inter : intervals) {
        if (mm.find(inter[0]) == mm.end()) {
            mm[inter[0]] = inter[1];
        } else {
            mm[inter[0]] = min(mm[inter[0]], inter[1]);
        }
    }

    int cnt = 0, bng = -1, end = -1;
    for (auto it : mm) {
        if (!cnt || it.first >= end) {
            cnt++;
            bng = it.first;
            end = it.second;
        } else if (it.second <= end) {
            bng = it.first;
            end = it.second;
        }
    }

    return intervals.size() - cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) << endl;
    // 2
    cout << eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) << endl;
    // 0
    cout << eraseOverlapIntervals({{1, 2}, {2, 3}}) << endl;

    return 0;
}
