#include "../template/head.h"
#include <bits/stdc++.h>

int busyStudent(vector<int> startTime, vector<int> endTime, int queryTime) {
    // 思路：差分数组
    // 时间 O(n + k)，空间 O(k)，k 为 endTime 中最大值
    int maxv = *max_element(endTime.begin(), endTime.end());
    if (queryTime > maxv) {
        return 0;
    }

    vector<int> vec(maxv + 2);
    for (int i = 0; i < startTime.size(); i++) {
        vec[startTime[i]]++;
        vec[endTime[i] + 1]--;
    }

    for (int i = 1; i < vec.size(); i++) {
        vec[i] += vec[i - 1];
    }

    return vec[queryTime];
}

int main(int argc, char *argv[]) {
    // 1
    cout << busyStudent({4}, {4}, 4) << endl;
    // 0
    cout << busyStudent({4}, {4}, 5) << endl;
    // 0
    cout << busyStudent({1, 1, 1, 1}, {1, 3, 2, 4}, 7) << endl;
    // 5
    cout << busyStudent({9, 8, 7, 6, 5, 4, 3, 2, 1},
                        {10, 10, 10, 10, 10, 10, 10, 10, 10}, 5)
         << endl;

    return 0;
}
