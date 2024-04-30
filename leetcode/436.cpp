#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> findRightInterval(vector<vector<int>> intervals) {
    // 思路：二分查找
    // 因为 start 都是不同的，所以可以保存 start 和 index 的对应关系
    // 时间 O(nlogn), 空间 O(n)
    // 优化: 不需要用哈希表
    int sz = intervals.size();
    vector<pair<int, int>> start_vec;
    for (int i = 0; i < sz; i++) {
        auto &inter = intervals[i];
        start_vec.emplace_back(inter[0], i);
    }

    sort(start_vec.begin(), start_vec.end());

    vector<int> res;
    for (int i = 0; i < sz; i++) {
        if (intervals[i][0] == intervals[i][1]) {
            // 这里也可以不用判断相等，直接查也行
            // 判断可以减少一次查询次数
            res.push_back(i);
        } else {
            auto it = lower_bound(start_vec.begin(), start_vec.end(),
                                  make_pair(intervals[i][1], 0));
            res.push_back(it == start_vec.end() ? -1 : it->second);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [-1]
    printVector(findRightInterval({{1, 2}}));
    // [0]
    printVector(findRightInterval({{4, 4}}));
    // [-1,0,1]
    printVector(findRightInterval({{3, 4}, {2, 3}, {1, 2}}));
    // [-1,2,-1]
    printVector(findRightInterval({{1, 4}, {2, 3}, {3, 4}}));

    return 0;
}
