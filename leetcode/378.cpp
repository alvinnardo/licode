#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;
int kthSmallest(vector<vector<int>> matrix, int k) {
    // 二分排序
    // 锯齿型的中间分界线

    int sz = matrix.size();
    int tot = sz * sz;
    int l = matrix[0][0], r = matrix[sz - 1][sz - 1];

    auto getNum = [&](int n) {
        // 找到矩阵中小于等于 n 的个数
        int num = 0;
        int i = sz - 1, j = 0;

        while (i >= 0 && j < sz) {
            if (matrix[i][j] <= n) {
                j++;
            } else {
                num += sz - j; // 找严格大的
                i--;
            }
        }

        return tot - num;
    };

    while (l <= r) { // 有值
        int mid = l + ((r - l) >> 1);
        int num = getNum(mid);

        if (num < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int kthSmallest_heap(vector<vector<int>> matrix, int k) {
    // k 个有序数组归并排序
    // 用优先队列维护头元素
    // 时间：O(nlogn)
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
        return matrix[a.first][a.second] > matrix[b.first][b.second];
    };

    int sz = matrix.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < sz; i++) {
        pq.emplace(i, 0);
    }

    pair<int, int> t;
    while (k--) {
        t = pq.top();
        pq.pop();
        if (t.second + 1 < sz) {
            pq.emplace(t.first, t.second + 1);
        }
    }

    return matrix[t.first][t.second];
}

int kthSmallest_my(vector<vector<int>> matrix, int k) {
    // 想不出来了，拿 O(n2) 做吧
    // 时间复杂度：O(n2logn), 对 n2 做排序
    vector<int> vec;
    int sz = matrix.size();
    for (auto &m : matrix) {
        for (auto &n : m) {
            vec.push_back(n);
        }
    }
    sort(vec.begin(), vec.end());

    return vec[k - 1];
}

int main(void) {
    cout << kthSmallest({{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8) << endl;
    cout << kthSmallest({{-5}}, 1) << endl;

    return 0;
}
