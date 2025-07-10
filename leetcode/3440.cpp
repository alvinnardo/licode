#include "../template/head.h"
#include <bits/stdc++.h>

int maxFreeTime(int eventTime, vector<int> &&startTime, vector<int> &&endTime) {
    // 思路：贪心 + 分类讨论
    // 时间 O(n)，空间 O(1)
    int sz = startTime.size();
    // 使用 vector 再排序耗费更多的空间
    // 其实只需要最大的三个值和空闲空间的数量即可
    int first = startTime[0], second = INT_MIN, third = INT_MIN;
    int t = 0;
    for (int i = 0; i < sz; i++) {

        t = i == sz - 1 ? eventTime - endTime[i]
                        : startTime[i + 1] - endTime[i];

        if (t >= first) {
            third = second;
            second = first;
            first = t;
        } else if (t >= second) {
            third = second;
            second = t;
        } else if (t >= third) {
            third = t;
        }
    }

    int maxv = INT_MIN;
    int pre = 0, next = 0, dur = 0;
    for (int i = 0; i < sz; i++) {
        pre = i == 0 ? startTime[i] : startTime[i] - endTime[i - 1];
        next = i == sz - 1 ? eventTime - endTime[i]
                           : startTime[i + 1] - endTime[i];
        if (pre < next) { // 保证 pre >= next
            swap(pre, next);
        }

        dur = endTime[i] - startTime[i];

        // 分类讨论
        int tmp = 0; // 判断去掉左右两边空闲后还是否有更大的空闲
        if (first > pre) {
            tmp = first;
        } else if (second > next) {
            tmp = second;
        } else if (sz + 1 > 2) {
            tmp = third;
        } else {
            tmp = 0;
        }

        maxv = max(maxv, tmp >= dur ? pre + next + dur : pre + next);
    }

    return maxv;
}

int maxFreeTime1(int eventTime, vector<int> &&startTime,
                 vector<int> &&endTime) {
    // 思路：贪心 + 红黑树
    // 时间 O(mlogm)，空间 O(m)
    map<int, int> mm;
    int sz = startTime.size();

    // 先保存所有的空闲区间
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            mm[startTime[i]]++;
        }
        if (i == sz - 1) {
            mm[eventTime - endTime[i]]++;
        } else {
            mm[startTime[i + 1] - endTime[i]]++;
        }
    }

    int maxv = INT_MIN;
    for (int i = 0; i < sz; i++) {

        int pre = i == 0 ? startTime[i] : startTime[i] - endTime[i - 1];
        int next = i == sz - 1 ? eventTime - endTime[i]
                               : startTime[i + 1] - endTime[i];

        // 先去掉本次会议的左右空闲区间，
        // 检查其它空闲区间能否满足
        if (--mm[pre] == 0) {
            mm.erase(pre);
        }
        if (--mm[next] == 0) {
            mm.erase(next);
        }

        int dur = endTime[i] - startTime[i];
        if (!mm.empty() && mm.crbegin()->first >= dur) {
            maxv = max(maxv, pre + next + dur);
        } else {
            maxv = max(maxv, pre + next);
        }

        // 检查结束后再将删去的添加回来
        mm[pre]++;
        mm[next]++;
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxFreeTime(5, {1, 3}, {2, 5}) << endl;
    // 7
    cout << maxFreeTime(10, {0, 7, 9}, {1, 8, 10}) << endl;
    // 6
    cout << maxFreeTime(10, {0, 3, 7, 9}, {1, 4, 8, 10}) << endl;
    // 0
    cout << maxFreeTime(5, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}) << endl;

    return 0;
}
