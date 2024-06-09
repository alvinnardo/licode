#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    // 思路：二分 + 双指针
    // 时间 O(logn + k + klogk)，空间 O(1)
    vector<int> res;
    int sz = arr.size();
    auto pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int l = pos - 1, r = pos;
    while (res.size() < k) {
        int l_diff = INT_MAX, r_diff = INT_MAX;
        if (l >= 0) {
            l_diff = abs(arr[l] - x);
        }
        if (r < sz) {
            r_diff = abs(arr[r] - x);
        }

        if (l_diff <= r_diff) {
            res.push_back(arr[l--]);
        } else {
            res.push_back(arr[r++]);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[]) {
    // {1,2,3,4}
    printVector(findClosestElements({1, 2, 3, 4, 5}, 4, 3));
    // {1,2,3,4}
    printVector(findClosestElements({1, 2, 3, 4, 5}, 4, -1));

    return 0;
}
