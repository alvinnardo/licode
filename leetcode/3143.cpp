#include "../template/head.h"
#include <bits/stdc++.h>

int maxPointsInsideSquare(vector<vector<int>> points, string s) {
    // 思路：模拟
    // 时间 O(nlogn)，空间 O(n)
    // 每个点可以映射到第一象限，然后取大值
    vector<pair<int, int>> vec;
    int sz = points.size();
    for (int i = 0; i < sz; i++) {
        vec.emplace_back(max(abs(points[i][0]), abs(points[i][1])), s[i]);
    }

    sort(vec.begin(), vec.end());

    int last_first = -1, cnt = 0, sum = 0;
    unordered_set<int> uset;
    for (auto &t : vec) {
        if (t.first != last_first) {
            cnt = 1;
            last_first = t.first;
        } else {
            cnt++;
        }

        sum++;
        if (uset.count(t.second)) {
            sum -= cnt;
            break;
        } else {
            uset.insert(t.second);
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {

    // 2
    cout << maxPointsInsideSquare({{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}},
                                  "abdca")
         << endl;
    // 1
    cout << maxPointsInsideSquare({{1, 1}, {-2, -2}, {-2, 2}}, "abb") << endl;
    // 0
    cout << maxPointsInsideSquare({{1, 1}, {-1, -1}, {2, -2}}, "ccd") << endl;

    return 0;
}
