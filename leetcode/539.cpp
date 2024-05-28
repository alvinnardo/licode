#include "../template/head.h"
#include <bits/stdc++.h>

int findMinDifference(vector<string> timePoints) {
    // 思路：转换后排序，再求最小差距
    // 时间 O(nlogn)，空间 O(n)
    int sz = timePoints.size();
    vector<int> vec(sz);

    auto getInt = [](const std::string &str) {
        return ((int)(str[0] - '0') * 10 + (int)(str[1] - '0')) * 60 +
               ((int)(str[3] - '0') * 10 + (int)(str[4] - '0'));
    };

    for (int i = 0; i < sz; i++) {
        vec.push_back(getInt(timePoints[i]));
    }
    sort(vec.begin(), vec.end(), greater<int>());

    int res = INT_MAX;
    for (int i = 0; i < sz - 1; i++) {
        res = min(res, vec[i] - vec[i + 1]);
    }

    // 最后一个是循环的
    return min(res, 1440 + vec[sz - 1] - vec[0]);
}

int main(int argc, char *argv[]) {

    // 1
    cout << findMinDifference({"23:59", "00:00"}) << endl;
    // 2
    cout << findMinDifference({"22:00", "00:00"}) << endl;
    // 0
    cout << findMinDifference({"00:00", "23:59", "00:00"}) << endl;
    // 120
    cout << findMinDifference({"00:00", "04:00", "22:00"}) << endl;

    return 0;
}
