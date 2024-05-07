#include "../template/head.h"
#include <bits/stdc++.h>

int findMinArrowShots(vector<vector<int>> points) {

    // 思路：先排序，然后遍历，以右边界为界限缩减区间
    // 时间 O(nlogn)，空间 O(logn)
    sort(points.begin(), points.end(),
         [](const vector<int> &a, const vector<int> &b) {
             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });

    int sz = points.size();
    int right = -1, cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (right == -1 || points[i][0] > right) {
            cnt++;
            right = points[i][1];
        } else {
            right = min(points[i][1], right);
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findMinArrowShots({{10, 16}, {2, 8}, {1, 6}, {7, 12}}) << endl;
    // 4
    cout << findMinArrowShots({{1, 2}, {3, 4}, {5, 6}, {7, 8}}) << endl;
    // 2
    cout << findMinArrowShots({{1, 2}, {2, 3}, {3, 4}, {4, 5}}) << endl;

    return 0;
}
