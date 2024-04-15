#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2];
    }
};

vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2,
                                   int k) {
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
        return nums1[a.first] + nums2[b.first] - nums1[a.first] -
                   nums2[b.first] >
               0;
    };
    // 优化
    // 思路：优先队列，存放位置和当前和，每次取最小值
    vector<vector<int>> res;

    int sz1 = nums1.size(), sz2 = nums2.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < sz2; i++) {
        pq.emplace(0, i);
    }

    while (res.size() < k) {
        auto t = pq.top();
        pq.pop();
        res.push_back({nums1[t.first], nums2[t.second]});

        // fresh
        t.first++;
        if (t.first < sz1) {
            pq.push({t.first, t.second});
        }
    }

    return res;
}
vector<vector<int>> kSmallestPairs_ori(vector<int> nums1, vector<int> nums2,
                                       int k) {
    // 思路：优先队列，存放位置和当前和，每次取最小值
    vector<vector<int>> res;

    int sz1 = nums1.size(), sz2 = nums2.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    for (int i = 0; i < sz2; i++) {
        pq.push({0, i, nums1[0] + nums2[i]});
    }

    while (res.size() < k) {
        auto t = pq.top();
        pq.pop();
        res.push_back({nums1[t[0]], nums2[t[1]]});

        // fresh
        t[0]++;
        if (t[0] < sz1) {
            pq.push({t[0], t[1], nums1[t[0]] + nums2[t[1]]});
        }
    }

    return res;
}

int main(void) {
    printVectorVector(kSmallestPairs({1, 7, 11}, {2, 4, 6}, 9));
    printVectorVector(kSmallestPairs({1, 1, 2}, {1, 1, 3}, 9));
    printVectorVector(kSmallestPairs({1, 1, 2, 5, 11}, {1, 1, 3}, 15));

    return 0;
}
