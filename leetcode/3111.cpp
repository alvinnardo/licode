#include "../template/head.h"
#include <bits/stdc++.h>

int minRectanglesToCoverPoints(vector<vector<int>> points, int w) {
    // 思路：贪心
    // 时间 O(nlogn)，空间 O(1)
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    int sz = points.size();
    int cnt = 0, bng = -1, end = -1;

    for (auto &p : points) {
        if (p[0] > end) {
            bng = p[0];
            end = bng + w;
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minRectanglesToCoverPoints(
                {{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}}, 1)
         << endl;
    // 3
    cout << minRectanglesToCoverPoints(
                {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}}, 2)
         << endl;
    // 2
    cout << minRectanglesToCoverPoints({{2, 3}, {1, 2}}, 0) << endl;

    return 0;
}
