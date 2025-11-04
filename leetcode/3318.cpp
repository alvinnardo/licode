#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findXSum(vector<int> &&nums, int k, int x) {
    // 思路：模拟
    // 时间 O(n2logn)，空间 O(n)
    // 简单题简单做
    vector<int> vec(51);
    int sz = nums.size();
    vector<pair<int, int>> vp;
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < sz; i++) {
        if (cnt < k) {
            vec[nums[i]]++;
            cnt++;
        } else {
            vec[nums[i]]++;
            vec[nums[i - k]]--;
        }

        if (cnt == k) {
            vp.clear();
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] != 0) {
                    vp.emplace_back(vec[i], i);
                }
            }

            sort(vp.begin(), vp.end(), std::greater<pair<int, int>>());
            int tmp{};
            for (int i = 0; i < vp.size(); i++) {
                if (i == x) {
                    break;
                }

                tmp += vp[i].first * vp[i].second;
            }

            res.push_back(tmp);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {6,10,12}
    cout << findXSum({1, 1, 2, 2, 3, 4, 2, 3}, 6, 2) << endl;
    // {11,15,15,15,12}
    cout << findXSum({3, 8, 7, 8, 7, 5}, 2, 2) << endl;

    return 0;
}
