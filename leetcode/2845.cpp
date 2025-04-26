#include "../template/head.h"
#include <bits/stdc++.h>

long long countInterestingSubarrays(vector<int> nums, int modulo, int k) {
    // 思路：前缀和
    // 时间 O(n + k)，空间 O(n + k)，k 是符合条件的最大个数

    long long res = 0;
    int sz = nums.size();
    int cnt = 0;
    vector<int> times{0}, time_value;
    for (int i = 0; i < sz; i++) {
        if (nums[i] % modulo == k) {
            cnt++;
        }

        if (cnt % modulo == k) {
            res++;
            if (time_value.empty() || time_value.back() != cnt) {
                time_value.push_back(cnt);
            }
        }

        if (times.size() == cnt) {
            times.push_back(times.back());
        } else {
            if (k == 0) {
                res += times[cnt] - times[cnt - 1];
            }
        }

        times[cnt]++;
    }

    if (k != 0) {
        for (int i = 0; i < time_value.size(); i++) {
            res += times[cnt - time_value[i]];
        }
    }

    return res;
}

// 超时，感觉也会超时
long long countInterestingSubarrays_runtime(vector<int> nums, int modulo,
                                            int k) {
    // 思路：哈希表

    int sz = nums.size();

    unordered_map<int, int> umap;
    vector<int> vec;
    int cnt = 0;
    long long res = 0;

    if (k == 0) {
        vec.push_back(0);
    }

    for (int i = 0; i < sz; i++) {
        if (nums[i] % modulo == k) {
            cnt++;
        }

        if (cnt % modulo == k) {
            res++;

            if (vec.empty() || vec.back() != cnt) {
                vec.push_back(cnt);
            }
        }

        for (int j = 0; j < vec.size(); j++) {
            res += umap[cnt - vec[j]];
        }

        umap[cnt]++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // // 3
    // cout << countInterestingSubarrays({3, 2, 4}, 2, 1) << endl;
    // // 2
    // cout << countInterestingSubarrays({3, 1, 9, 6}, 3, 0) << endl;
    // // 2
    // cout << countInterestingSubarrays({5, 1}, 6, 1) << endl;
    // // 4
    // cout << countInterestingSubarrays({5, 4, 5}, 4, 1) << endl;
    // 6
    cout << countInterestingSubarrays({4, 5, 4, 5}, 4, 1) << endl;

    return 0;
}
