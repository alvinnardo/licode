#include "../template/head.h"
#include <bits/stdc++.h>

int maxFrequency(vector<int> &&nums, int k, int numOperations) {
    // 思路：差分
    // 时间：O(n)，空间 O(n)

    int sz = nums.size();
    int a{};
    int maxv = std::ranges::max(nums);
    vector<int> vec(maxv + 1);
    vector<int> umap(maxv + 1);
    auto addVec = [&](int num) {
        while (vec.size() <= num) {
            vec.push_back(0);
        }
    };
    for (int i = 0; i < sz; i++) {
        umap[nums[i]]++;
        a = nums[i] - k;
        if (a < 0) {
            vec[0]++;
        } else {
            vec[a]++;
        }

        a = nums[i] + k + 1;
        if (a <= maxv) {
            vec[a]--;
        }
    }

    int res{};
    for (int i = 1; i < vec.size(); i++) {
        vec[i] += vec[i - 1];

        // 操作数和可操作数的最小值 + 原本值的个数
        res = max(res, min(vec[i] - umap[i], numOperations) + umap[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxFrequency({1, 4, 5}, 1, 2) << endl;
    // 2
    cout << maxFrequency({5, 11, 20, 20}, 5, 1) << endl;

    return 0;
}
